#include <iostream>
#include <ctime>
using namespace std;
 
int genPile()
{
  int pile = rand() % (30 - 15 + 1) + 15;
  return pile;
}

int compDecision(int pile)
{
  int remove;

  if(pile == 1 || pile == 2)
  {
    remove = 1; 
  }

  else if(pile == 3)
  {
    remove = 2; 
  }

  else if(pile == 4)
  {
    remove = 3;
  }

  else
  {
    remove = rand() % (3 - 1 + 1) + 1; 
  }

  return remove; 
}

void adjustPile(int &lose, int &pile, int remove)
{
  pile = pile - remove;
 
  if(pile == 0)
  {
    cout<<"The pile is empty with its rocks & the game is lost";
    lose += 1;
  }
}

bool valid(int remove, int pile)
{
  if(remove < pile && remove >= 1 && remove <= 3)
  {
    return true; 
  }

  else
  {
    return false; 
  }
}

void turn(int player, int &pLose, int &cLose, int &pile, string person)
{
  int remove;
 
  if(player==1)
  {
    do{
        cout<<"How many rocks, "<<person;
        cin>>remove;
 
    
      }while(!valid(remove, pile));
 
      adjustPile(pLose, pile, remove);
  }
    
  else
  {
    remove = compDecision(pile);
 
    cout<<"Computer has removed"<<remove<<"rocks";
    
    adjustPile(cLose, pile, remove);
  }
}
 
bool gameOver(int pLose, int cLose)
{
  if(pLose >= 2 )
  {
    cout<<"You lost";
    return true;
  }
 
  else if(cLose >= 2)
  {
    cout<<"You Won";
    return false;
  }
 
  else
  {
    return false;
  }
}


int main()
{

    srand(time(0));
   	string person; 
 	   
   	cout<<"Welcome to the Game of Rocks!"<<endl;
   	cout<<"What is your name, human player (so I can know who I'm about to crush!)? ";
   	getline(cin, person);
    
    //create a random # of rocks between 15-30 for each of 3 piles
	  int pile1=genPile(); 
	  int pile2=genPile();
	  int pile3=genPile();

    //keep track of how many piles the player has lost
	  int pLose=0; 	

    //keep track of how many piles the computer has lost
    int cLose=0; 	

    //1=human player, 2=computer
    int player=2; 

	  //keep going until someone has lost at least 2 piles
	  do 
	  {
		  system("clear");

		  //switch between players before start of next turn
		  if(player==1)
      {
        player++;
      } 
		  else
      {
        player--;
      }

		  //if the pile still has rocks, turn proceeds
		  if(pile1 > 0)
		  {
			  //output current number in pile
			  cout<<"# Rocks in Pile 1: "<<pile1<<endl; 
			  //play a single turn on this pile
			  turn(player,pLose,cLose, pile1, person); 
		  }
		  
      if(pile2 > 0)
		  {
			  cout<<"# Rocks in Pile 2: "<<pile2<<endl;
			  turn(player, pLose,cLose,pile2, person);
		  }
		  
      if(pile3 > 0)
		  {
			  cout<<"#Rocks in Pile 3:"<<pile3<<endl;
			  turn(player,pLose,cLose,pile3, person);
		  }

		  //pause so human can see computer moves
		  cout<<"Hit enter to continue."<<endl;
	   	cin.get();


    //continues so long as no one has lost 2 piles
    }while(!gameOver(pLose,cLose)); 

	  return 0;
}
