#include <iostream>
#include "Deck/Deck.h"

int main() {
    Deck shuffleDeck;
    Deck randomDeck;
    shuffleDeck.shuffle();
    shuffleDeck.print();
    std::cout << shuffleDeck.compare(shuffleDeck.getDeck());
    return 0;
}
