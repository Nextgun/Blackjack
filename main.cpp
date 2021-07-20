#include <iostream>

using namespace std;

// Function Prototypes
//
// Function 1 - print board state (use iomanip + setw)

//

// Our Classes for Blackjack
class Player
{
    private:
        string name;
        string cards[15];           // Array that hold the cards
        double moneyAmt;            // total available money - current bet
        double betAmt;              // money taken from total for current round of Blackjack
    public:
        void placeBet();            // Function 2 -	how much you gonna bet?
        void checkHand();           // Function 7 -	check if bust;
                                    // calculates value of the hand, checks for a bust or win.

};

//*******************************************************
// placeBet                                             *
// will take money from the total money pool,           *
// and store it in the betAmt attribute                 *
//*******************************************************
void Player::placeBet()
{
    // write code for function
}

//*******************************************************
// checkHand                                            *
// will calculate value of hand and                     *
// determine if a bust, a win, or nothing happened      *
//*******************************************************
void Player::checkHand()
{
    // write code for function
}

class Dealer
{
    private:
        string cards[15];
        int countHiddenCard = 1;    // keep track so that dealers second card remains hidden
    public:
        void dealcards(int numPlayer);  // Function 3 -	deal cards (note: have a counter so when second card dealt, make it  face  down for the dealers hand)
        void dealOneCard();
        void revealHiddenCard();
        void checkHand();           // Function 7 -	check if bust;
                                    // calculates value of the hand, checks for a bust or win.

};

//*******************************************************
// dealcards                                            *
// will deal 1 card to each person in the game          *
//*******************************************************

void Dealer::dealcards(int numPlayer)
{
    for (int count = 0; count < numPlayer; count++)
    {
        // write code to deal one card per player

        // call function to print board after each player gets a new card
    }

    if (countHiddenCard == 2)
    {
        // add 2nd as ## so its hidden
    }

    countHiddenCard++;
}

//*******************************************************
// dealOneCard                                          *
// will deal 1 card to one person                       *
//*******************************************************
void Dealer::dealOneCard()
{
    // write code for function
}

//*******************************************************
// revealHiddenCard                                     *
// will take away the card ##,                          *
// and deal a new random card                           *
//*******************************************************
void Dealer::revealHiddenCard()
{
    // write code for function
}

//*******************************************************
// checkHand                                            *
// will calculate value of hand and                     *
// determine if a bust, a win, or nothing happened      *
//*******************************************************
void Dealer::checkHand()
{
    // write code for function
}


int main()
{
    // title screen code

    // gameplay code

    // default 4 players
    // initialize
    Player player1;
    Player player2;
    Player player3;
    Player player4;
    // make player list a vector (i think)
    // use pointers to create players, pass by pointer, dynamically create
    // gonna need everyones help on it -hector

    Dealer theDealer;               // The games dealer (comp)

    // variable creation
    char playAgain;


    // start game loop
    do
    {
        // write game code here

        // ask to play again
        cout << "Would you like to play again? (Type 'Y' for yes, anything else to close.) " << endl;
        cin >> playAgain;
    }while(tolower(playAgain) == 'y');



    // end screen code

    return 0;
}

// write function header, include which team member wrote it.
// Author: Sawan
void drawTitle()
{
    char userinput;                     // used to start game
    // all inside a do while loop
    do
    {
        // copy sawans function here

        // ask for input
        cout << "input 'P' to play the game, anything else will do nothing";
        cin >> userinput;
        // run input validation // ?maybe idk -hector

    }while(tolower(userinput) != 'p');
}

// write function header, include which team member wrote it.
// Author:
void drawBoard()
{
    // write code here
}
