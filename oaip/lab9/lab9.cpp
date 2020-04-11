#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
void menu() {

  cout << "1 - Enter array of structures"
       << "\n";
  cout << "2 - Display array of structures"
       << "\n";
  cout << "3 - Sort out array of structures"
       << "\n";
  cout << "4 - Search/change/delete a certain structure by a parameter"
       << "\n";
  cout << "5 - Escape"
       << "\n";
}

union marks {
  int maths, physics, russian, literature;
};

typedef enum Mark { MARK_D, MARK_C, MARK_B, MARK_A } Mark;

typedef struct Pupil {
  char first_name[20];
  char last_name[20];
  char generic_name[30];
  unsigned int phone_number : 24;
  char adress[20];
  unsigned int grade : 4;
  Mark maths_mark;
  Mark physics_mark;
  Mark russian_mark;
  Mark literature_mark;
} Schoolar;

void enter_pupil(Pupil *pupils, int &enter, int &n) {
  int grade, phone;
  cout << "Enter first name"
       << "\n";
  cin >> pupils[enter].first_name;
  cout << "Enter last name"
       << "\n";
  cin >> pupils[enter].last_name;
  cout << "Enter generic name"
       << "\n";
  cin >> pupils[enter].generic_name;
  cout << "Enter phone number"
       << "\n";
  cin >> phone;
  pupils[enter].phone_number = phone;
  cout << "Enter adress"
       << "\n";
  cin >> pupils[enter].adress;
  cout << "Enter grade"
       << "\n";
  cin >> grade;
  pupils[enter].grade = grade;
  cout << "Enter maths mark from 0 to 3"
       << "\n";
  int mark;
  cin >> mark;
  pupils[enter].maths_mark = (Mark)mark;
  cout << "Enter physics mark from 0 to 3"
       << "\n";
  cin >> mark;
  pupils[enter].physics_mark = (Mark)mark;
  cout << "Enter russian mark from 0 to 3"
       << "\n";
  cin >> mark;
  pupils[enter].russian_mark = (Mark)mark;
  cout << "Enter literature mark from 0 to 3"
       << "\n";
  cin >> mark;
  pupils[enter].literature_mark = (Mark)mark;
  enter++;
}

void display_pupil(Pupil *pupils, int &enter, int &i) {
  for (int i = 0; i < enter; i++) {
    cout << "name: " << pupils[i].first_name << "\n";
    cout << "last name: " << pupils[i].last_name << "\n";
    cout << "generic name: " << pupils[i].generic_name << "\n";
    cout << "phone number: " << pupils[i].phone_number << "\n";
    cout << "adress: " << pupils[i].adress << "\n";
    cout << "grade: " << pupils[i].grade << "\n";
    cout << "Maths: " << pupils[i].maths_mark << "\n";
    cout << "Physics: " << pupils[i].physics_mark << "\n";
    cout << "Russian: " << pupils[i].russian_mark << "\n";
    cout << "Literature: " << pupils[i].literature_mark << "\n"
         << "\n";
  }
}

void sort_out(Pupil *pupils, int &enter) {
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
  cout << "1 - first name"
       << "\n";
  cout << "2 - last name"
       << "\n";
  cout << "3 - grade"
       << "\n";
}

void option_menu() {
  cout << "1 - display"
       << "\n";
  cout << "2 - change"
       << "\n";
  cout << "3 - delete"
       << "\n";
}

void option(Pupil *pupils, int &enter, int &index_to_change) {
  int opt;
  int not_equal = -1;
  cout << "choose option"
       << "\n";
  option_menu();
  cin >> opt;
  switch (opt) {
  case 1: {
    int condition = index_to_change + 1;
    display_pupil(pupils, condition, index_to_change);
    break;
  }
  case 2: {
    enter_pupil(pupils, index_to_change, not_equal);
    break;
  }
  case 3: {

    for (int i = index_to_change; i < enter; i++) {
      pupils[i] = pupils[i + 1];
    }
    enter--;
  }
  }
}

void search(Pupil *pupils, int &enter) {
  char name[20];
  char last[20];
  int grd;
  Pupil temp;
  cout << "choose the parameter for searching"
       << "\n";
  int k;
  parameter();
  cin >> k;
  switch (k) {
  case 1: {
    cout << "enter first name"
         << "\n";
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
    cout << "enter last name"
         << "\n";
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
    cout << "enter grade"
         << "\n";
    cin >> grd;
    for (int i = 0; i < enter; i++) {
      if (grd == pupils[i].grade) {
        option(pupils, enter, i);
        break;
      }
    }
    break;
  }
  }
}

main() {
  int key;
  int n = 5;
  int enter = 0;
  int *enter_ptr = &enter;
  Pupil *pupils;
  pupils = (Pupil *)malloc(n * sizeof(Pupil));
  bool process = 1;
  while (process) {
    if (enter == n) {
      n *= 2;
      pupils = (Pupil *)realloc(pupils, n * sizeof(Pupil));
    }
    cout << "Enter key"
         << "\n";
    menu();
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
      sort_out(pupils, enter);
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
    }
  }
}
