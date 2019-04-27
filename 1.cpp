#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX = 20;

struct Info {
  int size;
  int state;
  time_t t;
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
      cout << endl << "Table " << i+1 << ": " << endl;
      cout << "Size: " << table[i].size;
      if (table[i].state == 0) {
        cout << "  Time: 0";
        cout << "  State: Available" << endl;
      }
      else {
        cout << "  Time: " << time(NULL)-table[i].t << "s";
        if (table[i].state == 1)
          cout << "  State: Occupied";
        else if (table[i].state == 2)
          cout << "  State: Booked";
        if ((time(NULL)-table[i].t) > 72 && table[i].state == 1)
          cout << " (Overtime!)" << endl;
        else if ((time(NULL)-table[i].t) > 36 && table[i].state == 2)
          cout << " (Booking Overtime! Please release the booking.)" << endl;
      }
    }
  }
}

void occupyTable(Info table[]) {
  int num;
  char choose;

  while(true) {
    cout << "Table Number: ";
    cin >> num;
    if (table[num-1].size == 0)
      cout << "Table doesn't exist." << endl;
    else if (table[num-1].state != 0)
      cout << "Failed. Table is not vacant." << endl;
    else {
      table[num-1].state = 1;
      table[num-1].t = time(NULL);
    }
    cout << "Occupy another table? (Y/N): ";
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

    cout << "Release another table? (Y/N): ";
    cin >> choose;
    if (choose == 'N')
      break;
  }
}

void findTable(Info table[]) {
  int num, min = -1, diff = MAX;
  cout << "Number of customers: ";
  cin >> num;

  for(int i = 0; i < MAX; i++) {
    if (table[i].state == 0 && table[i].size != 0){
      if (table[i].size >= num && (table[i].size-num) < diff) {
        min = i;
        diff = table[i].size-num;
      }
    }
  }
  if (min == -1)
    cout << "No available table is found." << endl;
  else
    cout << "Table " << min+1 << " is availtable."<< endl;
}

void addBooking(Info table[]) {
  int num;
  char choose;
  string name, phone;

  while(true) {
    cout << "Please enter the name: ";
    cin >> name;
    cout << "Please enter phone number: ";
    cin >> phone;
    cout << "Table Number: ";
    cin >> num;

    if (table[num-1].state != 0)
      cout << "Failed. Table is not vacant.";
    else {
      table[num-1].state = 2;
      table[num-1].t = time(NULL);

      ofstream fout("Booking.txt");
      if (!fout) {
        cout << "Failed to open file.";
        return;
      }
      fout << "Name: " << name << "  Phone No.: " << phone << "  Table No.: " << num;
      fout.close();
    }
    cout << "Add another booking? (Y/N): ";
    cin >> choose;
    if (choose == 'N')
      break;
  }
}

void releaseBooking(Info table[]) {
  int num, choose;

  cout << "1: Cancel Booking" << endl;
  cout << "2: Customer Arrived" << endl;
  cout << "Please enter your choice (1/2): ";
  cin >> choose;
  cout << "Please enter the booked table number: ";
  cin >> num;
  if (table[num-1].state == 2) {
    if (choose == 1)
      table[num-1].state = 0;
    else if (choose == 2) {
      table[num-1].state = 1;
      table[num-1].t = time(NULL);
    }
  }
  else
    cout << "Table was not booked." << endl;
}

int main() {
  Info table[MAX];
  int choose;

  createTable(table);
  while(true) {
    cout << endl << "Table Management System" << endl;
    cout << "************************" << endl;
    cout << "1: Check Table" << endl;
    cout << "2: Occupy Table" << endl;
    cout << "3: Release Table" << endl;
    cout << "4: Find Table" << endl;
    cout << "5: Add Booking" << endl;
    cout << "6: Release Booking" << endl;
    cout << "7: Reset Tables" << endl;
    cout << "Please enter your choice (1-7): ";
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
      case 5:
        addBooking(table);
        break;
      case 6:
        releaseBooking(table);
        break;
      case 7:
        createTable(table);
        break;
    }
  }
}
