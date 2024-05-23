#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Directory {
private:
    string name;
    string owner;
    string phone;
    string address;
    string activity;

public:
    Directory() {}

    Directory(const string& n, const string& o, const string& p, const string& a, const string& act)
        : name(n), owner(o), phone(p), address(a), activity(act) {}

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Owner: " << owner << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Activity: " << activity << endl;
    }

    friend ostream& operator<<(ostream& os, const Directory& dir) {
        os << dir.name << "|" << dir.owner << "|" << dir.phone << "|" << dir.address << "|" << dir.activity << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Directory& dir) {
        getline(is, dir.name, '|');
        getline(is, dir.owner, '|');
        getline(is, dir.phone, '|');
        getline(is, dir.address, '|');
        getline(is, dir.activity);
        return is;
    }

    bool searchByName(const string& n) const {
        return name == n;
    }

    bool searchByOwner(const string& o) const {
        return owner == o;
    }

    bool searchByPhone(const string& p) const {
        return phone == p;
    }

    bool searchByActivity(const string& act) const {
        return activity == act;
    }
};

void addRecord() {
    ofstream file("directory.txt", ios::app);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    string name, owner, phone, address, activity;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter owner: ";
    getline(cin, owner);
    cout << "Enter phone: ";
    getline(cin, phone);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter activity: ";
    getline(cin, activity);

    Directory entry(name, owner, phone, address, activity);
    file << entry;
    file.close();
}

void searchByName() {
    ifstream file("directory.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    string name;
    cout << "Enter name to search: ";
    getline(cin, name);

    Directory entry;
    bool found = false;
    while (file >> entry) {
        if (entry.searchByName(name)) {
            entry.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No record found with name: " << name << endl;
    }

    file.close();
}

void searchByOwner() {
    ifstream file("directory.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    string owner;
    cout << "Enter owner to search: ";
    getline(cin, owner);

    Directory entry;
    bool found = false;
    while (file >> entry) {
        if (entry.searchByOwner(owner)) {
            entry.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No record found with owner: " << owner << endl;
    }

    file.close();
}

void searchByPhone() {
    ifstream file("directory.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    string phone;
    cout << "Enter phone number to search: ";
    getline(cin, phone);

    Directory entry;
    bool found = false;
    while (file >> entry) {
        if (entry.searchByPhone(phone)) {
            entry.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No record found with phone number: " << phone << endl;
    }

    file.close();
}

void searchByActivity() {
    ifstream file("directory.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    string activity;
    cout << "Enter activity to search: ";
    getline(cin, activity);

    Directory entry;
    bool found = false;
    while (file >> entry) {
        if (entry.searchByActivity(activity)) {
            entry.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No record found with activity: " << activity << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "1. Add Record" << endl;
        cout << "2. Search by Name" << endl;
        cout << "3. Search by Owner" << endl;
        cout << "4. Search by Phone" << endl;
        cout << "5. Search by Activity" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            searchByName();
            break;
        case 3:
            searchByOwner();
            break;
        case 4:
            searchByPhone();
            break;
        case 5:
            searchByActivity();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

