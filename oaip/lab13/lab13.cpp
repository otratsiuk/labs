#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
  char title[60];
  char authorName[40];
  unsigned int year : 32;
  char publisher[20];
  unsigned int cost : 32;
  unsigned int price : 32;
  unsigned int profit : 32;
};

void AddBook(vector<Book> &books) {
  Book book;
  int year;
  int cost;
  int price;
  int profit;
  cin.get();
  cout << "\nEnter title: ";
  cin.getline(book.title, 30);
  cout << "\nEnter author: ";
  cin.getline(book.authorName, 20);
  cout << "\nEnter year: ";
  cin >> year;
  book.year = year;
  cout << "\nEnter publisher: ";
  cin.get();
  cin.getline(book.publisher, 20);
  cout << "\nEnter cost: ";
  cin >> cost;
  book.cost = cost;
  cout << "\nEnter price: ";
  cin >> price;
  book.price = price;
  cout << "\nEnter profit: ";
  cin >> profit;
  book.profit = profit;
  books.push_back(book);
}

void DisplayBook(Book &book) {
  cout << "\ntitle:\t\t" << book.title << "\n";
  cout << "author:\t\t" << book.authorName << "\n";
  cout << "year:\t\t" << book.year << "\n";
  cout << "publisher:\t" << book.publisher << "\n";
  cout << "cost:\t\t" << book.cost << "\n";
  cout << "price:\t\t" << book.price << "\n";
  cout << "profit:\t\t" << book.profit << "\n\n";
}

void FromFileToVector(vector<Book> &books, string &fileName) {
  ifstream booksFile(fileName, ios ::out);
  Book tempBook;
  books.clear();
  booksFile.seekg(0, ios::beg);
  while (booksFile.read((char *)&tempBook, sizeof(Book))) {
    books.push_back(tempBook);
  }
  booksFile.close();
}

void FromVectorToFile(vector<Book> books, string &fileName) {
  ofstream booksFile(fileName, ios ::in | ios::trunc);
  for (int i = 0; i < books.size(); i++) {
    booksFile.write((char *)&books[i], sizeof(Book));
  }
  booksFile.close();
}

void DisplayBooksVector(vector<Book> &books) {
  cout << "\nBooks:\n";
  for (int i = 0; i < books.size(); i++) {
    DisplayBook(books[i]);
  }
}

void Keys() {
  cout << "\n1 - title\n";
  cout << "2 - author's name\n";
  cout << "3 - year\n";
}

void SelectionSort(vector<Book> &books) {
  int key;
  cout << "Choose parameter for sorting:\n";
  Keys();
  cin >> key;
  for (int i = 0; i < books.size() - 1; i++) {
    int min = i;
    for (int j = i + 1; j < books.size(); j++) {
      if (key == 1 && (strcmp(books[j].title, books[min].title)) < 0) {
        min = j;
      } else if (key == 2 &&
                 (strcmp(books[j].authorName, books[min].authorName)) < 0) {
        min = j;
      } else if (key == 3 && (books[j].year < books[min].year)) {
        min = j;
      }
    }
    if (min != i) {
      swap(books[i], books[min]);
    }
  }
  cout << "\nBooks are sorted\n";
}

int SearchByParameter(vector<Book> &books) {
  int key;
  char parameter1[30];
  int parameter2;
  cout << "\nChoose parameter for searching:\n";
  Keys();
  cin >> key;
  if (key == 1) {
    cout << "Enter parameter:\n";
    cin.ignore(256, '\n');
    cin.getline(parameter1, 30);
    for (int i = 0; i < books.size(); i++) {
      if (strcmp(parameter1, books[i].title) == 0) {
        return i;
      }
    }
  } else if (key == 2) {
    cout << "Enter parameter:\n";
    cin.ignore(256, '\n');
    cin.getline(parameter1, 30);
    for (int i = 0; i < books.size(); i++) {
      if (strcmp(parameter1, books[i].authorName) == 0) {
        return i;
      }
    }
  } else if (key == 3) {
    cout << "Enter parameter:\n";
    cin >> parameter2;
    for (int i = 0; i < books.size(); i++) {
      if (parameter2 == books[i].year) {
        return i;
      }
    }
  }
}

void DeleteElement(vector<Book> &books) {
  int index = SearchByParameter(books);
  books.erase(books.begin() + index);
  cout << "Book is deleted\n";
}

void Menu() {
  cout << "1 - add new book\n";
  cout << "2 - display books\n";
  cout << "3 - sort out alphabetically by a certain field\n";
  cout << "4 - delete a certain book by a chosen field\n";
  cout << "5 - commit all changes to file and exit the programm\n";
}

int main() {
  vector<Book> books;
  string booksFileName("books.bin");
  fstream booksFile(booksFileName);

  void (*options[4])(vector<Book> & books) = {AddBook, DisplayBooksVector,
                                              SelectionSort, DeleteElement};

  FromFileToVector(books, booksFileName);

  int next = 1;
  while (next) {
    int option;
    cout << "\nChoose option\n";
    Menu();
    cin >> option;
    if (option == 5) {
      next = 0;
    } else {
      options[option - 1](books);
    }
  }

  FromVectorToFile(books, booksFileName);
  return 0;
}