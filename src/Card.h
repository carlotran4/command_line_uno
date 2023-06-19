#ifndef _card_
#define _card_

#include <iostream>
#include <string>
#include <vector>
#include <experimental/random>

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
     * @param color_in_play Current color of card in play.
     * @param symbol_in_play Current symbol of card in play.
     * @return True if card is valid to play, false otherwise.
     */
    bool is_valid_play(std::string color_in_play, std::string symbol_in_play);

    bool is_valid_play(Card& card);

    std::string to_string();

    private:
        std::vector<std::string> colors = {"Red","Blue","Green","Yellow"};
};


//TODO: deprecate
/**
 * Prints the color and symbol of a card
 * @param os std::cout.
 * @param item Card to Print
 * @return
 */
std::ostream & print(std::ostream &os, const Card &item);

#endif //_card_