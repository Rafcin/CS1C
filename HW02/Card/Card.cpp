//
// Created by raf on 6/9/21.
//

#include "Card.h"
Card::Card(Rank rank, Suit suit) {
    m_rank = rank;
    m_suit = suit;
}

Rank Card::getRank() {
    return m_rank;
}

Suit Card::getSuit() {
    return m_suit;
}

char* Card::getSuitSymbol() {
    switch (m_suit) {
        case Suit::CLUBS: return "♣";
            break;
        case Suit::DIAMONDS: return "♦";
            break;
        case Suit::HEARTS: return "♥";
            break;
        case Suit::SPADES: return "♠";
            break;
    }
}

//Don't judge me... I hate I wrote it this way...
//ACE = 1, TWO=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK=11, QUEEN=12, KING=13
char* Card::getRankSymbol() {
    switch (m_rank) {
        case Rank::ACE: return "01";
            break;
        case Rank::TWO: return "02";
            break;
        case Rank::THREE: return "03";
            break;
        case Rank::FOUR: return "04";
            break;
        case Rank::FIVE: return "05";
            break;
        case Rank::SIX: return "06";
            break;
        case Rank::SEVEN: return "07";
            break;
        case Rank::EIGHT: return "08";
            break;
        case Rank::NINE: return "09";
            break;
        case Rank::TEN: return "10";
            break;
        case Rank::JACK: return "11";
            break;
        case Rank::QUEEN: return "12";
            break;
        case Rank::KING: return "13";
            break;
    }
}