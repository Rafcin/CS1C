//
// Created by raf on 6/9/21.
//

#ifndef HW02_CARD_H
#define HW02_CARD_H

enum class Rank { ACE = 1, TWO=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK=11, QUEEN=12, KING=13 };
enum class Suit { CLUBS=1, DIAMONDS=2, HEARTS=3, SPADES=4 };
class Card {
private:
    Suit m_suit;
    Rank m_rank;
public:
    Card();
    Card(Rank, Suit);
    Rank getRank();
    Suit getSuit();
    char* getSuitSymbol();
    char* getRankSymbol();
};


#endif //HW02_CARD_H
