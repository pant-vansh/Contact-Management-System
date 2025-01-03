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
            cout<<"Emial  :: "<<email<<endl<<endl;
            cout<<"Description :: "<<description<<endl;
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
}