//
// Created by raf on 6/9/21.
//

#include "Deck.h"
#include <iostream>
#include <cassert>

// Deck Size 52 | 13 per suit (4)
/**
 * @name Deck Constructor
 * @brief setups the deck, takes no params and initalizes the 52 cards in the deck.
 *
 *
 *
 * Funfact: If you ever look at Valves old Source2 code you'll find plenty of comments that just say "turn this bug
 * into a feature".
 */
Deck::Deck() {
    Suit s = Suit::CLUBS;
    Rank r = Rank::ACE;
    for (int i = 0; i < numberOfSuits; i++) {
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
        for (int j = 1; j <= numberOfRanks; j++) {
            Card* n = new Card(static_cast<Rank>(j), s);
            deck.push_back(n);
        }
    }
    assert(deck.size() == deckSize);
}

Deck::~Deck() {
    deck.clear();
}

//https://giphy.com/gifs/xU9TT471DTGJq
//https://www.cplusplus.com/reference/cassert/assert/
//https://www.cplusplus.com/reference/vector/vector/erase/ - Erase single or range.
/**
 * @name Shuffle
 * @param NA
 * @brief shuffle splits the deck, does a size check and shuffles a perfect shuffle.
 *
 * I hate how I wrote this, I could have just used copy but it doesn't matter.
 * 1. The split size of the deck is defined by taking the length of the vector and / 2. 52/2 = 26.
 * 2. Assert says "Hey is the inverse of the split the same length of the vector?" If it is the pass otherwise
 * exit and stop. Don't really need this but it was late so why the hell not, at some point all my code will just be filled with asserts.
 * 3. We set the start and end to to deck.start and end to half the deck.
 * 4. Now while the end + 1 so 27 in this case is not equal to the end of the deck we use move_backwards to weave the array.
 * *Note* I could technically do this:
 *      vector shuffled;
 *      int pos = 1;
 *      for(size_t i = 0; i < 26; i++)
 *          int r = deck[26+i];
 *          // last + index
 *          //remove start to 26 + current index.
 *          deck.erase(deck.start + 26 + i);
 *          //insert the start of the deck to end
 *          deck.insert(deck.start + pos, r);
 *          //inc pos on each loop
 *          pos +- 2;
 * but I hate this. I mean I tested a version of this but it sucks, move_backwards just works, I don't often use it maybe the last time was ROS or for the Matrix
 * project but I just hate having to see loops that are pre defined, re-usability is key and clean code is key, I looked back at the Matrix project and for the
 * determinant I had nested loops. Also this does a lot of copying and I hate it, at least with move backwards its rotating it and doing less copies if i'm right.
 */
void Deck::shuffle() {
    //Split deck size/2
    auto const split = deck.size() / 2;
    //Check is inverse equal to deck size | exit
    assert(split * 2 == deck.size());
    //start
    auto s = deck.begin()+1;
    //end
    /*
     * Whoever invented auto is genius. I don't have to specify shit, it just deduces this based on the
     * initialization expression!
     */
    auto e = deck.begin()+split;
    //Start+1 not equal to end do:
    while (e+1 != deck.end()) {
        Card* temp = *e;
        std::move_backward(s, e, e+1);
        *s = temp;
        //after :D
        ++e;
        s += 2;
    }
}

//compares current to target deck. Returns 0 or 1
bool Deck::compare(std::vector<Card*> targ) {
    //I know using equal is eh but it exists and I must use it.
    return std::equal(deck.begin(), deck.end(), targ.begin());
}

//Why... what the fuck was I thinking.
/**
 *
 * This print was pointless but pointless stuff is fun.
 * I created the shape and then getSuitSymbol and getRankSymbol just return strings as I want them.
 * For the rank instead of 1,2,3...10 it's 01, 02, 03, 04... 10 to fit in the card and not cause this overflow with the borders.
 */
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
