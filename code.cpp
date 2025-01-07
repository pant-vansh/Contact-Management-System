#include<iostream>
#include<fstream>
using namespace std;
class temp
{
    string name,address,father_name,mother_name,mobile_no,gender,email,description,search;
    fstream file;
    public:
    void addContact();
    void showAll();
    void searchContact();
    void modifyContact();
    void deleteContact();
}obj;
int main()
{
    char choice;

    // Display the menu with the formatted text
    while (true)
    {
        printf("\n\t\tWELCOME TO THE PHONEBOOK MENU");
        printf("\n\t\t******************************");
        printf("\n\nEnter your choice number");
        printf("\n\n\t1. Add New");
        printf("\n\t2. List of Contacts");
        printf("\n\t3. Exit Menu");
        printf("\n\t4. Modify Contacts");
        printf("\n\t5. Search for Contacts");
        printf("\n\t6. Delete Contacts\n");

        // Take user input
        cin >> choice;
        // cin.ignore();  // Clear the buffer after reading a character

        switch (choice)
        {
            case '1':
                obj.addContact();
                // thi is case 1
                break;

            case '2':
                obj.showAll();
                break;

            case '3':
                cout << "Exiting the program." << endl;
                return 0;  // Exit the program

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
                cout << "Invalid Selection ...! Please try again." << endl;
                break;
        }
    }
    return 0; 
}

void temp :: addContact()
{
    cout<<"Enter Name:: ";
    getline(cin,name);
    cout<<"Enter Address :: ";
    getline(cin,address);
    cout<<"Enter Father's Name :: ";
    getline(cin,father_name);
    cout<<"Enter Mother's Name :: ";
    getline(cin,mother_name);
    cout<<"Enter Phone Number :: ";
    getline(cin,mobile_no);
    cout<<"Enter Gender :: ";
    getline(cin,gender);
    cout<<"Enter Email Address :: ";
    getline(cin,email);
    cout<<"Description :: ";
    getline(cin,description);

    file.open("data.csv" , ios :: out | ios :: app);
    file<<name<<","<<address<<","<<father_name<<","<<mother_name<<","<<mobile_no<<","<<gender<<","<<email<<","<<description<<"\n";
    file.close();
}
void temp :: showAll()
{
    cout<<endl;
    file.open("data.csv", ios :: in);
    getline(file,name,',');
    getline(file,address,',');
    getline(file,father_name,',');
    getline(file,mother_name,',');
    getline(file,mobile_no,',');
    getline(file,gender,',');
    getline(file,email,',');
    getline(file,description,'\n');
    

    while( !file.eof())
    {
        cout<<"Name :: "<<name<<endl;
        cout<<"Address :: "<<address<<endl;
        cout<<"Father's Name :: "<<father_name<<endl;
        cout<<"Mother's Name :: "<<mother_name<<endl;
        cout<<"Phone Number  :: "<<mobile_no<<endl;
        cout<<"Gender :: "<<gender<<endl;
        cout<<"Emial  :: "<<email<<endl;
        cout<<"Description :: "<<description<<endl<<endl;

        getline(file,name,',');
        getline(file,address,',');
        getline(file,father_name,',');
        getline(file,mother_name,',');
        getline(file,mobile_no,',');
        getline(file,gender,',');
        getline(file,email,',');
        getline(file,description,'\n');
    }
    file.close();
}

void temp :: searchContact()
{
    cout<<"Enter Name :: ";
    getline(cin,search);

    file.open("data.csv", ios :: in);
    getline(file,name,',');
    getline(file,address,',');
    getline(file,father_name,',');
    getline(file,mother_name,',');
    getline(file,mobile_no,',');
    getline(file,gender,',');
    getline(file,email,',');
    getline(file,description,'\n');
    
    bool found = false;

    cout<<endl;
    while( !file.eof())
    {
        if( name == search)
        {
            cout<<"Name :: "<<name<<endl;
            cout<<"Address :: "<<address<<endl;
            cout<<"Father's Name :: "<<father_name<<endl;
            cout<<"Mother's Name :: "<<mother_name<<endl;
            cout<<"Phone Number  :: "<<mobile_no<<endl;
            cout<<"Gender :: "<<gender<<endl;
            cout<<"Emial  :: "<<email<<endl;
            cout<<"Description :: "<<description<<endl<<endl;

            found = true;
            break;
        }

        getline(file,name,',');
        getline(file,address,',');
        getline(file,father_name,',');
        getline(file,mother_name,',');
        getline(file,mobile_no,',');
        getline(file,gender,',');
        getline(file,email,',');
        getline(file,description,'\n');
    }
    file.close();

    if (!found) 
    {
        cout << "Contact not found!" << endl;
    }
}

// add later
void temp::modifyContact()
{
    cout << "Modify Contact functionality will go here." << endl;
}

void temp::deleteContact()
{
    cout << "Delete Contact functionality will go here." << endl;
}