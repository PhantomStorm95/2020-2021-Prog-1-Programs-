#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void dealerCards(int dealer_c, int dealer_c2)
{
    
    for(int i = 0; i < 1; i++)
    {
        dealer_c = rand() % (11 - 1 + 1) + 1;
        dealer_c2 = rand() % (11 - 1 + 1) + 1; 
    }

    cout<<dealer_c<<endl;
    cout<<dealer_c2;
}

void playerCards(int player_c, int player_c2)
{
    for(int x = 0; x < 1; x++)
    {
        player_c  = rand() % (11 - 1 + 1) + 1;
        player_c2 = rand() % (11 - 1 + 1) + 1;
    }

    cout<<endl<<player_c<<endl;
    cout<<player_c2;
}

void checkCards(int dealer_c, int dealer_c2, int player_c, int player_c2, int player_t, int dealer_t)
{
    //Add Both Dealer Cards
    dealer_t = dealer_c + dealer_c2;

    //Add Both Player Cards
    player_t = player_c + player_c2;

    //Conditions/Checking Both Dealer & Player Cards 
    if(dealer_t > 21 || player_t == 21 || player_t > dealer_t)
    {
        cout<<"Congrats You Win!"<<endl;
    }

    else if(dealer_t ==  player_t)
    {
        cout<<"Wow A Tie!"<<endl;
    }
    else
    {
        cout<<"Sorry You Lost Dealer Won, Good Luck Next Time!"<<endl; 
    }

}

int main()
{
    srand(time(0));

    //Global Variables? 
    int deal_cards;
    int deal_cards2;

    int player_cards;
    int player_cards2;

    int player_total;
    int dealer_total; 

    //Calling The Diffrent Functions To Execute BlackJack
    dealerCards(deal_cards, deal_cards2);
    playerCards(player_cards, player_cards2);
    checkCards(deal_cards, deal_cards2, player_cards, player_cards2, player_total, dealer_total);

    return 0;
}