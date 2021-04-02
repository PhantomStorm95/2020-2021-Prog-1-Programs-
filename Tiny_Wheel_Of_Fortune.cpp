#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//Creates two vectors for storing 4 answers and 4 categories to be chosen later on in the program 
const vector<string>answers = {"Tom Brady", "Dog", "Superman", "Cars"};
const vector<string>categories = {"Quarterback", "Animal", "Superhero", "Movie"};

//Function to check if a guesses is been guessed previously doesn't work needs time and help 
bool PreviouslyGuessed(char &guess, int &mistakes, string &all_guesses)
{
    //Creates a boolean variable to return true or false in the condtions below 
    bool local2; 
    
    //Another for loop is used to check the entire letters of guesses 
    for(int b = 0; b < all_guesses.length(); b++)
    {
        //If any position in the all_guesses variable equals the current guess that is a duplicate it returns true 
        if(all_guesses.at(b) == guess)
        {
            cout<<"Already guessed that one!";
            local2 = true;
        }

        //If not local2 bool is set to false
        else
        {
            local2 = false; 
        }
    }

    //Returns local2 variable 
    return local2; 
}

//Function for selecting the answer and category of the game so the user can know for refrence 
void setanswerAndCategory(int &random_num, vector<int>&random, string &answer, string &category)
{
  //Uses a for loop to set the answer and category to a random number up to 4 and uses that index to pick the parallel answer and category inside the two vectors 
  for(int index = 0; index<random.size(); index++)
  {
    answer = answers[random[index]];
    category = categories[random[index]];
  }
}

//String function creates a variable string which is the same length to the answer and it's converted into underscores
string hideanswer(string &answer)
{
 //Sets a new variable string length to the answer
 string length = answer;
 
 //For loop to run over the entire letters and the length of the answer
 for(int i = 0; i <answer.length(); i++)
 {
   //If the position of the letter from int i = 0 to it's length doesn't have a space in that letter change to a underscore for the length variable
   if(length.at(i) != ' ')
   {
     length.at(i) = '_';
   }
 }
  //Returns the string length
 return length;
}
 
bool vannaWhite(string &answer, char &guess, string &hiddenanswer, int &mistakes)
{
 //Creates a local boolean variable to judge the for loop below for if their guess was true or false
 bool local;
 
 //For loop for the program evaluating if the users guess is true or false for the entire length of the answer
 for(int x = 0; x < answer.length(); x++)
 {
   //If their guess meaning the letter they input is anywhere on the length of the answer
   if(guess == answer.at(x))
   {
     //set that spot in the hidden version to equal the letter to replace the underscore'
     hiddenanswer.at(x) = guess;
     //make the local variable true and also if this if statement happens the mistakes stays the same anywhere in the user guessing process
     local = true;
   }
 
   else
   {
     //else false and mistakes decreases by 1
     local =  false;
     mistakes -= 1;
   }
 }

 return local;
}
 
void showHidden(string &hiddenanswer, string &category)
{
 //Uses a for loop to print the hidden version of the answer with spaces for the characters of the answer when printing
 for(int y = 0; y < hiddenanswer.length(); y++)
 {
   cout<<hiddenanswer.at(y)<<" ";
 }
 //Prints a another space to keep game organized
 cout<<endl;
 //Prints the name of the category the user can guess from that specific category
 cout<<category;
}
 
//Function that asks the user for a letter in the char guess variable
char makeGuess(char &guess, int &mistakes, string &all_guesses)
{
 //Asks the user for their letter and collects that data inside the variable char guess
 cout<<endl<<"Letter: ";
 cin>>guess;

 all_guesses += guess;
 
 //Returns the letter to upper case
 return toupper(guess);

 //Calls function where guessing is made to check for duplicates but it doesn't work 
 PreviouslyGuessed(guess, mistakes, all_guesses);
}
 
int main() {

  srand(time(0));

 //Basic variables to be used as parameters for the functions above
 string all_guesses;
 string hiddenanswer;
 string answer;
 string category;
 char guess;
 int mistakes = 5;

 //Creates a random number to be the random index for the answer or category
 int random_num = rand() % 4;

 //Stores that random number inside a vector called random for use in the setanswerAndCategory function 
 vector<int>random = {random_num};
 
 //Question: How do I check if the user guesses all the letters and put that as a condition for the while loop
 //While loop runs the all of the functions as long as mistakes never reaches 0 still haven't figure out the second condition need help on that
 setanswerAndCategory(random_num, random, answer, category);
 hiddenanswer = hideanswer(answer);
 while(mistakes != 0 && hiddenanswer != answer)
 {
   //Question: Is this the right order for the functions to run the game
   showHidden(hiddenanswer, category);
   makeGuess(guess, mistakes, all_guesses);
   vannaWhite(answer, guess, hiddenanswer, mistakes);
 }
}