#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


class Card{
public:
    Card(){
    }

    Card(std::string xnumber, std::string xsuit, std::string xcolor){ //constructor that gives each member of this class a number, suit, and color
        number = xnumber;
        suit = xsuit;
        color = xcolor;
    }

    std::string getNumber() { //getter
        return number;
    }

    std::string getSuit() {
        return suit;
    }

    std::string getColor() {
        return color;
    }

    void setNumber(std::string newNumber) { //setter
        number = newNumber;
    }

    void setSuit(std::string newSuit) {
        suit = newSuit;
    }

    void setColor(std::string newColor) {
        color = newColor;
    }

private:
    std::string number;
    std::string suit;
    std::string color;
};

class Deck{
public:

    Deck(){ //constrctor that calls a private function in the class
        generateCards();
    }

    void shuffle(){
        srand(time(NULL));
        for(int i = 0; i < 100; i++){ //shuffles the deck 100 times by replacing one random card with another
            swapCards(rand() % 52, rand() % 52); //calls another private function
        }
    }

    void oneCard(){ //prints just one random card
        srand(time(NULL));
        int randomNumber = rand() % 52;
        std::cout << "Card(" << cards[randomNumber].getNumber() << ", " << cards[randomNumber].getSuit() << ", " << cards[randomNumber].getColor() << ")" << std::endl;
    }

    void printCards(){
        for(int i = 0; i < 52; i++){
            std::cout << "Card(" << cards[i].getNumber() << ", " << cards[i].getSuit() << ", " << cards[i].getColor() << ")" << std::endl;
        }
    }

    void generateCards() { //initializes 52 cards
        std::string number[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"}; //creates an array of numbers
        std::string suit[] = {"Spade", "Club", "Heart", "Diamond"}; //creates an array of suits
        std::string color[] = {"Black", "Black", "Red", "Red"}; //creates an array of colors, corresponds with above suits
        int cardIndex = 0; //wil increase and be used to initialize the 52 cards of the deck
        for(int numberIndex = 0; numberIndex < 13; numberIndex++){
            for (int suitColorIndex = 0; suitColorIndex < 4; suitColorIndex++){
                cards[cardIndex++] = Card(number[numberIndex], suit[suitColorIndex], color[suitColorIndex]); //makes each card
                }
            }
        }

private:

    Card cards[52];    // these are all cards in an Array

    void swapCards(int a, int b){ // swap cards between two positions. Valid input: numbers between 0 and 51
        Card temp = cards[a]; //temp is temporary storage for variable a
        cards[b] = cards[a];
        cards[a] = temp;
        //std::cout << "a = " << a << "b = " << b << std::endl; //was used to test if random was working
    }
};

std::string intro(){
    std::string userInput;
    std::cout << "Welcome to my card shuffler!" << std::endl;
    std::cout << "This cardshuffler includes a deck of 52 standard cards" << std::endl;
    std::cout << "To randomly shuffle the deck, enter 'shuffle'" << std::endl;
    std::cout << "To select one random card from the deck, enter 'random'" << std::endl;
    std::cout << "To see the deck as it is ordered, enter 'deck'" << std::endl;
    std::cout << "If you want to exit the program, enter 'exit'" << std::endl;
    std::cin >> userInput;
    return userInput;
    }

void decision(std::string userInput){
    Deck xDeck = Deck();
    if(userInput == "shuffle") {
        xDeck.shuffle();
        xDeck.printCards();
        }
    else if(userInput == "random"){
        xDeck.oneCard();
    }
    else if(userInput == "deck"){
        xDeck.generateCards();
        xDeck.printCards();
    }
    else{
    exit(1);
    }
}


int main(){

    Deck myDeck = Deck(); //don't have to generate the cards because it's a part of the constructor
    decision(intro());

    std::string playAgain;
    std::cout << "Would you like to play again? (yes or no)" << std::endl;
    std::cin >> playAgain;
    while(playAgain == "yes"){
        decision(intro());
        std::cout << "Would you like to play again? (yes or no)" << std::endl;
        std::cin >> playAgain;
    }
    return 0;
}


