//Scared Donkey Program Souvik Kar Period 4 Petr 
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main(){

  //A function from the library <ctime> to make the donkey movements as random as possible 
  srand(time(0));

  //Variables 
  //Userinput for things like operating the menu or typing length of the bridge 
  int input;
  int input2;
  //A boolean statement that helps run the the while loop for the donkey when it moves 
  bool donkey_end = false;
  //A boolean statement that helps for figuring out the highest & lowest steps in the 50 trials when using if statements 
  bool first_trial = true;
  //A variable that is the starting point for the donkey so halfway in the bridge 
  double start_pt = 0.0;
  //A variable that counts the number of steps after a single trial
  int step_counter = 0;
  //A variable that counts each number of steps for each trial out of 50 when the user selects option 2 from the menu 
  int total_steps = 0;
  //A variable that stores the integer 50 for the 50 trials when the user selects option 2 from the menu also having it as a variable to acess and modify later on
  int howManyTimes = 3;
  //Two int variables that store the greatest and lowest number of steps for when option 2 for after the 50 trials are completed, I abbreviated to save time hopefully you understand 
  int lsteps = 0;
  int hsteps = 0;

  //1st main while loop will keep running as long as the user never types 3 in that case the program exits 
  while(input != 3)
  {
    //Prints out a menu of options for the user to read and asks the user for input number 1-3
    cout<<"\n"<<"1 - View single simulation \n";
    cout<<"2 - Run statistics over trials \n";
    cout<<"3 - Quit \n";
    cin>>input;

    //If the user types in 1 for input for the menu options
    if(input == 1)
    {
      //Asks the user for the length of the bridge and collects that input for future use 
      cout<<"How long is the bridge: ";
      cin>>input2;

      //The halfway point on the bridge for the donkey is calculated by taking the bridge length dividing by 2 then rounding it 
      start_pt = lround(input2 / 2.0);

      //2nd while loop will run as long as the boolean donkey_end is false this while loop is responsible for moving the donkey until it reaches until it passes the end of the bridge 
      while(donkey_end == false)
      { 
        //Creates a random number between 0 - 1 for moving the donkey left or right 
        int moves = rand() % 2;

        //Creates the Step number then prints out currently where the donkey is in * form with the ends of the bridge 
        cout.width(input2 + 2 + 7);
        cout<<"\nStep "<<step_counter<<":"<<"|";

        cout.width(start_pt);
        cout<<"*";
        cout.width(input2-start_pt);
        cout<<" ";
        cout<<"|";

        //If the random number is 0 the donkey will move one space to the left 
        if(moves == 0)
        {
          start_pt = start_pt - 1;
        }

        //Else the random number is 1 the donkey will move one space to the right
        else
        {
          start_pt = start_pt + 1;
        }

        //If statement to check if the donkey as passed the ends of either gates to where the stepcounter ends and it prints out a final bridge with no donkey on it 
        if(start_pt <= 0 || (start_pt >= input2))
        {
          cout<<"\nStep "<<step_counter + 1<<":"<<"|";
          for(int x = 1; x <= input2; x++)
          {
            cout<<" ";
          }
          cout<<"|";
          //The boolean donkey_end is true so the while loop will end
          donkey_end = true;
        }

        //Each donekey step is added to the stepcounter to be displayed at the end 
        step_counter++;
      }

      //A simple print statement that prints the total steps taken for the donkey 
      cout<<"\n"<<"Total Steps Taken: "<<step_counter;

      //Reseting the variables to be used for the next time the user input is 1 
      donkey_end = false; 
      start_pt = 0.0;
      step_counter = 0;
    }

    //If the user types in 2 for input for the menu options
    else if(input == 2)
    {
      //Asks the user for the length of the bridge and collects that input for future use 
      cout<<"How long is the bridge: ";
      cin>>input2;

      //The halfway point on the bridge for the donkey is calculated by taking the bridge length dividing by 2 then rounding it
      start_pt = lround(input2 / 2.0);

      //A main for loop that runs 50 trials for the donkey 
      for(int y = 1; y <= howManyTimes; y++)
      {
        //A while loop that runs as long as the boolean donkey_end is false this while loop is responsible for moving the donkey until it reaches until it passes the end of the bridge, donkey_end is used again to not create another boolean 
        while(donkey_end == false)
        {
          //Creates a random number between 0 - 1 for moving the donkey left or right 
          int moves = rand() % 2;

          //If the random number is 0 the donkey will move one space to the left and a step is added to stepcounter
          if(moves == 0)
          {
            start_pt = start_pt - 1;
            step_counter++;
          } 

          ////Else the random number is 1 the donkey will move one space to the right and a step is added to stepcounter
          else
          {
            start_pt = start_pt + 1;
            step_counter++;
          } 

          //If the donkey reaches past the end of either the left or right side of the bridge 
          if(start_pt <= 0 || (start_pt >= input2))
          {
            donkey_end = true;
          }
        } 
        
        //This variable total_steps keeps adding the steps after a trial until all 50 are completed for future use
        total_steps = total_steps + step_counter;

        //If the first_trial is true the greatest and fewest steps are the first trial's stepcounter then the boolean becomes false
        if(first_trial == true)
        {
          hsteps = step_counter;
          lsteps = step_counter;
          first_trial = false;
        }

        //This else statement with mini if statements keeps testing for the lowest and highest amount of steps and replaces it if the condition is met 
        else
        {
          if(step_counter < lsteps)
          {
            lsteps = step_counter;
          }

          if(step_counter > hsteps)
          {
            hsteps = step_counter;
          }
        }

        //Reseting variables to be used for the next time
        step_counter=0;
        donkey_end = false;
        start_pt = lround(input2 / 2.0);
      }

      //Prints out three statistics over the 50 trials 
      cout<<"\n"<<"Statistics Over 50 Trials:";
      //For printing out average steps it rounds the total_steps after all 50 trials and divides by howManyTimes being = 50
      cout<<"\n"<<"Average steps: "<< lround(total_steps / howManyTimes);
      cout<<"\n"<<"Greatest # Steps Taken: "<<hsteps;
      cout<<"\n"<<"Fewest # Steps Taken: "<<lsteps<<"\n";
    }

    //If the user types in 3 for the menu options the program exits hence return 0;
    else
    {
      return 0;
    }
  }
}