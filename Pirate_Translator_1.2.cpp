#include <iostream>
using namespace std;

string Replace(string &english, string &pirate, string &phrase)
{
  //Creates local variables to be used in do while loop later on in the function 
  string before;
  string after;
  string look_pirate; 
  int found = -1;
  int found2;

  //A do while that keeps running as long as the int found never is equal to -1 as the index
  do{
      //Tries to find the english word starting in the phrase and the certain index in the do while loop
      found = phrase.find(english , found + 1);
      //If the index of the english word is found in the phrase 
      if(found != -1)
      {
        //Found 2 formula for the number of characters to add for the phrase.substr for looking for the english word to convert to pirate word
        found2 = found + english.length() -1 - found + 1;

        //Look_pirate is set to the starting index found and adds correct number of characters (found2)
        look_pirate = phrase.substr(found, found2);

        //If found the starting index of the english/pirate word is equal to 0 
        if(found == 0)
        {
          //Whatever after the english/pirate word is found using a formula and the fancy string function substr
          after = phrase.substr(found + found2, phrase.length());
          //Look_pirate is now set to the pirate word 
          look_pirate = pirate; 
          //Phrase is now look_pirate + after 
          phrase = look_pirate + after; 
        }

        //Else if its greater than 0 
        else if(found > 0)
        {
          //Phrase: I said hello my friend
          //Whatever is before the english/pirate word is found from 0 to found - 1
          before = phrase.substr(0, found - 1);
          //Whatver after the english/pirate word is found in the phrase
          after = phrase.substr(found + found2, phrase.length());
          //Look_pirate is now set to the pirate word 
          look_pirate = pirate; 
          //Phrase is now before + look_pirate + after with some spaces :)
          phrase = before + " " + look_pirate + " " + after;
        }
      }
 }while(found != -1);

 //cout<<endl<<"Pirate Version: "<<phrase; 
 //Returns the phrase outside the loop properly 
 return phrase; 
}

void uncfirst(string &english, string &pirate)
{
  //English word: hello to Hello 
  //Changes the first letter of the pirate and english string to uppercase
  english[0] = toupper(english[0]); 
  pirate[0] = toupper(pirate[0]); 

  //cout<<"Letter: "<<english.at(0);
}

int main() {

  //Local variables in main to be used as parameters for function and userinput
  string english;
  string pirate; 
  string phrase;
  string english2 ;
  string pirate2 ;

  //Asks the user for their phrase and collects it 
  cout<<endl<<"Enter your phrase: ";
  getline(cin, phrase);

  //Asks the user for their 1st english word to swap and collects it 
  cout<<endl<<"Enter 1st English word to swap: ";
  cin>>english;

  //Asks the user for their 1st pirate word and collects it 
  cout<<endl<<"Enter 1st Pirate replacement word: ";
  cin>>pirate;

  //Asks the user for their 2nd english word to swap and collects it 
  cout<<endl<<"Enter 2nd English word to swap: ";
  cin>>english2;

  //Asks the user for their 2nd pirate word and collects it 
  cout<<endl<<"Enter 2nd Pirate replacement word: ";
  cin>>pirate2;

  //Sets phrase equal to the Replace function for the 1st run 
  phrase = Replace(english, pirate, phrase);
  
  //Calls the uncfirst function to convert lower to upper case of english and pirate strings 
  uncfirst(english, pirate);

  phrase = Replace(english, pirate, phrase);

  //Sets the english and pirate string variables equal to the 2nd ones for use in Replace function 
  english = english2; 
  pirate = pirate2; 

  //Sets phrase equal to the Replace function and calls the function for a 2nd time 
  phrase = Replace(english, pirate, phrase);
  
  //Calls the uncfirst function to convert lower to upper case of english and pirate strings 
  uncfirst(english, pirate);

  phrase = Replace(english, pirate, phrase);

  //Prints the final pirate version of the phrase 
  cout<<endl<<"Pirate Version: "<<phrase;  
}