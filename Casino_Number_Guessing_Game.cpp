#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void introduction(string &username)
{
    cout<<"Welcome To Casino Royale \n";
    cout<<"What Is Your Full Name: ";
    getline(cin, username);

    cout<<endl<<"Your Current Balance Is $500 \n";
}

void play(string &username, int &userbalance, int &bet, int &dice, int &guess)
{
    cout<<endl<<"How Much Do You Want To Bet: ";
    cin>>bet;

    while(bet > userbalance)
    {
        if(bet <= userbalance)
        {
            cout<<"Your Bet Is Valid Please Proceed \n";
        }

        else
        {
            cout<<"Your Bet Is Greater Than Your Current Balance Please Try Again \n";
        }
    }
    
    dice = rand() % (6 - 1 + 1) + 1;

    cout<<endl<<"What Is Your Guess: ";
    cin>>guess;

    if(guess == dice)
    {
        userbalance += bet;
        cout<<"Your Current Balance Is "<<userbalance;
    }

    else
    {
        userbalance -= bet;
        cout<<"Your Current Balance Is "<<userbalance;
    }

}

int main()
{
    string username;
    int userbalance = 500; 
    int bet;
    int dice;
    int guess;

    srand(time(0));

    introduction(username);
    play(username, userbalance, bet, dice, guess);

    return 0;

}