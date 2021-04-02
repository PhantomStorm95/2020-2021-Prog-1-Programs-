#include <iostream>
using namespace std;
 
string Replace(string &english, string &pirate, string &phrase)
{
  //Creates the two string variables to separate the pirate word from other parts of the phrase
  string before;
  string after;
  //Creates a integer index called found
  int found = -1;
    
  do{
   //Tries to find the english word starting in the phrase and the certain index in the do while loop
   found = phrase.find(english , found + 1);
   //If it finds the first index of the english word 
   if(found != -1)
   {
     //Creates a second integer index called found2 
     int found2;
 
     //The before the phrase it labels the index between 0 and the where it finds the start of the index of the english word
     before = phrase.substr(0, found);
     //Found2 variables is reset to now equal to the index after the english word's last letter 
     found2 = phrase.length() - found - english.length() + 1; 
     //The after string is set the found2 + 1 index up to the entire phrase length 
     after = phrase.substr(found2 + 1, phrase.length());
     //phrase = pc before + pirate + pc after the word
     
     //The new pirate phrase is now before + pirate + after all string concatnation  
     phrase = before + pirate + after; 
   }
 }while(found != -1);
 //Do while keeps running until found the index isn't equal to -1 
 
 //Prints the pirate version of the phrase and returns it 
 cout<<endl<<"Pirate Version: "<<phrase; 
 return phrase; 
}
 
int main() {
 
  //Variables in main for collecting userinput to be used as parameters
  string english;
  string pirate; 
  string phrase;
  
  //Asks the user for the english word in the phrase to swap and collects it 
  cout<<"Enter an English word to swap: ";
  cin>>english;
  
  //Asks the user for the pirate word to replace the english word in the phrase and collects it
  cout<<endl<<"Enter a Pirate replacement word: ";
  cin>>pirate;
  
  //Fancy function called cin.ignore() to organize userinput between cin and getline 
  cin.ignore(); 
  
  //Asks the user for their entire phrase and collects it 
  cout<<endl<<"Enter your phrase: ";
  getline(cin, phrase);
  
  //Calls the function Replace to run the program it is shown above 
  Replace(english, pirate, phrase);
}

