#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Card
{
    int value = 0;
    string face;
    string suit;
};

constexpr size_t DECK_SIZE = 54; // 13 * 4 + 2 jokers

Card* createStdDeck(Card deck[], size_t DECK_SIZE);
void displayDeck(Card deck[], size_t DECK_SIZE);
Card* shuffleDeck(Card deck[], size_t DECK_SIZE);

int main(){
    Card deck[DECK_SIZE];
    createStdDeck(deck, DECK_SIZE);
    cout << "Standard deck:\n";
    displayDeck(deck, DECK_SIZE);


    srand (time(NULL)); // srand()
    shuffleDeck(deck, DECK_SIZE);
    cout << "Shuffled deck:\n";
    displayDeck(deck, DECK_SIZE);
    return 0;
}

Card* createStdDeck(Card deck[], size_t DECK_SIZE){
    const string faces[] { "Ace", "Two",  "Three", "Four", "Five", "Six", "Seven",
                                 "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Joker" };
    const string suits[] { "Hearts", "Clubs",  "Diamonds", "Spades" };
    size_t cards = (DECK_SIZE - 2) / 4; // 13
    for(size_t i=0; i<cards; ++i) {
        deck[i].value = i + 1;
        deck[i].face = faces[i];
    }
    // Multiply x 4:
    for(int i=1; i<4; ++i) {copy(deck, deck+cards, deck+cards*i); }
    // Add 4 x 13 suits
    for(int i=0; i<4; ++i) {
        for(size_t j=0; j<cards; ++j) { deck[j+cards*i].suit = suits[i]; }
    }
    // Add jokers. Jokers value = 0.
    deck[DECK_SIZE -2].face = "Joker"; // deck[52]
    deck[DECK_SIZE -2].suit = "Black";
    deck[DECK_SIZE -1].face = "Joker";
    deck[DECK_SIZE -1].suit = "Red";
    return deck;
}

void displayDeck(Card deck[], size_t DECK_SIZE){
    for(size_t i=0; i<DECK_SIZE; ++i) {
        cout << "value: "  << setw(2) << deck[i].value
                  << "; face: "   <<setw(5) << deck[i].face
                  << "; suit: " <<setw(8) << deck[i].suit
                  << '\n';
    }
}

Card* shuffleDeck(Card deck[], size_t DECK_SIZE){
    random_shuffle(deck, deck + DECK_SIZE);
    return deck;
}
/*Најпрво декларирам структура Card која ги содржи функциите вредност, лице и костим. Потоа декларирам константа Големина на шпил, како и
функците крерање стандарден шпил, прикажување на шпилот карти и мешање на шпилот карти.
Во меин ја повикувам и функцијата srand(time(NULL)) koja користи при мешањето на шпилот - секоја карта да биде извлечена само еднаш.
Во функцијата Card* createStdDeck декларирам два стрингови (faces и suits) и декларирам size_t cards = 13 карти (секој костим има по 13 лица, без двата
џокери во шпилот). Преку For циклусот се доделува вредност на .value и .face (кои се членови на структурата Card) на првите 13 карти, а потоа преку следниот
for циклус истото се доделува и на останатите карти од трите костими, а со помош на следниот циклус се доделува и вредноста на suit на целиот шпил без двата Џокери.
А потоа се додаваат и двата Џокери.
На крај се печати целиот шпил по ред, а потоа и измешан*/
