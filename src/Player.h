#ifndef _player_
#define _player_

#include "Card.h"
#include <vector>
#include <iostream>
#include <string>

struct Player{
    std::vector<Card> hand;
    std::string name;
    bool is_alive = true;

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
     * Prints the cards in the players hand, with a corresponding number.
     * Ex. 1 [Yellow 2]   2 [Blue 5]
     */
    void print_hand();

    /**
     * Prints "Name has n cards"
     */
    void print_hand_to_others();

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

#endif //player