#ifndef UNO_GAMEFLOW_H
#define UNO_GAMEFLOW_H
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include "Card.h"
#include "Player.h"

/**
 * Halts program flow for n milliseconds.
 * @param milliseconds Amount of milliseconds to sleep for.
 */
void sleep(int milliseconds);

/**
 * Animates printing to terminal as if it is being typed out.
 * @param text Text to print out.
 */
void animatedPrint(std::string text);

/**
 * Prompts player to play/draw cards.
 * @param player The  person playing- not a bot.
 * @param cardInPlay The current card in play.
 */
void playerPlaySequence(Player &player, Card& cardInPlay);

/**
 * Play sequence for NPCs. Plays the first card in the hand that works,
 * or draws until it gets a card that works.
 * @param player The player to do the play sequence on.
 * @param cardInPlay The current card in play.
 */
void botPlaySequence(Player &player, Card& cardInPlay);

/**
 * Implementation of the reverse card. Changes the player vector to the
 * reverse order, and shifted so that the player who played the reverse card
 * is at the back. Shifts the index so that it will be at 0 on the next iteration.
 * @param players Player vector to be reversed.
 * @param index Index of the player that played the reverse card.
 */
void reverse_players(std::vector<Player> &players, int &index);


#endif //UNO_GAMEFLOW_H
