#include <iostream>
#include <ctime>
using namespace std;
 
//Creates a constant string variable to store the entire alphabet 
const string test_string = "abcdefghijklmnopqrstuvwxyz"; 
 
string Split(string &input, int &rand1, int &rand2, int &i)
{
    //Local variables for splitting the word into three portions for left, middle, right
    string left;
    string middle;
    string right; 
 
    //Creates the random number to find the size of the left chunk on how the text should be split
    rand1 = rand() % ((input.length() - 2) - 1 + 1) + 1;
    //Adds that number to the user's input and takes that chunk out and adds it to the string left
    left = input.substr(0, rand1);
    //cout<<endl<<left; 
  
    //middle
    //Creates the random number to find the size of the middle chunk on how the text should be split
    rand2 = rand() % ((input.length() - rand1-1) - 1 + 1) + 1;
    //Adds that number to the user's input and uses the function substr to take that chunk out with the current position of the left and how many letters to take and adds it to the string middle 
    middle = input.substr(rand1, rand2);
    //cout<<endl<<middle; 
 
    //right
    //Starts from the position of the middle string and goes to the end of the input length and adds it to the string variable right
    right = input.substr(rand1+rand2); 
    //cout<<endl<<right; 
 
    //right+middle+left
    //Adds right middle and left prints it out being the scrambled permutation with the number being the index i and returns it!
    cout<<endl<<"Permutation #"<<i<<" :"<<right + middle + left; 
    return right + middle + left; 
}
 
bool PlayAgain()
{
    //Creates the int variable to store the user's choice
    int option;
 
    //Asks the user if they want to scramble another word 
    cout<<endl<<"Again ? 1 = Yes, 2 = No: ";
    cin>>option;
 
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
 
int main() 
{
  srand(time(0));
 
  //Creates variables to be used as parameters in the functions above
  string input; 
  int rand1;
  int rand2; 
  int times;
  int input2; 
  int i; 
  int trials; 
  int size; 
  int a;
  int num_trials = 0; 
  
  //A do while loop that keeps scrambling words for the user as long as the Playagin function never returns false
  do{
      //Asks the user the number of times they want to shuffle their word or phrase and collects it inside a variable called times
      cout<<"How would you like to shuffle the phrase?";
      cout<<endl<<"1) Specify a number of times ";
      cout<<endl<<"2) Run some Trials";
      cin>>input2;
 
      if(input2 == 1)
      {
        //Asks the user the number of times they want to shuffle their word or phrase and collects it inside a variable called times
        cout<<"How many times would you like to shuffle the phrase? ";
        cin>>times; 
      
        cin.ignore(); 
      
        //Asks the user for their phrase and collects inside a string variable input
        cout<<endl<<"Enter the phrase to scramble: ";
        getline(cin, input);
 
        //A for loop that keeps printing the scrambled phrase for the number of times the variable 
        for(i = 1; i <= times; i++)
        {
          //Sets input the string the user types in their word in to the Split function to keep repeating over and over 
          input = Split(input, rand1, rand2, i);
        }
      }
 
      // A else statement to make the user shuffle the alphabet 
      else 
      {
        //Asks the user what size the want for the string and collects it 
        cout<<endl<<"What size of the string to test? ";
        cin>>size;
 
        //Asks the user how many trials they would like and collects it 
        cout<<endl<<"How many trials? ";
        cin>>trials; 
 
        //Creates a second string called input2 that stores the original string for the alphabet
        string input2;
 
        //Modifys the string input2 to go from 0 meaning letter a to the size entered by the user before and creates the string to be shuffled
        input2 = test_string.substr(0, size);
 
        //Prints that string to display to the user
        cout<<input2; 
        
        //Sets input as to input2 the string so it can be shuffled in the split function 
        input = input2; 
 
       //Sets the index i at 1 to start the first permutation 
       i = 1;
       //Runs a for loop starting at 1 for the integer a to the number of trials 
       for(a = 1; a <= trials; a++)
       {
         //Prints the number of the trial 
         cout<<endl<<"Trial: "<<a;
         do
          {
            //Sets input the string the user types in their word in to the Split function to keep repeating over and over 
            input = Split(input, rand1, rand2, i);
            //Keeps adding the index i by plus 1, i++
            i++;
            //Number of trials is added each time a permuation is done
            num_trials = num_trials + 1;  
            //While loop keeps running as long as the original string never equals the current string while it's being shuffled 
          }while(input != input2);
          //Resets the index i variable at 1
          i = 1; 
       }
       //Creates the integer variable avg_trials here because of the order outside the for loop to divide number of trials over the trials the user wants to run 
       int avg_trials = (num_trials / trials);
       //Displays the average number of permutations over the trials to reshuffle to the original word 
       cout<<endl<<"Average permutations required: "<<avg_trials;
      }
      //Program keeps running as long as the PlayAgain does not return false as a boolean 
    }while(PlayAgain() != false);
}

