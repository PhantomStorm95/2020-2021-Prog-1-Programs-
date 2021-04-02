#include <iostream>
using namespace std; 

int genPile()
{
  int pile = rand() % (30 - 15 + 1) + 15;

  return pile;
}

void adjustPile(bool &lose, int &pile, int remove)
{
  pile = pile - remove;

  if(pile == 0)
  {
    cout<<"The pile is empty with its rocks & the game is lost";
    lose = true;
  }
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
