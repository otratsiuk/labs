#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_array_value(fstream &file) {
  int temp;
  int count = 0;
  for (int i = 0; file >> temp; i++)
    count++;
  file.clear();
  file.seekg(0);
  return (count);
}

void from_file_to_array(fstream &file, int array[], int value) {
  for (int i = 0; i < value; i++) {
    file >> array[i];
  }
  file.clear();
  file.seekg(0);
}

void heapify(int array[], int heap_size, int index) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  if (left < heap_size && array[left] > array[largest])
    largest = left;
  if (right < heap_size && array[right] > array[largest])
    largest = right;
  if (largest != index) {
    swap(array[index], array[largest]);
    heapify(array, heap_size, largest);
  }
}

void heap_sort(int array[], int heap_size) {
  for (int index = heap_size / 2 - 1; index >= 0; index--)
    heapify(array, heap_size, index);
  for (int index = heap_size - 1; index > 0; index--) {
    swap(array[0], array[index]);
    heapify(array, index, 0);
  }
}

void add_sorted_array_to_file(fstream &file, int array[], int value) {
  file.clear();
  file.seekg(0, ios::end);
  for (int i = 0; i < value; i++) {
    file << array[i] << " ";
  }
}

int line_search(int array[], int value, int key) {
  int search_result = 0;
  for (int i = 0; i < value; i++) {
    if (array[i] == key)
      search_result++;
  }
  return (search_result);
}

void add_search_result_to_file(fstream &file, int array[], int value) {
  int key;
  cout << "enter key number for line search: ";
  cin >> key;
  int search_result = line_search(array, value, key);
  file.clear();
  file.seekg(0, ios::end);
  if (search_result != 0) {
    file << "\nsought_for number " << key << " exists in array";
  } else if (search_result == 0) {
    file << "\nsought-for number " << key << " doesn't exist in array";
  }
  file.close();
}

int count_strings(fstream &file) {
  string s;
  int string_counter = 0;
  file.seekp(0, ios::beg);
  while (getline(file, s)) {
    string_counter++;
  }
  return string_counter;
}

void erase_empty_strings(string file_name) {
  fstream file(file_name, ios::in);
  string s;
  int number_of_strings = count_strings(file);
  string strings[number_of_strings];
  file.clear();
  file.seekp(0, ios::beg);
  for (int i = 0; i < number_of_strings; i++) {
    getline(file, strings[i]);
  }
  file.close();
  file.open(file_name, ios::out);
  for (int i = 0; i < number_of_strings; i++) {
    if (strings[i].length() > 0) {
      file << strings[i] << "\n";
    }
  }
  file.close();
}

void formate_text(string unformatted_file_name, string formatted_file_name) {
  fstream unformatted_file(unformatted_file_name, ios::in);
  fstream formatted_file(formatted_file_name, ios::out);
  string s;
  string temp;
  int k, position;
  cout << "enter k(k>25) which defines width of text: ";
  cin >> k;
  unformatted_file.seekp(0, ios::beg);
  while (getline(unformatted_file, temp)) {
    s.append(temp);
  }
  for (int pos = 0; pos < s.length(); pos += k) {
    temp = s.substr(pos, k);
    position = temp.find("     ");
    if (temp[temp.length() - 1] == ' ') {
      temp.erase(temp.length() - 1, 1);
    }
    if (position > 0) {
      temp.insert(position, "\n");
      formatted_file << temp << "\n";
    } else
      formatted_file << temp << "\n";
  }
  unformatted_file.close();
  formatted_file.close();
}

void create_symbol_file(string text_file_name, string symbols_file_name) {
  fstream text_file(text_file_name, ios::in);
  fstream symbol_file(symbols_file_name, ios::out);
  bool equality;
  bool space_symbol;
  vector<char> symbols;
  char temp;
  string text;
  while (text_file >> temp) {
    equality = 1;
    for (int i = 0; i < symbols.size(); i++) {
      if (temp == symbols[i])
        equality = 0;
    }
    if (equality == 1) {
      symbols.push_back(temp);
    }
  }
  text_file.seekp(0, ios::beg);
  while (getline(text_file, text)) {
    text.append(text);
  }
  space_symbol = text.find(' ');
  if (space_symbol) {
    symbols.push_back(' ');
  }
  int symbols_code[symbols.size()];
  for (int i = 0; i < symbols.size(); i++) {
    symbols_code[i] = (int)symbols[i];
  }
  heap_sort(symbols_code, symbols.size());
  for (int i = 0; i < symbols.size(); i++) {
    symbol_file << (char)symbols_code[i];
  }
  text_file.close();
  symbol_file.close();
}

void menu() {
  cout << "tasks:\n";
  cout << "2 - task2\n";
  cout << "3 - task3\n";
  cout << "4 - task4\n";
  cout << "5 - task5\n";
}

main() {
  typedef void (*add_to_file_functions)(fstream & file, int *array,
                                        int array_value);

  add_to_file_functions task2[2]{add_sorted_array_to_file,
                                 add_search_result_to_file};
  int task_number;
  int process = 1;
  while (process) {
    menu();
    cout << "\nenter task number: ";
    cin >> task_number;
    switch (task_number) {
    case 2: {
      fstream file_with_array("task2.txt");
      int array_value;
      array_value = count_array_value(file_with_array);
      int *array = (int *)malloc(array_value * sizeof(int));
      from_file_to_array(file_with_array, array, array_value);
      heap_sort(array, array_value);
      task2[0](file_with_array, array, array_value);
      task2[1](file_with_array, array, array_value);
      cout << "check file task2.txt\n";
      break;
    }
    case 3: {
      string file_name("task3.txt");
      erase_empty_strings(file_name);
      cout << "check file task3.txt\n";
      break;
    }
    case 4: {
      string unformatted_file_name("task4_unformatted.txt");
      string formatted_file_name("task4_formatted.txt");
      formate_text(unformatted_file_name, formatted_file_name);
      cout << "check file task4_formatted.txt\n";
      break;
    }
    case 5: {
      string text_file("task5_text.txt");
      string symbol_file("task5_symbols.txt");
      create_symbol_file(text_file, symbol_file);
      cout << "check file task5_symbols.txt\n";
      break;
    }
    default: {
      cout << "such task doesn't exist\n";
      break;
    }
    }
    char answer;
    cout << "\nwant to continue?(y/n): ";
    cin >> answer;
    if (answer == 'n')
      process = 0;
  }
}