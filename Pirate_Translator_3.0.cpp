#include <iostream>
#include <vector>
#include <ctime> 
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
          //Whatever after the english/pirate word is found in the phrase
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
}

void arrr(string &phrase)
{
  //Creates two variables the index found3 to find the punctuation and the string add that adds "Arrr!"
  int found3 = -1;
  string add = "Arrr!";
  
  //A do while loop that keeps running as long as the index found3 is never equal to -1
  do{
    //Creates a random number either 0 or 1 to check after each sentence to add "Arrr!" (50% chance)
    int rand_num = rand() % (1 - 0 + 1) + 0;

    //The index is equal to finding punctuation of . or ! or ? starting at index 0
    found3 = phrase.find_first_of(".!?", found3 + 1);
    //If the random number is a 1 
    if(rand_num == 1)
    {
      //Then add the string add with "Arrr!" in replace of the punctuation in the sentence
      if(found3 != -1)
      {
        phrase=phrase.substr(0, found3)+ add + phrase.substr(found3 + 1);
        //Add the index of the found postion in the phrase to length of "Arrr!"
        found3 += add.length();
      }
    }
  }while(found3 != -1);
}
 
int main() {

  srand(time(0));
 
  //Local variables in main to be used as parameters for function and user input
  string english;
  string pirate; 
  string phrase;
  vector<string>english_words = {"hello", "friend", "madam", "officer", "stranger", "where", "is", "the", "my", "your", "restaurant", "hotel", "money"};
  vector<string>pirate_words = {"ahoy", "matey", "proud beauty", "foul blaggart", "scurvy dog", "whar", "be", "th'", "me", "yer", "galley", "fleabag inn", "booty"};
 
  //Asks the user for their phrase and collects it 
  cout<<endl<<"Enter your phrase: ";
  getline(cin, phrase);
 
  //Runs a for loop over all 13 english to pirate equal words/phrases
  //x < 13 or x <= 12 for the index 
  for(int x = 0; x <= 12; x++)
  {
    //Sets the english and pirate word parameters in the Replace function equal to the vector index of all phrases and words
    english = english_words[x];
    pirate = pirate_words[x];
    
    //Sets phrase equal to the Replace function for the first run
    phrase = Replace(english, pirate, phrase);
    //Calls the uncfirst function to convert lower to upper case of english and pirate strings 
    uncfirst(english, pirate);
    //Sets phrase equal to the Replace function for the second run 
    phrase = Replace(english, pirate, phrase);
  }
  
  //Calls the arr phrase before printing the pirate phrase to check for punctuation and replace it with "Arrr!"
  arrr(phrase);
 
  //Prints the final pirate version of the phrase 
  cout<<endl<<"Pirate Version: "<<phrase; 
}