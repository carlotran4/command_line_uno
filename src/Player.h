#ifndef _player_
#define _player_

#include "Card.h"
#include <vector>
#include <iostream>
#include <string>

struct Player{
    std::vector<Card> hand;
    std::string name;
    bool inGame = true;

    /**
     * Initializes a Player object with seven random cards in its hand
     * and named n.
     * @param n Name of the Player object.
     */
    Player(std::string n);

    /**
     * Adds no_cards cards into the Player's hand
     * @param no_cards Number of cards to draw.
     */
    void draw(int no_cards);

    /**
     * Returns a string representation of the Player's data.
     *
     * @param toSelf If true, will print the cards that are in
     * the player's hands. Otherwise will just print the number of cards.
     */
    std::string to_string(bool toSelf);

    /**
     * Removes a card from the player's hand.
     * @param cardNo index+1 of the card in the hand.
     * @return The card that was played.
     */
    Card play_card(int cardNo);

    /**
     * return most prevalent color in hand
     */
    std::string most_freq_color();
};

#endif //_player_