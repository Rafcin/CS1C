//
// Created by raf on 6/9/21.
//

#ifndef HW02_CARD_H
#define HW02_CARD_H

/**
 * @name Card
 * @brief Card class for basic playing cards. This class contains no adjustments for different card games and
 * simply contains the basic ranks for a deck.
 *
 * @public Card, getRank, getSuit, getSuitSymbol, getRankSymbol
 * @private suit, rank
 *
 */
enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
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
