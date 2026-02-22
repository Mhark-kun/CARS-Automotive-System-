#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

//The RentalRecord struct stores all relevant information for a car rental transaction.
struct RentalRecord {
    char name[50], number[20], email[50], rentDate[20];
    char car[30], packageName[10];
    int price;
};

//Displays rental records from the file. Shows a message if the file can't be opened.
void showRecords() {
    ifstream file("rental_records.txt");
    if (!file.is_open()) {
        cout << "No records found." << endl;
        return;
    }
    //Reads and prints each line from the rental records file.
    char line[100];
    cout << "--- Rental Records ---" << endl;
    while (file.getline(line, 100)) {
        cout << line << endl;
    }
    file.close();
}

//Appends a new rental record to the rental_records.txt file.
void saveRecord(RentalRecord r) {
    ofstream file("rental_records.txt", ios::app);
    file << "Name: " << r.name << endl;
    file << "Phone: " << r.number << endl;
    file << "Email: " << r.email << endl;
    file << "Car: " << r.car << endl;
    file << "Package: " << r.packageName << endl;
    file << "Price: PHP " << r.price << endl;
    file << "Rent Date: " << r.rentDate << endl;
    file << "-----------------------------" << endl;
    file.close();
}

//Clears all data in the rental_records.txt file.
void clearRecords() {
    ofstream file("rental_records.txt", ios::trunc);
    if (file.is_open()) {
        cout << "All rental records have been cleared." << endl;
        file.close();
    } else {
        cout << "Failed to clear records." << endl;
    }
}
//Displays details of the selected car based on the carType input.
void showCarDetails(int carType) {
    if (carType == 1) {
        cout << endl;
        cout << "Toyota Vios" << endl;
        cout << "Description: The Toyota Vios is a fuel-efficient and comfortable sedan, perfect for both city driving and long-distance trips. With its smooth handling and reliable performance, it's ideal for daily commutes or weekend getaways across the Philippines." << endl;
        cout << "Maximum Capacity: 5 people" << endl;
        cout << "Suggested Places to Use: Metro Manila, Tagaytay, Baguio, Batangas, Subic, Clark, and other urban or provincial highways." << endl;
    } else if (carType == 2) {
        cout << endl;
        cout << "Ford Ranger" << endl;
        cout << "Description: The Ford Ranger is a rugged and versatile pickup truck known for its strong performance, off-road capability, and modern features. Ideal for both work and adventure." << endl;
        cout << "Maximum Capacity: 5 people" << endl;
        cout << "Suggested Places to Use: Davao Region, Palawan, Bicol Region, Sagada & Banaue." << endl;
    } else if (carType == 3) {
        cout << endl;
        cout << "Nissin Urvan" << endl;
        cout << "Description: The Nissin Urvan is a versatile van ideal for large groups. Great for family trips or group tours." << endl;
        cout << "Maximum Capacity: 10-15 people" << endl;
        cout << "Suggested Places to Use: Metro Manila, Tagaytay, Baguio, Batangas, Subic, Clark, etc." << endl;
    }
}
//Handles login for authorized personnel and provides options to view or clear rental records.
int main() {
    char userType[15], password[20];

    cout << "Are you an 'authorized' personnel or a 'customer'? ";
    cin >> userType;

    for (int i = 0; userType[i]; i++) {
        userType[i] = tolower(userType[i]);
    }

    if (strcmp(userType, "authorized") == 0) {
        cout << "Enter password: ";
        cin >> password;
        if (strcmp(password, "admin123") == 0) {
            int choice;
            cout << "\n1. View Rental Records" << endl;
            cout << "2. Clear Rental Records" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 1) {
                showRecords();
            } else if (choice == 2) {
                clearRecords();
            } else {
                cout << "Invalid choice." << endl;
            }
        } else {
            cout << "Incorrect password. Access denied." << endl;
        }
        return 0;
    } else if (strcmp(userType, "customer") != 0) {
        cout << "Invalid input. Please enter 'authorized' or 'customer' only." << endl;
        return 0;
    }
//Collects customer details and lets them choose a car to rent.
    RentalRecord r;
    int carType, packageChoice;

    cout << "\n--- Customer Details ---" << endl;
    cin.ignore();
    cout << "Name: ";
    cin.getline(r.name, 50);
    cout << "Phone Number: ";
    cin.getline(r.number, 20);
    cout << "Email Address: ";
    cin.getline(r.email, 50);
    cout << "Enter Rent Date (MM/DD/YYYY): ";
    cin.getline(r.rentDate, 15);

    cout << "\nAvailable Cars:" << endl;
    cout << "1. Toyota Vios" << endl;
    cout << "2. Ford Ranger" << endl;
    cout << "3. Nissin Urvan" << endl;
    cout << "Choose a car by entering the corresponding number: ";
    cin >> carType;

//Lets the customer choose a rental package based on the selected car 
//Sets the corresponding car name, package details, and price.
    showCarDetails(carType);
    switch (carType) {
        case 1:
            strcpy(r.car, "Toyota Vios");
            cout << "\nChoose a Package:" << endl;
            cout << "1. 1 day - PHP 1500" << endl;
            cout << "2. 2 days - PHP 2500" << endl;
            cout << "3. 1 week - PHP 10000" << endl;
            break;
        case 2:
            strcpy(r.car, "Ford Ranger");
            cout << "\nChoose a Package:" << endl;
            cout << "1. 1 day - PHP 2000" << endl;
            cout << "2. 2 days - PHP 3500" << endl;
            cout << "3. 1 week - PHP 12000" << endl;
            break;
        case 3:
            strcpy(r.car, "Nissin Urvan");
            cout << "\nChoose a Package:" << endl;
            cout << "1. 1 day - PHP 4500" << endl;
            cout << "2. 2 days - PHP 9000" << endl;
            cout << "3. 1 week - PHP 20000" << endl;
            break;
        default:
            cout << "Invalid car type." << endl;
            return 0;
    }

    cout << "Enter package number: ";
    cin >> packageChoice;

    if (carType == 1) {
        switch (packageChoice) {
            case 1: strcpy(r.packageName, "1 day"); r.price = 1500; break;
            case 2: strcpy(r.packageName, "2 days"); r.price = 2500; break;
            case 3: strcpy(r.packageName, "1 week"); r.price = 10000; break;
            default: cout << "Invalid package." << endl; return 0;
        }
    } else if (carType == 2) {
        switch (packageChoice) {
            case 1: strcpy(r.packageName, "1 day"); r.price = 2000; break;
            case 2: strcpy(r.packageName, "2 days"); r.price = 3500; break;
            case 3: strcpy(r.packageName, "1 week"); r.price = 12000; break;
            default: cout << "Invalid package." << endl; return 0;
        }
    } else if (carType == 3) {
        switch (packageChoice) {
            case 1: strcpy(r.packageName, "1 day"); r.price = 4500; break;
            case 2: strcpy(r.packageName, "2 days"); r.price = 9000; break;
            case 3: strcpy(r.packageName, "1 week"); r.price = 20000; break;
            default: cout << "Invalid package." << endl; return 0;
        }
    }
//Saves the record and displays a rental summary.
    saveRecord(r);

    cout << "\n--- Rental Summary ---" << endl;
    cout << "Name: " << r.name << endl;
    cout << "Phone: " << r.number << endl;
    cout << "Email: " << r.email << endl;
    cout << "Car: " << r.car << endl;
    cout << "Package: " << r.packageName << endl;
    cout << "Price: PHP " << r.price << endl;
    cout << "Rent Date: " << r.rentDate << endl;

    return 0;
}

