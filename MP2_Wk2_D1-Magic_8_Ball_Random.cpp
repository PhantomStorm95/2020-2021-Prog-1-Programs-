#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

//Magic 8 Ball Program Souvik Kar Programming 1 Petr Period 4
int main(){

  srand(time(0));

  int userinput;
  string userinput2;
  vector<string>responses={"Yes", "No", "Count On It", "May Be", "Ask Again", "No Doubt", "Absolutely", "Not Now", "Cannot Tell Now", "Very Likely"};

  cout<<"Welcome to Magic 8 Ball Simulator";

  while(userinput != 2)
  {
    cout<<endl<<endl<<"Select from options below:";
    cout<<endl<<"1) Ask your question";
    cout<<endl<<"2) Quit \n";
    cin>>userinput;
    cin.ignore();

    if(userinput == 1)
    {
      cout<<"What is your question?: \n";
      getline(cin,userinput2);
      
      int r = rand() % 9;
      
      cout<<"The Magic 8 Ball Says: "<<responses[r]<<endl;
    }

    else
    {
      cout<<"Thanks for trusting Magic 8 Ball for all your important decisions!";
      return 0;
    }
  }
}