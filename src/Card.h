#ifndef _card_
#define _card_

#include <iostream>
#include <string>
#include <vector>
#include <random>

struct Card{
    std::string color;
    std::string symbol;
    /**
     * Constructs a card following the probability distribution of a
     * 112 card uno deck.
     */
    Card();

    /**
     * Tests if the card is a valid play.
     * @param card Current card in play.
     * @return True if card is valid to play, false otherwise.
     */
    bool is_valid_play(Card& card);

    /**
     * @return Returns a string representation of a card. Ex. Red 2
     */
    std::string to_string();

    private:
        std::vector<std::string> colors = {"Red","Blue","Green","Yellow"};
};

/**
 * Generates an integer within [lower,upper].
 * @param lower - lower bound. Inclusive.
 * @param upper - upper bound. Inclusive.
*/
int randint(int lower, int upper);

#endif //_card_