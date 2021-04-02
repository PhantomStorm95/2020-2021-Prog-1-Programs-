#include <iostream>
using namespace std;

int main(){

  bool valid(int remove, int pile)
  {
    
    if(remove < pile || remove >= 1 && remove <= 3)
    {
      return true; 
    }

    else
    {
      return false; 
    }
  }

  void turn(int player, bool &pLose, bool &cLose, int &pile, string person)
  {
      int remove;

      if(player==1)
      {
        do{
            cout<<"How many rocks, "<<person;
            cin>>remove;

      
          }while(!valid(remove, pile));

      
          adjustPile( pLose,  pile,  remove);
      }
      
      else
      {
        remove = compDecision(pile);

        cout<<"Computer has removed"<<remove<<"rocks";
      
        adjustPile(cLose, pile, remove);

      }
    }

    bool gameOver(bool pLose, bool cLose)
    {
      if(pLose==true )
      {
        cout<<"You lost";
        return true
      }

      else if(cLose == true)
      {
        cout<<"You Won";
        return true; 
      }

      else 
      {
        return false; 
      }
      
    }


  
    

}