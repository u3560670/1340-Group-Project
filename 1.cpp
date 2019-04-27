#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 20;

struct Info {
  int size;
  int state;
};

void createTable(Info table[]) {
  int num, size;

  cout << "Number of tables: ";
  cin >> num;
  for (int i = 0; i < MAX; i++) {
    if (i < num) {
      cout << "Size of tables " << i+1 << ": ";
      cin >> size;
      table[i].size = size;
      table[i].state = 0;
    }
    else
      table[i].size = 0;
  }
}

void showTable(Info table[]) {
  for (int i = 0; i < MAX; i++) {
    if (table[i].size != 0) {
      cout << "Table " << i+1 << ": ";
      cout << "size: " << table[i].size;
      if (table[i].state == 0)
        cout << "state: Available" << endl;
      else
        cout << "state: Not available" << endl;
    }
  }
}

void occupyTable(Info table[]) {
  int num;
  char choose;

  while(true) {
    cout << "Table Number: ";
    cin >> num;
    if (table[num-1].state != 0)
      cout << "Failed. Table is not vacant.";
    else
      table[num-1].state = 1;

    cout << "Continue? (Y/N): ";
    cin >> choose;
    if (choose == 'N')
      break;
  }
}

void releaseTable(Info table[]) {
  int num;
  char choose;

  while(true) {
    cout << "Table Number: ";
    cin >> num;

    table[num-1].state = 0;

    cout << "Continue? (Y/N): ";
    cin >> choose;
    if (choose == 'N')
      break;
  }
}

void findTable(Info table[]) {
  int num, min = 0, diff = MAX;
  cout << "Number of customers: ";
  cin >> num;

  for(int i = 0; i < MAX; i++) {
    if (table[i].size > num && (table[i].size-num) < diff && table[i].state == 0 && table[i].size != 0){
      min = i;
      diff = table[i].size-num;
    }
  }
  cout << "Table: " << min << endl;
}

int main() {
  Info table[MAX];
  int choose;

  createTable(table);
  while(true) {
    cout << "Table Management System" << endl;
    cout << "************************" << endl;
    cout << "1: Check Table" << endl;
    cout << "2: Occupy Table" << endl;
    cout << "3: Release Table" << endl;
    cout << "4: Find Table" << endl;
    cin >> choose;
    for (int i = 0; i < 30; i++) {
      cout << endl;
    }
    switch (choose) {
      case 1:
        showTable(table);
        break;
      case 2:
        occupyTable(table);
        break;
      case 3:
        releaseTable(table);
        break;
      case 4:
        findTable(table);
        break;
    }
  }
}
