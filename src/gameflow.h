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

void playerPlaySequence(Player &player, Card& cardInPlay);

void botPlaySequence(Player &player, Card& cardInPlay);

#endif //UNO_GAMEFLOW_H
