//
// Created by raf on 6/9/21.
//

#ifndef HW02_DECK_H
#define HW02_DECK_H

#include <vector>
#include "../Card/Card.h"
class Deck {
private:
    std::vector<Card*> deck;
    //STANDARD DECK SIZE IS 52 13 Ranks, 4 Suits
    int numberOfRanks = 13;
    int numberOfSuits = 4;
public:
    Deck();
    ~Deck();

    const std::vector<Card *> getDeck() const;
    void setDeck(const std::vector<Card *> &deck);

    void shuffle();
    void print();
    bool compare(std::vector<Card*> targ);
};


#endif //HW02_DECK_H
