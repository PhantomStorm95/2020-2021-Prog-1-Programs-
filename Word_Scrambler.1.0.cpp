#include <iostream>
#include <ctime>
using namespace std;
 
string Split(string &input, int &rand1, int &rand2, int &i)
{
    //Local variables for splitting the word into three portions for left, middle, right
    string left;
    string middle;
    string right; 
  
    //Creates the random number to find the size of the left chunk on how the text should be split
    rand1 = rand() % ((input.length() - 1) - 1 + 1) + 1;
    //Adds that number to the user's input and takes that chunk out and adds it to the string left
    left = input.substr(0, rand1);
    //cout<<endl<<left; 
  
 
    //middle
    //Creates the random number to find the size of the middle chunk on how the text should be split
    rand2 = rand() % ((input.length() - rand1) - 1 + 1) + 1;
    //Adds that number to the user's input and uses the function substr to take that chunk out with the current position of the left and how many letters to take and adds it to the string middle 
    middle = input.substr(rand1, rand2);
    //cout<<endl<<middle; 
 
    //right
    //Starts from the position of the middle string and goes to the end of the input length and adds it to the string variable right
    right = input.substr(rand2 + 2, input.length()); 
    //cout<<endl<<right; 
 
    //right+middle+left
    //Adds right middle and left prints it out being the scrambled permutation with the number being the index i and returns it!
    cout<<endl<<"Permutation #"<<i<<" :"<<right + middle + left; 
    return right + middle + left = input; 
}
 
bool PlayAgain()
{
    //Creates the int variable to store the user's choice
    int option;
 
    //Asks the user if they want to scramble another word 
    cout<<endl<<"Again ? 1 = Yes, 2 = No: ";
    cin>>option;
 
    //Uses the function cin ignore to organize from the asking the user in main for their text 
    cin.ignore();
 
    //If the user enters in a 1 the program runs again 
    if(option == 1)
    {
      cout<<endl; 
      return true; 
    }
 
    //Else it is assumed that they don't want to and it exits the program 
    else
    {
      cout<<endl<<"Goodbye";
      return false;
    }
}
 
int main() {
 
  //Creates variables to be used as parameters in the functions above
  string input; 
  int rand1;
  int rand2; 
  int times; 
  int i; 
  
  //A do while loop that keeps scrambling words for the user as long as the Playagin function never returns false
  do{
      //Asks the user the number of times they want to shuffle their word or phrase and collects it inside a variable called times
      cout<<"How many times would you like to shuffle the phrase? ";
      cin>>times; 
      
      //Uses a fancy function cin.ignore to organize userinput between two inputs for the user
      cin.ignore(); 
 
      //Asks the user for their phrase and collects inside a string variable input
      cout<<endl<<"Enter the phrase to scramble: ";
      getline(cin, input);
      //cin>>input; 
      
      //A for loop that keeps printing the scrambled phrase for the number of times the variable 
      for(i = 1; i <= times; i++)
      {
        //Sets input the string the user types in their word in to the Split function to keep repeating over and over 
        input = Split(input, rand1, rand2, i);
      }
 
  }while(PlayAgain() != false);
}