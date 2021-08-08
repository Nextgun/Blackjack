#include <iostream>
#include <windows.h>            // only works for windows
#include <cstring>
#include <iomanip>
#include <cctype>
#include <stdlib.h>             // srand and rand for the random function
#include <ctime>                // to get system time for the random function

// never got this project to work so left it all in one big file.
//#include "dealerClass.cpp"
////#include "dealerClass.h"
//#include "playerClass.cpp"
////#include "playerClass.h"

using namespace std;

// Global variables
int const BIGSPACE = 25; //25;
int const SMALLSPACE = 10; //10;

struct Card{
    int value; // = 20;
    string display ;//= "20";
};

// Our Classes for Blackjack
class Player
{
    private:
        string name;
        int numCards;
        Card hand[15];                      // Array that hold the player's hand
        int total;                          // Total value of the cards
        double moneyAmt = 1000;             // total available money - current bet
        double betAmt = 0;                  // money taken from total for current round of Blackjack
    public:
        Player();                           // default constructor
        string getName(){return name;}
        int getTotal(){return total;}       // allows access to the private member total
        void changeName(int num);
        void printHand();
        double getMoneyAmt(){return moneyAmt;}
        void changeMoneyAmt(double newMoney){moneyAmt = newMoney;}
        double getBetAmt(){return betAmt;}
        void changeBetAmt(double newBet){betAmt = newBet;}
        int getNumCards(){return numCards;}
        void dealOneCard(Card[]);
        void setHand(Card[]);
        void placeBet();                    // Function 2 -	how much you gonna bet?
        bool checkHand();                   // Function 7 -	check if bust;
                                            // calculates value of the hand, checks for a bust or win.

};

void Player::setHand(Card deck[])
{
    for(int count = 0; count < numCards; count++)
    {
        hand[count] = deck[52];
    }
    numCards = 0;
    total = 0;
}

Player::Player()
{
    numCards = 0;
    total = 0;
}

void Player::printHand()
{
   // cout << left << setw(24);
    for(int count = 0; count < numCards; count++)
    {
        cout << hand[count].display << ", ";
    }
}

void Player::dealOneCard(Card deck[])
{
    int i;
    int choice;
    bool valid = false;
        // srand(time(NULL));
    do{
        // get random number
        i = (rand() % (52 - 1 + 1));// + 1;
        //i = rand() % 52;
    }while(deck[i].value == '0');

    hand[numCards] = deck[i];
    deck[i].value = '0';
    deck[i].display = "0";
    switch(hand[numCards].value){
        case '0': total += 0;
            break;
        case '1':
        while(! valid)
        { // repeat as long as the input is not valid
            cout << "Will this ace be a 1 or 11? " ;
            cin >> choice;
            if(cin.fail() || (choice != 1 && choice != 11))
            {
                cout << "Sorry, that was an invalid input. Please try again." << endl;

                // clear error flags
                cin.clear();
                // Wrong input remains on the stream, so you need to get rid of it
                cin.ignore(INT_MAX, '\n');
            }
            else
            {
                valid = true;

                 // clear error flags
                cin.clear();
                // Wrong input remains on the stream, so you need to get rid of it
                cin.ignore(INT_MAX, '\n');
            }
        }
            total += choice;
        break;
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
// changeName                                             *
// will take money from the total money pool,           *
// and store it in the betAmt attribute                 *
//*******************************************************
void Player::changeName(int num)
{
    string tempName;

    cout<<"Please enter the player name"<<endl;
    cout<<"Player " << num << " : ";
    getline(cin, tempName);

    name = tempName;
}

//*******************************************************
// placeBet                                             *
// will take money from the total money pool,           *
// and store it in the betAmt attribute                 *
//*******************************************************
void Player::placeBet()
{
    int tempBet;

    bool valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        cout << "Enter number: " ;
        cin >> tempBet;
        if(cin.fail())
        {
            cout << "Wrong input" << endl;

            // clear error flags
            cin.clear();
            // Wrong input remains on the stream, so you need to get rid of it
            cin.ignore(INT_MAX, '\n');
        }
        else if(tempBet < 2 || tempBet > 500 || tempBet > moneyAmt)
        {
            cout << "Sorry mate that not good enough. \n"
                 << "Enter a number from 2 to 500, and not more then your current money. "
                 << endl;
        }
        else
        {
            valid = true;

             // clear error flags
            cin.clear();
            // Wrong input remains on the stream, so you need to get rid of it
            cin.ignore(INT_MAX, '\n');
        }
    }
    betAmt = tempBet;
    moneyAmt -= betAmt;
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
        Card hand[15];                  //the dealer's hand
        int total;                      // the total value of the dealer's hand
        int countHiddenCard;            // keep track so that dealers second card remains hidden
    public:
        Dealer();                       //default constructor
        string getName(){return name;}
        int getTotal(){return total;}   // allows access to the private member total
        void printHand();
        void dealOneCard();
        int getNumCards(){return numCards;}
        bool checkHand();               // Function 7 -	check if bust;
        void setHand();                                // calculates value of the hand, checks for a bust or win.
        void setDeck();                 // calculates value of the hand, checks for a bust or win.
        Card deck[53];                  // The deck

};
Dealer::Dealer()
{
    numCards = 0;
    total = 0;
    countHiddenCard = 0;
}

void Dealer::setHand()
{
    for(int count = 0; count < numCards; count++)
    {
        hand[count] = deck[52];
    }
    numCards = 0;
    total = 0;
    countHiddenCard = 0;
}

void Dealer::printHand()
{
    cout << setw(BIGSPACE);
    for(int count = 0; count < 5; count++)
    {
        cout << setw(SMALLSPACE) << hand[count].display << ", ";
    }
    cout << "current total: " << total << endl;
    cout << endl;
}

//*******************************************************
// dealOneCard                                          *
// will deal 1 card to one person                       *
//*******************************************************
void Dealer::dealOneCard()
{
    int i;
    // srand(time(NULL));
    do{
        // get random number
        i = (rand() % (52 - 1 + 1));// + 1;
        //i = rand() % 52;
    }while(deck[i].value == '0');

    hand[numCards] = deck[i];
    if (countHiddenCard == 0 && numCards == 1)
    {
        hand[numCards] = deck[52];
//        countHiddenCard++;
//        numCards--;
    }
    deck[i].value = '0';
    deck[i].display = "0";
    switch(hand[numCards].value){
        case '0': total += 0;
            break;
        case '1':
            if (total + 11 <= 21)
                total += 11;
            else total += 1;
        break;
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
    if (countHiddenCard == 0 && numCards == 1)
    {
//        hand[numCards] = deck[52];
        countHiddenCard++;
        numCards--;
    }
    numCards++;
}

//*******************************************************
// checkHand                                            *
// will calculate value of hand and                     *
// determine if a bust, a win, or nothing happened      *
//*******************************************************
bool Dealer::checkHand()
{
    if (total >= 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//*******************************************************
// setDeck                                              *
// will set the contents of the deck to                 *
// include every single card                            *
//*******************************************************
void Dealer::setDeck(){
    Card deckOrder[53] = {
           {'1',"AC"},{'1',"AH"},{'1',"AS"},{'1',"AD"},
           {'2',"2C"},{'2',"2H"},{'2',"2S"},{'2',"2D"},
           {'3',"3C"},{'3',"3H"},{'3',"3S"},{'3',"3D"},
           {'4',"4C"},{'4',"4H"},{'4',"4S"},{'4',"4D"},
           {'5',"5C"},{'5',"5H"},{'5',"5S"},{'5',"5D"},
           {'6',"6C"},{'6',"6H"},{'6',"6S"},{'6',"6D"},
           {'7',"7C"},{'7',"7H"},{'7',"7S"},{'7',"7D"},
           {'8',"8C"},{'8',"8H"},{'8',"8S"},{'8',"8D"},
           {'9',"9C"},{'9',"9H"},{'9',"9S"},{'9',"9D"},
           {'X',"10C"},{'X',"10H"},{'X',"10S"},{'X',"10D"},
           {'J',"JC"},{'J',"JH"},{'J',"JS"},{'J',"JD"},
           {'Q',"QC"},{'Q',"QH"},{'Q',"QS"},{'Q',"QD"},
           {'K',"KC"},{'K',"KH"},{'K',"KS"},{'K',"KD"},
           {'0',"XX"}
                        };
    for(int i = 0; i < 53; i++){deck[i] = deckOrder[i];}
}

// Function Prototypes
void printBoardState(Dealer dealer, Player player[]); //Function 1 - print board state (use iomanip + setw)
void testdealcards(int numPlayer, Dealer dealer, Player player[], Card deck[]);
void drawTitle();
void endgame(Dealer dealer, Player players[]);

int main()
{
    // set up for our random numbers
    // Get the system time.
    unsigned seed = time(0);
    // Seed the random number generator.
    srand(seed);

    // Game-play code
    int numOfPlayers = 4;           // default 4 players

    // initialize our objects
    Player playerList[numOfPlayers];
    Dealer theDealer[numOfPlayers];               // The games dealer (comp)

    // variable creation for playing more rounds.
    char playAgain;

    drawTitle();
    printBoardState(theDealer[0], playerList);

    // get everyones name
    for(int count = 0; count < numOfPlayers; count++)
    {
        // ask for name
        playerList[count].changeName(count+1);
        Sleep(400); // pause
        printBoardState(theDealer[0], playerList);
    }

    // start game loop
    do
    {
        // title screen code

        Sleep(400); // pause
        printBoardState(theDealer[0], playerList);
        Sleep(400);// pause

        // write game code here
        theDealer[0].setDeck();            // set the deck / initialize the deck

        if(theDealer[0].getNumCards() > 0)// check if hand has cards
        {
            theDealer[0].setHand(); // initializes the dealer hand
        }
        for(int count = 0; count < numOfPlayers; count++)
        {
                if (playerList[count].getNumCards() > 0 )
                    playerList[count].setHand(theDealer[0].deck);// initializes the player hand
        }

        printBoardState(theDealer[0], playerList);

        for(int count = 0; count < numOfPlayers; count++)
        {
            // ask for bet
            playerList[count].placeBet();
            Sleep(400); // pause
            printBoardState(theDealer[0], playerList);
        }

        // dealer deals 2 cards each
        theDealer[0].dealOneCard();
        printBoardState(theDealer[0], playerList);
        Sleep(400); // pause

        theDealer[0].dealOneCard(); // hidden card
        printBoardState(theDealer[0], playerList);
        Sleep(400); // pause

        testdealcards(numOfPlayers,theDealer[0], playerList, theDealer[0].deck);

        printBoardState(theDealer[0], playerList);

        for(int count = 0; count < numOfPlayers; count++)
        {
            // ask for hit or stand
            // call function for bust or win
            char tempAns;
            while(playerList[count].checkHand() == false)
            {
                printBoardState(theDealer[0],playerList);
                Sleep(400);

                cout << "Player name: " << playerList[count].getName() << endl;
                cout << "Do you want to Hit (H) or Stand (S) ? " << endl;
                cin >> tempAns;
                Sleep(400);

                while(tolower(tempAns) != 'h' && tolower(tempAns) != 's')
                {
                    cout << "Invalid Input, Please try again. " << endl;
                    cout << "Player name: " << playerList[count].getName() << endl;
                    cout << "Do you want to Hit (H) or Stand (S) ? " << endl;
                    cin >> tempAns;
                    Sleep(400);
                }

                if (tolower(tempAns) == 'h')
                {
                    playerList[count].dealOneCard(theDealer[0].deck);
                }
                else if (tolower(tempAns) == 's')
                {
                    break;          // test to double check if it breaks out of thee while loop or not
                }

            }           // while the player has not busted loop
        }

        Sleep(1400);
        theDealer[0].dealOneCard();     // card 3, should replace hidden                    // dealer reveals second card
        printBoardState(theDealer[0],playerList);           // print screen to see hidden card
        Sleep(400);

        while(theDealer[0].getTotal() <=16)
        {
            cout<< "Since the dealer has less then 17, he gets another card. " << endl;
            Sleep(2000);
            theDealer[0].dealOneCard();              // card 4           // dealer reveals second card
            printBoardState(theDealer[0],playerList);
            Sleep(400);
        }
//        if(theDealer[0].getTotal() <=16)
//        {
//            cout<< "Since the dealer has less then 17, he gets another card. " << endl;
//            Sleep(2000);
//            theDealer[0].dealOneCard();              // card 4           // dealer reveals second card
//            printBoardState(theDealer[0],playerList);
//            Sleep(400);
//        }
//        if(theDealer[0].getTotal() <=16)
//        {
//            cout<< "Since the dealer has less then 17, he gets another card. " << endl;
//            Sleep(2000);
//            theDealer[0].dealOneCard();              // card 4           // dealer reveals second card
//            printBoardState(theDealer[0],playerList);
//            Sleep(400);
//        }

        printBoardState(theDealer[0],playerList);
        endgame(theDealer[0],playerList);                                       // draw and perform all of end game.

        // ask to play again
        cout << "Would you like to play again? (Type 'Y' for yes, anything else to close.) " << endl;
        cin >> playAgain;
        Sleep(400);
    }while(tolower(playAgain) == 'y');
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
        system("CLS");

        cout<<"--------------------------------------------------------------------------------------------------"<<endl;
        cout<<"|    $$$$$$$   $$         $$$$$$    $$$$$$   $$    $$     $$$$$   $$$$$$    $$$$$$   $$    $$    |"<<endl;
        cout<<"|    $$    $$  $$        $$    $$  $$    $$  $$   $$         $$  $$    $$  $$    $$  $$   $$     |"<<endl;
        cout<<"|    $$    $$  $$        $$    $$  $$        $$  $$          $$  $$    $$  $$        $$  $$      |"<<endl;
        cout<<"|    $$$$$$$   $$        $$$$$$$$  $$        $$$$            $$  $$$$$$$$  $$        $$$$        |"<<endl;
        cout<<"|    $$    $$  $$        $$    $$  $$        $$  $$    $$    $$  $$    $$  $$        $$  $$      |"<<endl;
        cout<<"|    $$    $$  $$        $$    $$  $$    $$  $$   $$   $$    $$  $$    $$  $$    $$  $$   $$     |"<<endl;
        cout<<"|    $$$$$$$   $$$$$$$$  $$    $$   $$$$$$   $$    $$   $$$$$$   $$    $$   $$$$$$   $$    $$    |"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<endl;

        // ask for input
        cout << "Enter Y to play game: " << endl;
        cin >> userinput;
        cin.ignore();
    }while(tolower(userinput) != 'y');
}

// write function header, include which team member wrote it.
// Author:
void printBoardState(Dealer dealer, Player player[])  // parameters will include 5 objects
{
    system("CLS");      // clears the terminal
    int tempVari = 0;
    int tempVari2 = 0;
    int tempVari3 = 0;

    cout << endl;
    cout << endl;
    cout << setw(BIGSPACE) << dealer.getName() << endl;
    dealer.printHand();
    cout << endl;
    cout << endl;
    cout << endl;

    cout<<player[0].getName()<<"\t\t\t"
        <<player[1].getName()<<"\t\t\t"
        <<player[2].getName()<<"\t\t\t"
        <<player[3].getName()<<endl;

    cout<< "total: " << player[0].getTotal()<<"\t\t"
        << "total: " << player[1].getTotal()<<"\t\t"
        << "total: " << player[2].getTotal()<<"\t\t"
        << "total: " << player[3].getTotal()<<endl;

    player[0].printHand();

   tempVari = 26 - (player[0].getNumCards() * 4);
   cout  << setw(tempVari);
    player[1].printHand();

   tempVari2 = 26 - (player[1].getNumCards() * 4);
   cout  << setw(tempVari2);
    player[2].printHand();

   tempVari3 = 26 - (player[2].getNumCards() * 4);
   cout  << setw(tempVari3);
    player[3].printHand();

    cout << endl;

    cout<< right << setw(4) <<player[0].getMoneyAmt() << ", " << setw(4) << player[0].getBetAmt()<<"\t\t"
        << setw(4) <<player[1].getMoneyAmt() << ", " << setw(4) << player[1].getBetAmt()<<"\t\t"
        << setw(4) <<player[2].getMoneyAmt() << ", " << setw(4) << player[2].getBetAmt()<<"\t\t"
        << setw(4) <<player[3].getMoneyAmt() << ", " << setw(4) << player[3].getBetAmt()<<endl;

}

void testdealcards(int numPlayer, Dealer dealer, Player player[], Card deck[])
{
        player[0].dealOneCard(deck);
        printBoardState(dealer, player);
        Sleep(400); // pause

        player[1].dealOneCard(deck);
        printBoardState(dealer, player);
        Sleep(400); // pause

        player[2].dealOneCard(deck);
        printBoardState(dealer, player);
        Sleep(400); // pause

        player[3].dealOneCard(deck);
        printBoardState(dealer, player);
        Sleep(700);// pause

        player[0].dealOneCard(deck);
        printBoardState(dealer, player);
        Sleep(400); // pause

        player[1].dealOneCard(deck);
        printBoardState(dealer, player);
        Sleep(400); // pause

        player[2].dealOneCard(deck);
        printBoardState(dealer, player);
        Sleep(400); // pause

        player[3].dealOneCard(deck);
        printBoardState(dealer, player);
        Sleep(400); // pause
}


void endgame(Dealer dealer, Player players[])
{
    int tempVari;
    cout << endl;
    for (int count = 0; count < 4; count++)
    {

        // if player busted
        if(players[count].getTotal()>21)
        {
            //printBoardState(dealer,players);

            cout<<"Player name: " << players[count].getName() << endl;
            cout<<"You busted. You are out of the game."<<endl;
            cout<<"You loose your bet"<<endl;

            players[count].changeBetAmt(0);
            cout << endl;

            Sleep(400);
        }

        // if the player ties with the dealer
        else if(players[count].getTotal() == dealer.getTotal())
        {
            //printBoardState(dealer,players);

            cout<<"Player name: " << players[count].getName() << endl;
            cout<<"You are done for the round."<<endl;
            cout<<players[count].getName() << ", You tied, so your bet has been returned to you.";

            tempVari = players[count].getMoneyAmt() + (players[count].getBetAmt());
            players[count].changeMoneyAmt(tempVari);
            players[count].changeBetAmt(0);
            cout << endl;

            Sleep(400);
        }

        // if player got 21, a blackjack
        else if(players[count].getTotal() == 21 && players[count].getNumCards() == 2)
        {
            //printBoardState(dealer,players);

            cout<<"Player name: " << players[count].getName() << endl;
            cout<<"You are done for the round."<<endl;
            cout<<players[count].getName() << ", you won $"<<(players[count].getBetAmt()*1.5)<<endl;

            tempVari = players[count].getMoneyAmt() + (players[count].getBetAmt() * 2.5);
            players[count].changeMoneyAmt(tempVari);
            players[count].changeBetAmt(0);
            cout << endl;

            Sleep(400);
        }
        // if player won the round
        else if (players[count].getTotal() > dealer.getTotal() || dealer.getTotal() > 21)
        {
            //printBoardState(dealer,players);

            cout<<"Player name: " << players[count].getName() << endl;
            cout<<"Yay! You won twice the bet."<<endl;
            cout<<"You won $"<<players[count].getBetAmt()*2<<endl;

            tempVari = players[count].getMoneyAmt() + (players[count].getBetAmt() * 2);
            players[count].changeMoneyAmt(tempVari);
            players[count].changeBetAmt(0);
            cout << endl;

            Sleep(400);
        }
        // if player lost the round
        else
        {
            //printBoardState(dealer,players);

            cout<<"Player name: " << players[count].getName() << endl;
            cout << "You lost! " << endl;
            cout << "You loose the bet. " << endl;

            players[count].changeBetAmt(0);
            cout << endl;

            Sleep(400);
        }
        Sleep(3000);
        printBoardState(dealer, players);
    }
}
