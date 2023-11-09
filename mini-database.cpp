#include <iostream>
#include <fstream>
#include <string.h>
#include <climits>
#include <windows.h>

using namespace std;

class Base{
public:
void crefil()
        {
            system("cls");
            string fname,message;
            cout<<"\n Enter file name: ";
            cin>>fname;

            cin.ignore(INT_MAX,'\n');

            cout<<"Enter the file data: ";
            getline(cin,message);

            ofstream fout(fname);
            fout<<message;
            fout.close();
        }
        void reafil()
        {
            system("cls");
            string fname,str;
            cout<<"\nEnter file name: ";
            cin>>fname;

            ifstream fin(fname);
            while(!fin.eof())
            {
                fin>>str;
                cout<<str<<" ";
            }
            cout<<"\n \n"<<endl;
            fin.close();
        }
        void edifil()
        {
            system("cls");
            string fname,message;
            cout<<"\n Enter file name: ";
            cin>>fname;

            cin.ignore(INT_MAX,'\n');

            cout<<"Enter the file data: ";
            getline(cin,message);

            ofstream fout(fname, ios::app);
            fout<<"\n"<<message;
            fout.close();
        }
        void logout()
        {
            system("cls");
            cout<<"********************logging out********************"<<endl;
            Sleep(1500);
            system("cls");
        }
        void def(){
            cout<<"\nSorry, wrong choice selected.\nEnter your choice again\n"<<endl;
            Sleep(1500);
            system("cls");
        }
        void newuse()
        {
            system("cls");
            string useid,usepass;
            cout<<"Enter the User ID: ";
            cin >> useid;
            cout<<"Enter the User Password: ";
            cin >> usepass;
            ofstream fout("login.txt", ios::app);
            fout<< useid << " " << usepass<<"\n"<<endl;
            fout.close();
        }
        void deluse()
        {
            system("cls");
        }
};

class user : Base
{
private:
        int choice; 
public:
        user()
        {
            // system("cls");
            cout<<"********************Login Successful********************\n";
            cout<<"1. Create New file \n2. Read existing file \n3. Edit a file \n4. Logout \n5. Exit";
            cout<<"\nEnter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:
                    crefil();
                    cll();
                    break;
                case 2:
                    reafil();
                    cll();
                    break;
                case 3:
                    edifil();
                    cll();
                    break;
                case 4:
                    logout();
                    break;
                case 5:
                    terminate();
                default:
                    def();
                    cll();
                    break;
            }
        }
        void cll(){
            user use;
        }
};

class sup_user : Base
{
private:
        int choice=0;

public:
        sup_user()
        {
            cout<<"********************Super User Account activated********************\n";
            cout<<"1. Create New file \n2. Read existing file \n3. Edit a file \n4. Create a new user \n5. Delete a user \n6. Logout \n7. Exit"<<endl;
            cout<<"\nEnter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                    crefil();
                    cll();
                    break;
                case 2:
                    reafil();
                    cll();
                    break;
                case 3:
                    edifil();
                    cll();
                    break;
                case 4:
                    newuse();
                    cll();
                    break;
                case 5:
                    deluse();
                    cll();
                    break;
                case 6:
                    logout();
                    break;
                case 7:
                    terminate();
                default:
                    def();
                    cll();
                    break;
            }
        }

        void cll(){
            sup_user su;
        }
};

int main()
{
    ifstream fin("login.txt", ios::in);
    char emid[50], pass[20], str[30];
    string suid="admin@gmail.com", supass="admin@123", u, p;

    cout<<"Welcome User, Please enter your credentials here\n";
    cout<<"Enter your email id: ";
    cin>>emid;
    cout<<"Enter your password: ";
    cin>>pass;

    if(emid==suid && pass==supass)
        {
            system("cls");
            sup_user su;
        }
    else
        while(fin>>u>>p)
        {   
            if(u == emid && p == pass)
            {
                system("cls");
                user us;
            }
            else
            {
                cout<<"Sorry, Wrong ID or Password\nPlease enter your details again"<<endl;
            }
        }

    cout<<"\n\n";
    fin.close();
    main();
}