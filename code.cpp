#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class temp {
    string name, address, father_name, mother_name, mobile_no, gender, email, description, search;
    fstream file;

public:
    void addContact();
    void showAll();
    void searchContact();
    void modifyContact();
    void deleteContact();
}obj;

int main() {
    char choice;

    while (true) {
        cout << "\n\t\tWELCOME TO THE PHONEBOOK MENU\n";
        cout << "\t\t******************************\n";
        cout << "\nEnter your choice number\n";
        cout << "\t1. Add New\n";
        cout << "\t2. List of Contacts\n";
        cout << "\t3. Exit Menu\n";
        cout << "\t4. Modify Contacts\n";
        cout << "\t5. Search for Contacts\n";
        cout << "\t6. Delete Contacts\n";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                obj.addContact();
                break;
            case '2':
                obj.showAll();
                break;
            case '3':
                cout << "Exiting the program.\n";
                return 0;
            case '4':
                obj.modifyContact();
                break;
            case '5':
                obj.searchContact();
                break;
            case '6':
                obj.deleteContact();
                break;
            default:
                cout << "Invalid Selection... Please try again.\n";
                break;
        }
    }
    return 0; 
}

void temp::addContact() 
{

    do 
    {
        cout << "Enter Name: ";
        getline(cin, name);
        if (name.empty()) 
        {
            cout << "Name cannot be empty. Please try again.\n";
        }
    } 
    while (name.empty());

    // Address 
    do 
    {
        cout << "Enter Address: ";
        getline(cin, address);
        if (address.empty()) 
        {
            cout << "Address cannot be empty. Please try again.\n";
        }
    } 
    while (address.empty());

    // Father's Name Validation
    do {
        cout << "Enter Father's Name: ";
        getline(cin, father_name);
        if (father_name.empty()) 
        {
            cout << "Father's name cannot be empty. Please try again.\n";
        }
    } 
    while (father_name.empty());

    // Mother's Name Validation
    do 
    {
        cout << "Enter Mother's Name: ";
        getline(cin, mother_name);
        if (mother_name.empty()) 
        {
            cout << "Mother's name cannot be empty. Please try again.\n";
        }
    } 
    while (mother_name.empty());

    // Mobile Number 
    do 
    {
        cout << "Enter Phone Number: ";
        getline(cin, mobile_no);
        if (mobile_no.length() != 10 || !all_of(mobile_no.begin(), mobile_no.end(), ::isdigit)) 
        {
            cout << "Invalid phone number. It must be exactly 10 digits. Please try again.\n";
        }
    } 
    while (mobile_no.length() != 10 || !all_of(mobile_no.begin(), mobile_no.end(), ::isdigit));

    // Gender 
    do 
    {
        cout << "Enter Gender (Male/Female/Other): ";
        getline(cin, gender);
        if (gender != "Male" && gender != "Female" && gender != "Other") 
        {
            cout << "Invalid gender. Please enter 'Male', 'Female', or 'Other'.\n";
        }
    } 
    while (gender != "Male" && gender != "Female" && gender != "Other");

    // Email Address 
    do 
    {
        cout << "Enter Email Address: ";
        getline(cin, email);
        size_t at_pos = email.find('@');
        size_t dot_pos = email.rfind('.');
        if (at_pos == string::npos || dot_pos == string::npos || at_pos > dot_pos) 
        {
            cout << "Invalid email address. Please try again.\n";
        }
    } 
    while (email.find('@') == string::npos || email.rfind('.') == string::npos || email.find('@') > email.rfind('.'));

    cout << "Description: ";
    getline(cin, description);

    file.open("data.csv", ios::out | ios::app);
    if (!file.is_open()) 
    {
        cout << "Error opening file!\n";
        return;
    }
    file << name << "," << address << "," << father_name << "," << mother_name << ","<< mobile_no << "," << gender << "," << email << "," << description << "\n";
    file.close();

    cout << "Contact added successfully!\n";
}



void temp::showAll() {
    file.open("data.csv", ios::in);
    if (!file.is_open()) {
        cout << "Error opening file!\n";
        return;
    }

    while (getline(file, name, ',')) {
        getline(file, address, ',');
        getline(file, father_name, ',');
        getline(file, mother_name, ',');
        getline(file, mobile_no, ',');
        getline(file, gender, ',');
        getline(file, email, ',');
        getline(file, description, '\n');
        
        cout << "\nName: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Father's Name: " << father_name << endl;
        cout << "Mother's Name: " << mother_name << endl;
        cout << "Phone Number: " << mobile_no << endl;
        cout << "Gender: " << gender << endl;
        cout << "Email: " << email << endl;
        cout << "Description: " << description << endl;
    }
    file.close();
}

void temp::searchContact() {
    cout << "Enter Name: ";
    getline(cin, search);

    file.open("data.csv", ios::in);
    if (!file.is_open()) {
        cout << "Error opening file!\n";
        return;
    }

    bool found = false;
    while (getline(file, name, ',')) {
        getline(file, address, ',');
        getline(file, father_name, ',');
        getline(file, mother_name, ',');
        getline(file, mobile_no, ',');
        getline(file, gender, ',');
        getline(file, email, ',');
        getline(file, description, '\n');

        if (name == search) {
            cout << "\nName: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Father's Name: " << father_name << endl;
            cout << "Mother's Name: " << mother_name << endl;
            cout << "Phone Number: " << mobile_no << endl;
            cout << "Gender: " << gender << endl;
            cout << "Email: " << email << endl;
            cout << "Description: " << description << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Contact not found!\n";
    }
}

void temp::modifyContact() {
    cout << "Enter the name of the contact you want to modify: ";
    getline(cin, search);

    vector<string> contacts;
    string line;
    bool found = false;

    file.open("data.csv", ios::in);
    if (!file.is_open()) {
        cout << "Error opening file!\n";
        return;
    }

    while (getline(file, line)) {
        contacts.push_back(line);
    }
    file.close();

    for (size_t i = 0; i < contacts.size(); i++) {
        stringstream ss(contacts[i]);
        string contact_name;
        getline(ss, contact_name, ',');

        if (contact_name == search) {
            found = true;
            cout<<endl;
            cout << "Contact found. Enter new details for the contact:\n";

            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Father's Name: ";
            getline(cin, father_name);
            cout << "Enter Mother's Name: ";
            getline(cin, mother_name);
            cout << "Enter Phone Number: ";
            getline(cin, mobile_no);
            cout << "Enter Gender: ";
            getline(cin, gender);
            cout << "Enter Email Address: ";
            getline(cin, email);
            cout << "Description: ";
            getline(cin, description);

            contacts[i] = name + "," + address + "," + father_name + "," + mother_name + ","
                          + mobile_no + "," + gender + "," + email + "," + description;
            break;
        }
    }

    if (found) 
    {
        file.open("data.csv", ios::out | ios::trunc);
        if (!file.is_open()) 
        {
            cout << "Error opening file!\n";
            return;
        }

        for (const string& contact : contacts) 
        {
            file << contact << "\n";
        }
        cout << "Contact updated successfully.\n";
        file.close();
    } 
    else 
    {
        cout << "Contact not found for modification.\n";
    }
}

void temp::deleteContact() 
{
    cout << "Enter the name of the contact you want to delete: ";
    getline(cin, search);

    vector<string> contacts;
    string line;
    bool found = false;

    // Read all contacts from the file
    file.open("data.csv", ios::in);
    if (!file.is_open()) 
    {
        cout << "Error opening file!\n";
        return;
    }

    while (getline(file, line)) 
    {
        stringstream ss(line);
        string contact_name;
        getline(ss, contact_name, ',');
        
        // If the name matches, skip adding it to the vector
        if (contact_name == search) 
        {
            found = true;
            continue;
        }
        contacts.push_back(line);
    }
    file.close();

    // Overwrite the file with the remaining contacts
    if (found) {
        file.open("data.csv", ios::out | ios::trunc);
        if (!file.is_open()) 
        {
            cout << "Error opening file!\n";
            return;
        }

        for (const string& contact : contacts) 
        {
            file << contact << "\n";
        }
        file.close();
        cout << "Contact deleted successfully.\n";
    } 
    else 
    {
        cout << "Contact not found!\n";
    }
}

