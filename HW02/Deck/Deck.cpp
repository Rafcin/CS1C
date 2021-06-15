//
// Created by raf on 6/9/21.
//

#include "Deck.h"
#include <iostream>
#include <cassert>

// Deck Size 52 | 13 per suit (4)
Deck::Deck() {
    Suit s = Suit::CLUBS;
    Rank r = Rank::ACE;
    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0: s = Suit::CLUBS;
                break;
            case 1: s = Suit::DIAMONDS;
                break;
            case 2: s = Suit::HEARTS;
                break;
            case 3: s = Suit::SPADES;
                break;
        }
        for (int j = 1; j <= 13; j++) {
            Card* n = new Card(static_cast<Rank>(j), s);
            deck.push_back(n);
        }
    }
}

Deck::~Deck() {
    deck.clear();
}

//https://giphy.com/gifs/xU9TT471DTGJq
//https://www.cplusplus.com/reference/cassert/assert/
void Deck::shuffle() {
    //Split deck size/2
    auto const split = deck.size() / 2;
    //Check is inverse equal to deck size | exit
    assert(split * 2 == deck.size());
    //start
    auto s = deck.begin()+1;
    //end
    auto e = deck.begin()+split;
    while (e+1 != deck.end()) {
        Card* temp = *e;
        std::move_backward(s, e, e+1);
        *s = temp;
        ++e;
        s += 2;
    }
}

//compares current to target deck. Returns 0 or 1
bool Deck::compare(std::vector<Card*> targ) {
    return std::equal(deck.begin(), deck.end(), targ.begin());
}

//Why... what the fuck was I thinking.
void Deck::print()
{
    for (unsigned int i = 0; i < deck.size(); i++) {
        std::cout << R"(
        ┌──────────┐
        )";
        std::cout<<"│ "<<deck[i]->getSuitSymbol()<<"        │";
        std::cout << R"(
        │          │
        )";
        std::cout<<"│    "<<deck[i]->getRankSymbol()<<"    │";
        std::cout << R"(
        │          │
        )";
        std::cout<<"│        "<<deck[i]->getSuitSymbol()<<" │";
        std::cout << R"(
        └──────────┘
        )";
    }
}

const std::vector<Card *> Deck::getDeck() const {
    return deck;
}

void Deck::setDeck(const std::vector<Card *> &deck) {
    Deck::deck = deck;
}
