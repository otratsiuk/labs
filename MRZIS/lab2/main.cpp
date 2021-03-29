#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <string>
#include <semaphore.h>
#include <iomanip>
#include <chrono>

std::vector<int> numbers;
std::vector<int> blockAverage;
std::vector<int> blockMin;
std::vector<int> blockMax;
int index = 0;
int generalAverage = 0;

sem_t semaphore1;
sem_t semaphore2;

void fromFileToVector(std::string &inputFileName,int blockSize){
    std::ifstream file(inputFileName);
    int i = 0;
    while(!file.eof()){
        int num;
        file >> num;
        numbers.push_back(num);
        i++;
        if(i%blockSize == 0){
            index = i;
            sem_post(&semaphore1);
        }
    }
}

void calculateValues(int blockSize){
    int i = 0;
    int blockSum = 0;
    int generalSum = 0;

    sem_wait(&semaphore1);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    int min = numbers[i];
    int max = numbers[i];

    do{
        if(min > numbers[i]){
            min = numbers[i];
        }
        if(max < numbers[i]){
            max = numbers[i];
        }
        blockSum += numbers[i++];
        if(i % blockSize == 0){
            blockMin.push_back(min);
            blockMax.push_back(max);
            blockAverage.push_back(blockSum/blockSize);
            generalAverage += blockSum;
            blockSum = 0;

            min = numbers[i];
            max = numbers[i];
            sem_post(&semaphore2);
        }
    }while(i < index);
}

void toFile(std::string &outputFileName, int blockSize){
    std::ofstream file(outputFileName);

    int i = 0;
    int block = 0;

    sem_wait(&semaphore2);

    while(i < index){
    file << std::setw(4)<<std::left<< numbers[i++] << " "; 
        if (i % 10 == 0){
        file << "\n";
        }
        if(i % blockSize == 0){
            file <<"index number = " << block<<"\nmin = "<< blockMin[block]<<"\nmax = "<<blockMax[block]<<"\nblock average = "<<blockAverage[block++] << "\n\n";
        }
    }
    file << "average = " << generalAverage/index <<"\n";
}

int main(){
    std::string inputFileName = "2.txt";
    std::string outputFileName = "output.txt";

    int blockSize;

    std::cout<<"enter block size(multiple of 10): ";
    std::cin>>blockSize;

    sem_init(&semaphore1, 1, 0);
    sem_init(&semaphore2, 1, 0);

    std::thread thread1(fromFileToVector, std::ref(inputFileName), blockSize);
    std::thread thread2(calculateValues, blockSize);
    std::thread thread3(toFile, std::ref(outputFileName), blockSize);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0 ;
}
