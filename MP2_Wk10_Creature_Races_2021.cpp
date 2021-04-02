#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//Creates global variables used in printing the race itself like the racers and racetrack 
const string square ="💠";
const string flag ="🚩";
const string dash="▫️";
const string train = "🚂";
const string policecar = "🚓";
const string suv = "🚙";

//Creates a string vector with all three players to be used later on in the program 
const vector<string>players = {train, policecar, suv};

//This function printHelper prints the small sqaures for the two headings used to make code in SplashScreen more concise 
void printHelper()
{
  for(int i = 0; i < 20; i++)
  {
    cout<<square<<" ";
  }
}

//This function SplashScreen creates the racetrack and introduction for the user 
void SplashScreen()
{
  //Prints the first heading with a flag
  cout<<flag;

  //Calls the printHelper function to print the small sqaures used for the heading
  printHelper();

  //Prints the first heading with a flag
  cout<<flag<<endl;

  //Prints a little introduction screen for the user 
  cout<<"Welcome to the Races...";
  cout<<endl<<"Today's Competitors Include";

  //Prints the 3 racers and who they are aka emoji's
  cout<<endl<<train;
  cout<<endl<<policecar;
  cout<<endl<<suv;
  
  cout<<endl<<"Best of Luck to You in Today's Races!";

  //Prints the first heading with a flag
  cout<<endl<<flag;

  //Calls the printHelper function to print the small sqaures used for the heading
  printHelper();

}

//This function ShowLane has the purpose of printing the racetrack with the racers on it 
void ShowLane(int racerNum, int pos)
{
  
  cout<<endl<<flag;
  cout<<racerNum;
  
  //A small for loop that prints out the little dashes for the racers to be on when changing their postion either forward or same place 
  for(int x = 0; x < 10; x++)
  {
    //If the variable x aka the dash postion equals the players postion in the vector from RacerNum print the player with their emoji 
    if(x == pos)
    {
      cout<<players[racerNum];
    }

    //Else print those little dashes and a space to make code more organized 
    else 
    {
      cout<<dash<<"";
    }
  }
}
//This function VerifyBet makes sure the money that the user bet is valid and is legal based on their total 
bool VerifyBet(double total, double bet)
{
  //If the user's bet is greater than or equal to zero and is less than or equal to their total it's valid 
  if(bet >= 0 && bet <= total)
  {
    return true;
  }

  //If the conditons above aren't met by the user's bet it return's false which is a invalid bet 
  else 
  {
    return false;
  }
}


//This function VerifyRacer makes sure the user's racer choice is valid 
bool VerifyRacer(int racerChoice)
{
  //If the user's racerChoice is between 0 & 2 it's valid 
  if(racerChoice >= 0 && racerChoice <= 2)
  {
    return true;
  }

  //Else the user's racerChoice is not valid so it returns false
  else 
  {
    return false; 
  }
}

//This function MakeChoices asks the user for the bet and keeps asking until it;s valid same thing with selection of the racer, it calls VerifyBet & VerifyRacer to make sure it's valid all in two separate do while loops
void MakeChoices(double total, double &bet, int &racerChoice)
{
  do{
  cout<<"How much do you want to Bet? ";
  cin>>bet;
  }while(VerifyBet(total, bet) == false);

  do{
  cout<<"Choose a racer: ";
  cin>>racerChoice;
  VerifyRacer(racerChoice);
  }while(VerifyRacer(racerChoice) == false);
}

//This function creates a random number between 0 and 1 which is added to racer's postion for 0 stay in place or 1 move forward in the race
int ChangePositionBy()
{
  //Creates a integer random number variable between 0 and 1 
   int random_num = rand() % (1 - 0 + 1) + 1;

   //Returns it for future use in the program 
   return random_num;
}

//This function determineWinners counts the number of winners for the racers 
void determineWinners(int &numberWinners, string &listWinners, vector<int> &pos)
{
  //A small for loop that runs 3 times to check if the racer's postion is 10 which is the end of the race one win is added to them
  for(int a = 0; a < 3; a++)
  {
    if(pos[a] == 10)
    {
      numberWinners += 1; 
      //Stores the picture of what racer won and add's it to listWinners variable 
      listWinners += players[a];
    }
  }
}
//If parameter don't declare 
//This function CheckWin figures out the number of winners and the emoji's of the winners 
bool CheckWin(vector<int> &pos, double &total, double bet, int racerChoice)
{
  //Declares some of the variables in the parmeters to be used properly including numberWinners & listWinners
  int numberWinners = 0;
  string listWinners;

  //Calls the function determineWinners to figure out what racers won in order to then count the number of winners
  determineWinners(numberWinners,  listWinners, pos);

  //If at least one racer won the user wins and it is displayed as well adds the bet to total it returns true 
  if(numberWinners > 0)
  {
    return true; 
    cout<<"You won \n";
    total = total + bet;
  }

  //Else the user loses and their bet is subtracted from their total because they lost it also returns false 
  else
  {
    return false; 
    total = total - bet;
  }
}

//This function PlayAgain asks the user if they want to play the game again
bool PlayAgain()
{
    //Creates a char variable to store the userinput 
    char option;

    //Asks the user if they want to play yes or no and collects that information to the variable option 
    cout<<"Play again? y = yes/ n = no";
    cin>>option;

    //If the user's option is yes either y or Y it returns true 
    if(tolower(option) == 'y')
    {
        return true; 
    }

    //Else it is assumed as no so it returns false 
    else
    {
        return false;
    }
}

//This function wait to make a pause so user can see the race 
void Wait(double seconds)
{
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ; 
	while (clock() < endwait) {} 
}

int main()
{
  //Fancy function from the libary ctime to make all numbers random as possible 
  srand(time(0));

  //Declares some variables in main as local so it can be used as parameters in the functions above 
  int racerNum = 0;
  int racerChoice;
  double total = 100;
  double bet;
  int random_num;
  
  //Calling functions in main in correct order 
//A do while loop that keeps doing the program as long as the user says yes to playagain 
do{
   vector<int>pos(3);
  SplashScreen();
  MakeChoices(total, bet, racerChoice);
  //This do while loop is making sure the racers are moving with the functons showLane & changePosition with the random number
  do{
  for(int b = 0; b <pos.size(); b++ )
  {
    ShowLane(b, pos[b]);
    
    pos[b]+=ChangePositionBy();
  } 
  cout<<endl;
  //Wait function is called to create a pause of 0.2 seconds to let the user see the race 
  Wait(0.2);
  //System clear wipes the screen to make it look animated 
  system("clear");
  
  //While loop keeps running as long as the function CheckWin is equal to false 
  }while(CheckWin(pos, total, bet, racerChoice) == false);

//Keeps running as long as playagain function is called and ran either true or false 
}while(PlayAgain());
}



