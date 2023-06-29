#include "Player.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <experimental/algorithm>
#include "gameflow.h"

//TODO: Make main function more concise/easy to follow
//TODO: Make a README

int main(){
    animatedPrint("Welcome to Command Line Uno!!!\n");
    sleep(500);
    Player bot1 = Player("Bot 1");
    Player bot2 = Player("Bot 2");
    Player bot3 = Player("Bot 3");
    Player person = Player("You");
    std::vector<Player> players {bot1,bot2,bot3,person};
    std::experimental::shuffle(players.begin(), players.end());
    animatedPrint("Order:");
    for(Player p: players){
        if(p.name == players.back().name) animatedPrint(p.name+"\n");
        else animatedPrint(p.name+", ");
    }
    std::cout<<std::endl;

    Card cardInPlay = Card();
    //First card cannot be +4 or Wild.
    while(cardInPlay.symbol == "+4"||cardInPlay.symbol == "Wild"){
        cardInPlay = Card();
    }

    while(person.inGame && players.size()>1){
        for(int i = 0; i<players.size(); ++i){
            if(players[i].name == "You"){
                playerPlaySequence(players[i],cardInPlay);
            }
            else {
                botPlaySequence(players[i],cardInPlay);
            }

            //Check if player has won
            if(!players[i].inGame){
                animatedPrint(players[i].name + " Won!");
                sleep(3000);
                return 0;
            }

            if(cardInPlay.symbol == "Skip") {
                if(i<players.size()-1) i++;
                else (i = 0);
                animatedPrint(players[i].name+ " got skipped!\n");
            }
            if(cardInPlay.symbol == "Reverse") {
                reverse_players(players, i);
                animatedPrint("Reversal! The new order is: ");
                for(Player &p: players){
                    if(p.name == players.back().name) animatedPrint(p.name+"\n");
                    else animatedPrint(p.name+", ");
                }
            }

            //Avoid out of range errors for if the current player is the last one in the vector.
            if(cardInPlay.symbol == "+2" && i<players.size()-1){
                players[i + 1].draw(2);
                animatedPrint(players[i+1].name+" had to draw two cards!\n");
            }
            else if(cardInPlay.symbol == "+2"){
                players.front().draw(2);
                animatedPrint(players.front().name+" had to draw two cards!\n");
            }

            if(cardInPlay.symbol == "+4" && i<players.size()-1){
                players[i + 1].draw(4);
                animatedPrint(players[i + 1].name + " had to draw four cards!\n");
            }
            else if(cardInPlay.symbol == "+4"){
                players.front().draw(4);
                animatedPrint(players.front().name + " had to draw four cards!\n");
            }

            //color selection is the same for +4 and wild cards
            if(cardInPlay.symbol == "+4" || cardInPlay.symbol == "Wild"){
                if(players[i].name == "You"){
                    std::string color;
                    animatedPrint("Type the color you want (Yellow, Red, Green, Blue)\n");
                    std::cin>>color; cardInPlay.color = color;
                }
                else cardInPlay.color = players[i].most_freq_color();
                animatedPrint(players[i].name+" chose " + cardInPlay.color+"\n\n");
            }
        }
    }
}



