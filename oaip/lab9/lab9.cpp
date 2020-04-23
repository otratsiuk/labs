#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
void menu() {

  cout << "\n1 - add new pupil\n";
  cout << "2 - display array of structures\n";
  cout << "3 - sort out alphabetically\n";
  cout << "4 - search/change/delete a certain structure by a chosen field\n";
  cout << "5 - escape\n";
}

typedef struct Pupil {
  char first_name[20];
  char last_name[20];
  char generic_name[30];
  char phone_number[20];
  char adress[20];
  unsigned int grade : 4;
  char maths_mark[2];
  char physics_mark[2];
  char russian_mark[2];
  char literature_mark[2];
} Schoolar;

void enter_pupil(Pupil *pupils, int &enter, int &n) {
  int grade, phone;
  cout << "\nenter first name: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].first_name;
  cout << "enter last name: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].last_name;
  cout << "enter generic name: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].generic_name;
  cout << "enter phone number: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].phone_number;
  cout << "enter adress: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].adress;
  cout << "enter grade: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> grade;
  pupils[enter].grade = grade;
  cout << "enter maths mark: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].maths_mark;
  cout << "enter physics mark: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].physics_mark;
  cout << "enter russian mark: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].russian_mark;
  cout << "enter literature mark: ";
  cin.ignore(256, '\n');
  if (cin.peek() != 32)
    cin >> pupils[enter].literature_mark;
  enter++;
}

void display_pupil(Pupil *pupils, int &enter, int &i) {
  for (int i = 0; i < enter; i++) {
    cout << "\nname:\t\t" << pupils[i].first_name << "\n";
    cout << "last name:\t" << pupils[i].last_name << "\n";
    cout << "generic name:\t" << pupils[i].generic_name << "\n";
    cout << "phone number:\t" << pupils[i].phone_number << "\n";
    cout << "adress:\t\t" << pupils[i].adress << "\n";
    cout << "grade:\t\t" << pupils[i].grade << "\n";
    cout << "Maths:\t\t" << pupils[i].maths_mark << "\n";
    cout << "Physics:\t" << pupils[i].physics_mark << "\n";
    cout << "Russian:\t" << pupils[i].russian_mark << "\n";
    cout << "Literature:\t" << pupils[i].literature_mark << "\n\n";
  }
}

void sort_out_alphabetically(Pupil *pupils, int &enter) {
  Pupil temp;
  for (int i = 0; i < enter; i++) {
    for (int j = enter - 1; j > i; j--) {
      if ((pupils[j - 1].first_name[0] > pupils[j].first_name[0])) {
        temp = pupils[j - 1];
        pupils[j - 1] = pupils[j];
        pupils[j] = temp;
      }
    }
  }
}

void parameter() {
  cout << "\n1 - first name\n";
  cout << "2 - last name\n";
  cout << "3 - grade\n";
}

void display_option_menu() {
  cout << "1 - change\n";
  cout << "2 - remove structure\n";
}

enum Option_menu { change = 1, remove_structure };

void option(Pupil *pupils, int &enter, int &index_to_change) {
  Option_menu option_menu;
  int opt;
  int not_equal = -1;
  int condition = index_to_change + 1;
  display_pupil(pupils, condition, index_to_change);
  display_option_menu();
  cout << "\nchoose option: ";
  cin >> opt;
  switch (opt) {
  case change: {
    cout << "enter your changes, enter space to leave the field unchanged\n";
    enter_pupil(pupils, index_to_change, not_equal);
    break;
  }
  case remove_structure: {
    for (int i = index_to_change; i < enter; i++) {
      pupils[i] = pupils[i + 1];
    }
    enter--;
  }
  default: {
    cout << "\nwrong key\n";
    break;
  }
  }
}

void search(Pupil *pupils, int &enter) {
  char name[20];
  char last[20];
  int grd;
  Pupil temp;
  parameter();
  cout << "\nchoose the parameter for searching: ";
  int k;
  cin >> k;
  switch (k) {
  case 1: {
    cout << "\nenter first name: ";
    cin >> temp.first_name;
    for (int i = 0; i < enter; i++) {
      if (strcmp(temp.first_name, pupils[i].first_name) == 0) {
        option(pupils, enter, i);
        break;
      }
    }
    break;
  }
  case 2: {
    cout << "enter last name\n";
    cin >> temp.last_name;
    for (int i = 0; i < enter; i++) {
      if (strcmp(temp.last_name, pupils[i].last_name) == 0) {
        option(pupils, enter, i);
        break;
      }
    }
    break;
  }
  case 3: {
    cout << "enter grade\n";
    cin >> grd;
    for (int i = 0; i < enter; i++) {
      if (grd == pupils[i].grade) {
        option(pupils, enter, i);
        break;
      }
    }
    break;
  }
  default: {
    cout << "\nwrong parameter\n";
  }
  }
}

main() {
  int key;
  int n = 5;
  int enter = 0;
  Pupil *pupils;
  pupils = (Pupil *)malloc(n * sizeof(Pupil));
  bool process = 1;
  while (process) {
    if (enter == n) {
      n *= 2;
      pupils = (Pupil *)realloc(pupils, n * sizeof(Pupil));
    }
    menu();
    cout << "enter key: ";
    cin >> key;
    switch (key) {
    case 1: {
      enter_pupil(pupils, enter, n);
      break;
    }
    case 2: {
      int k = 0;
      display_pupil(pupils, enter, k);
      break;
    }
    case 3: {
      int k = 0;
      sort_out_alphabetically(pupils, enter);
      display_pupil(pupils, enter, k);
      break;
    }
    case 4: {
      search(pupils, enter);
      break;
    }
    case 5: {
      exit(1);
      break;
    }
    default: {
      cout << "\nwrong key\n";
      break;
    }
    }
  }
}