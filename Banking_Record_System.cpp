#include <iostream>
#include <cmath>

using namespace std;

void add_record(int &num, string &f_name, string &l_name, int &bal)
{
    cout<<"\n"<<"Enter Account Number: ";
    cin>>num;

    cout<<"Enter First Name: ";
    cin>>f_name;

    cout<<"Enter Last Name: ";
    cin>>l_name;

    cout<<"Enter Balance: ";
    cin>>bal;
}


void show_data(int num, string f_name, string l_name, int bal)
{
  cout<<"Account Number: "<<num<<endl;
  cout<<"First Name: "<<f_name<<endl;
  cout<<"Last Name: "<<l_name<<endl;
  cout<<"Current Balance: "<<bal<<endl;
}

void update_data(int num, string f_name, string l_name, int bal)
{
    cout<<"Your Current Account Data Is: \n";
    cout<<"1. Account Number: "<<num<<endl;
    cout<<"2. First Name: "<<f_name<<endl;
    cout<<"3. Last Name: "<<l_name<<endl;
    cout<<"4. Current Balance: "<<bal<<endl;

    int input2;
    cout<<"What Type Of Data Would You Like To Change: \n";
    cin>>input2;

    switch(input2)
    {
      case 1:
          cout<<"New Account Number: ";
          cin>>num;
          break;
      
      case 2:
          cout<<"New First Name: ";
          cin>>f_name;
          break;
      
      case 3: 
          cout<<"New Last Name: ";
          cin>>l_name;
          break;
      
      case 4: 
          cout<<"New Balance: ";
          cin>>bal;
          break;
    }
}

int main() {

    int input;
    int account_num;
    string first_name;
    string last_name;
    int balance;

    while(input != 6)
    {
      cout<<"\n"<<"***Account Information System***\n";
      cout<<"Select one option below \n";
      cout<<"1--> Add Record To File \n";
      cout<<"2--> Show Record From File \n";
      //cout<<"3--> Search Record From File \n";
      cout<<"4--> Update Record \n";
      cout<<"5--> Delete Record \n";
      cout<<"6--> Quit \n";
        
      cout<<"\n"<<"Enter Your Choice: ";
      cin>>input;

      if(input == 1)
      {
        add_record(account_num, first_name, last_name, balance);
      }

      else if(input == 2)
      {
        show_data(account_num, first_name, last_name, balance);
      }

      else
      {
        return 0;
      }

    }

    //return 0;

}