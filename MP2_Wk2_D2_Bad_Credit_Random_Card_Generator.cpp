//Bad Credit Random Credit Card Number Generator Souvik Kar Period 4 Petr 
#include <iostream>
#include <vector>
#include <math.h>
#include<ctime>

using namespace std;

int main(){

    //Variables 
    //A variable that stores the random credit card number for future use, here it is a global variable 
    long long CC;
    //Asking the user for some input into the program to produce some sort of output 
    int input;
    int input2;
    //Stores the number of digits in each specfic type of card because each of the three are diffrent
    int digits;
    int remaining_card_digits = 0;

    //1st While loop that keeps running as long as the input2 (which is when the program asks the user if they want to genrate a random credit card number again)
    while(input2 != 2)
    {
        srand(time(0)); //A fancy function that makes sure when the random credit card is made it is more random

        //User Menu for the user to read and follow directions
        cout<<"Type of card to generate: \n";
        cout<<"1 - AMEX \n";
        cout<<"2 - MasterCard \n";
        cout<<"3 - 13-digit Visa \n";
        cout<<"4 - 16-digit Visa \n";
        cin>>input;

        //This variable called start_card as a integer stores the 1st or 1st & 2nd digits of the selected credit card
        int start_card = 0;

        //If user selects a AMEX 
        if(input == 1)
        {
          //Total number of digits is 15
          digits =  15;
          //start_card is now a changed variable which produces a random number between 1 & 2
          start_card = rand() % (2) + 1;
          //If its a 1 the first two digits of the card become 3 and 4 from left to right 
          if(start_card == 1)
          {
            start_card = 34;
          }
          //Else if it's a 2 first two digits of the card become 3 and 7 from left to right 
          else 
          {
            start_card = 37;
          }
          remaining_card_digits = 2;
        }

        //If user selects a MasterCard
        else if(input == 2)
        {
          //Total number of digits now becomes 16 because of the diffrent type of card selected 
          digits = 16;
          //start_card is now changed again to producing a random number for the first two digits being from 51-55 since it's a MasterCard
          start_card = rand() % (55 - 51 + 1) + 51;
          remaining_card_digits = 2;
        }

        //If user selects a Visa with 13 digits
        else if(input == 3)
        {
          //Total number of digits now becomes 13 because of the diffrent type of card selected 
          digits = 13;
          //start_card doesn't need a random number generator for the first digit of a Visa because its only one digit you guessed it 4
          start_card = 4;
          remaining_card_digits = 1;
        }
        
        //If user selects a Visa with 16 digits
        else if(input == 4)
        {
          //Total number of digits now becomes 16 because there is a another form of Visa with 16 digits :)
          digits = 16;
          //start_card doesn't need a random number generator for the first digit of a Visa because its only one digit you guessed it 4
          start_card = 4;
          remaining_card_digits = 1;
        }

        //Creates a vector which stores the indivudal digits 
        vector<int>CC_check(digits);

        //A boolean variable that stores the condtion false for use in the while loop parmeter for it to run 
        bool CC_found = false;
        //2nd while loop will run as long as the random credit card number is kept on being made and all the checks are made then the boolean will become true
        while(CC_found == false) 
        {
        
        //This for loop is for generating the random digits of the rest of the selected credit card number 
        for(int i = 0; i < digits - remaining_card_digits ; i++)
        {
          CC = CC + ((rand() % 10) * (pow(10, i)));
        }
        
        //Now the variable CC keeps shifting the digits to the left to make the random credit card number complete 
        CC = (start_card * pow(10, digits - remaining_card_digits)) + CC;

        //Creates a new variable to store the last digit in the vector postion 
        int vector_postion = digits - 1;

        //This while loop inserts every digit of the random credit card number into the vector based on the index 
        while(CC > 0)
        {
          int rem = CC % 10;
          CC_check[vector_postion] = rem;
          vector_postion = vector_postion - 1;
          CC = (CC/10);
        }

        //These variables are used for the third check known as CheckSum to verify the random credit number made 
        int evenCheck = 0;
        int sumCheck = 0;

        //This for loop multiplies and adds the even digits starting with the second digit which is really index 1 and adds them up but has a condtion 
        for(int x = 1; x < digits - 1; x = x + 2)
        {
          evenCheck = CC_check[x] * 2;
          //If the digit is more than 9 it will separate the two digits and then add them together, ex- 10 would be (1 + 0)
          if (evenCheck > 9)  
          {
            evenCheck = 1 + (evenCheck - 10);
          }
          sumCheck = sumCheck + evenCheck;
        } 

        //This for loop will add the digits that weren't included in the first for loop so the odd digits
        for(int x = 0; x <= digits - 1; x = x + 2)
        {
          evenCheck = CC_check[x];
          sumCheck = sumCheck + evenCheck;
        }

        //A if statement that says if the last digit in sumCheck is 0 it is a legit random credit card for the selected type 
        if((sumCheck % 10) == 0) 
        {
          cout<<"Generated Card Number: "<<"\n";
          for(int i=0; i < CC_check.size(); i++)
          {
            //Prints out the full random credit card number 
          
            cout<<CC_check.at(i)<<" ";
            CC_found = true;
          }
        }
        }

        //Asks the user if they want to create another random credit card number for a type of card after the 1st one 
        cout<<"\n\n"<<"Again? 1=yes, 2=no";
        cin>>input2;

        //If the user enters the number 2 which is a no the program will exit 
        if(input2 == 2)
        {
          return 0;
        }

    }
}