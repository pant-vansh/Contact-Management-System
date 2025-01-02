#include<iostream>
#include<fstream>
using namespace std;
class temp
{
    string phoneNo,name,address,description,search;
    fstream file;
    public:
    void addContact();
    void showAll();
    void searchContact();
}obj;
int main()
{
    char choice;

    cout<<"1 --> Add Contact"<<endl;
    cout<<"2 --> Show All Contact"<<endl;
    cout<<"3 --> Search Contact"<<endl;
    cout<<"0 --> exit"<<endl;

    cin>>choice;
    cin.ignore();

    switch (choice)
    {
        case '1':
            obj.addContact();
            break;

        case '2':
           obj.showAll();
           break;

        case '3':
           obj.searchContact();
           break;
        case '0':
            return 0;
            break;
        default:
            cout<<"Invalid Selection ...!";
            break;
    }

    return 0;
    
}

void temp :: addContact()
{
    cout<<"Enter Phone Number :: ";
    getline(cin,phoneNo);
    cout<<"Enter Name :: ";
    getline(cin,name);
    cout<<"Enter Address :: ";
    getline(cin,address);
    cout<<"Enter Description :: ";
    getline(cin,description);

    file.open("data.csv" , ios :: out | ios :: app);
    file<<phoneNo<<","<<name<<","<<address<<","<<description<<"\n";
    file.close();
}
void temp :: showAll()
{
    file.open("data.csv", ios :: in);
    getline(file,phoneNo,',');
    getline(file,name,',');
    getline(file,address,',');
    getline(file,description,'\n');

    while( !file.eof())
    {
        cout<<"Phone Number :: "<<phoneNo<<endl;
        cout<<"Name :: "<<name<<endl;
        cout<<"Address :: "<<address<<endl;
        cout<<"Description :: "<<description<<endl<<endl;

        getline(file,phoneNo,',');
        getline(file,name,',');
        getline(file,address,',');
        getline(file,description,'\n');
    }
    file.close();
}

void temp :: searchContact()
{
    cout<<"Enter Phone No :: ";
    getline(cin,search);

    file.open("data.csv", ios :: in);
    getline(file,phoneNo,',');
    getline(file,name,',');
    getline(file,address,',');
    getline(file,description,'\n');

    while( !file.eof())
    {
        if( phoneNo == search)
        {
            cout<<"Phone Number :: "<<phoneNo<<endl;
            cout<<"Name :: "<<name<<endl;
            cout<<"Address :: "<<address<<endl;
            cout<<"Description :: "<<description<<endl<<endl;
        }
        getline(file,phoneNo,',');
        getline(file,name,',');
        getline(file,address,',');
        getline(file,description,'\n');
    }
    file.close();
}