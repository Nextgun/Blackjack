#include <iostream>
#include <iomanip>

using namespace std;


struct Card{
    char suit;
    char value;
    string display;

};

// Our Classes for Blackjack
class Player
{
    private:
        string name;
        int numCards;
        Card hand[15];              // Array that hold the player's hand
        int total = 0;                  // Total value of the cards
        double moneyAmt;                // total available money - current bet
        double betAmt;                  // money taken from total for current round of Blackjack
    public:
        string getName(){return name;}
        void printHand();
        double getMoneyAmt(){return moneyAmt;}
        double getBetAmt(){return betAmt;}
        void dealOneCard(Card[]);
        void placeBet();                // Function 2 -	how much you gonna bet?
        bool checkHand();               // Function 7 -	check if bust;
                                        // calculates value of the hand, checks for a bust or win.

};

void Player::printHand()
{
    for(int count = 0; count < numCards; count++)
    {
        cout << hand[count].display << ", ";
    }
}

void Player::dealOneCard(Card deck[])
{
    int i;
    srand(time(NULL));
    do{
        i = rand() % 52;
    }while(deck[i].suit == 0);

    hand[numCards] = deck[i];
    deck[i] = {0,'0',"0"};
    switch(hand[numCards].value){
        case '2': total += 2;
        break;
        case '3': total += 3;
        break;
        case '4': total += 4;
        break;
        case '5': total += 5;
        break;
        case '6': total += 6;
        break;
        case '7': total += 7;
        break;
        case '8': total += 8;
        break;
        case '9': total += 9;
        break;
        case 'X':
        case 'J':
        case 'Q':
        case 'K': total += 10;
        break;
    }
    numCards++;



}

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
bool Player::checkHand()
{
    if (total >= 21)
        return true;
    else return false;
}

class Dealer
{
    private:
        string name = "Dealer";
        int numCards;
        Card hand[15];              //the dealer's hand
        int total;                  // the total value of the dealer's hand
        int countHiddenCard = 1;    // keep track so that dealers second card remains hidden
    public:
        string getName(){return name;}
        void printHand();
        void dealcards(int numPlayer);  // Function 3 -	deal cards (note: have a counter so when second card dealt, make it  face  down for the dealers hand)
        void dealOneCard();
        void revealHiddenCard();
        bool checkHand();           // Function 7 -	check if bust;
                                    // calculates value of the hand, checks for a bust or win.
        void setDeck();          // calculates value of the hand, checks for a bust or win.
        Card deck[52];              // The deck

};

void Dealer::printHand()
{
    for(int count = 0; count < numCards; count++)
    {
        cout << setw(25) << hand[count].display << ", ";
    }
    cout << endl;
}

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
    int i;
    srand(time(NULL));
    do{
        i = rand() % 52;
    }while(deck[i].suit == 0);

    hand[numCards] = deck[i];
    deck[i] = {0,'0',"0"};
    switch(hand[numCards].value){
        case '2': total += 2;
        break;
        case '3': total += 3;
        break;
        case '4': total += 4;
        break;
        case '5': total += 5;
        break;
        case '6': total += 6;
        break;
        case '7': total += 7;
        break;
        case '8': total += 8;
        break;
        case '9': total += 9;
        break;
        case '10':
        case 'J':
        case 'Q':
        case 'K': total += 10;
        break;
    }
    numCards++;

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
bool Dealer::checkHand()
{
    if (total >= 21)
        return true;
    else return false;
}

// Function Prototypes
//
void printBoardState(Dealer dealer, Player player1, Player player2, Player player3, Player player4); //Function 1 - print board state (use iomanip + setw)

//
int main()
{

    // title screen code

    // gameplay code
    int numOfPlayers = 4;

    // default 4 players
    // initialize
    Player playerList[numOfPlayers];


    Dealer theDealer;               // The games dealer (comp)


    printBoardState(theDealer, playerList[0], playerList[1], playerList[2], playerList[3]);


    // variable creation
    char playAgain;


    // start game loop
    do
    {
        // write game code here
        for(int count = 0; count < numOfPlayers; count++)
        {
            // ask for name
            // ask for bet
        }

      //  while ()    // maybe doesnt even need a loop tbh
      //  {
            //draw board
            // dealer deals 2 cards each

            for(int count = 0; count < numOfPlayers; count++)
            {
                // ask for hit or stand
                // call function for bust or win
            }

            // dealer reveals second card
            // calc bust or win
            // calc money earned or lost
     //   }


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
void printBoardState(Dealer dealer, Player player1, Player player2, Player player3, Player player4)  // parameters will include 5 objects
{
    // code here
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(25) << dealer.getName() << endl;
    dealer.printHand();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(10) << player1.getName() << setw(10) << player2.getName()
         << setw(10) << player3.getName() << setw(10) << player4.getName() << endl;

   player1.printHand();
   player2.printHand();
   player3.printHand();
   player4.printHand();
//    << setw(10) << player2.printHand()
//         << setw(10) << player3.printHand() << setw(10) << player4.printHand() << endl;

    cout << setw(10) << player1.getMoneyAmt() << "," << player1.getBetAmt()
         << setw(10) << player2.getMoneyAmt() << "," << player2.getBetAmt()
         << setw(10) << player3.getMoneyAmt() << "," << player3.getBetAmt()
         << setw(10) << player4.getMoneyAmt() << "," << player4.getBetAmt() << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}


// write function header, include which team member wrote it.
// Author:
void drawEnd()
{
    // draw end screen
}
