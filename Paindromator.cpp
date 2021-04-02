#include <iostream>
using namespace std;

//Creates a function called Numerate that makes the input cleaned up 
string Numerate(string &input, string &copy_input)
{
  //Runs a for loop over the entire input length being a string entered by the user in main
  for(int i = 0; i < input.length(); i++)
  {
    //If any part of the user's input is a letter it makes it lower case and adds that string to a the first copy
    if(isalpha(input.at(i)))
    {
      input.at(i) = tolower(input.at(i));
      copy_input += input.at(i); 
    }
  }

  //Returns the copy input string 
  return copy_input; 
}

//This Clean function reverses the letters from copy input to the reverse string variable and adds it to the reverse string for future use
void Clean(string &input, string &copy_input, string &reverse)
{
  for(int i = copy_input.length() - 1; i >= 0; i--)
  {
    //This lines at the the letters from copyinput to reverse string variable 
    reverse += copy_input.at(i);
  }

}

//This Check function checks if the copy input equals the reverse string aka if it is a palindrome 
void Check(string &input, string &copy_input, string &reverse)
{
  //If copy input is equal to reverse it is a palindrome and outputs it to the user 
  if(copy_input == reverse)
  {
    cout<<endl<<"Yes! "<<input<<" is a palindrome";
  }

  //Else it is not a palidnrome and outputs it to the user 
  else
  {
    cout<<endl<<"No, "<<input<<" is a palindrome";
  }
}

//This function PlayAgain asks the user for a option to play again and returns a boolean 
bool PlayAgain()
{
    //Creates the char variable to store the user's choice
    char option;

    //Asks the user if they want to check for another palindrome
    cout<<endl<<"Check another: ";
    cin>>option;

    //Uses the function cin ignore to organize from the asking the user in main for their text 
    cin.ignore();

    //If the user enters in a y or Y it changes to lower case and returns true meaning yes they want to check another 
    if(tolower(option) == 'y')
    {
        return true; 
    }

    //Else it is assumed that they don't want to and it exits the program 
    else
    {
        return false;
    }
}

int main(){

  //Creates the three variables to store the users text all in string type 
  string input;
  string copy_input;
  string reverse;

  //While loop keeps running the palindrome checking program for the user as long as the function PlayAgain returns true everytime 
  do{
      cout<<endl<<"Please enter text to check for palindrome: ";
      getline(cin, input);
      Numerate(input, copy_input);
      Clean(input, copy_input, reverse);
      Check(input, copy_input, reverse);

  }while(PlayAgain() == true);
}