#include "Player.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <experimental/algorithm>
#include "gameflow.h"


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
    //First card cannot be +4 or Wild, because they do not have a default color.
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
                animatedPrint(players[i].name+ " got skipped!");
            }
            if(cardInPlay.symbol == "Reverse") {
                reverse(players.begin(), players.end());
                animatedPrint("Reversal! The new order is: ");
                for(Player p: players){
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

//int main(){
//    std::cout<< "Welcome to command line uno!"<<std::endl;
//    Player bot1 = Player("Bot 1");
//    Player bot2 = Player("Bot 2");
//    Player bot3 = Player("Bot 3");
//    Player person = Player("You");
//    std::vector<Player> players {bot1,bot2,bot3,person};
//    std::experimental::shuffle(players.begin(), players.end());
//    std::cout<<"ORDER: ";
//    for(Player p: players){
//        std::cout<<p.name<<", ";
//    }
//    std::cout<<"\n"<<std::endl;
//    std::cout<<"Your Cards"<<std::endl;
//    person.print_hand();
//
//    //Card in play.
//    Card current_card;
//    //Ensure first card is not Special card.
//    do{
//    current_card = Card();
//    } while (current_card.is_wild || current_card.is_plus_4);
//    std::cout<<"First card"<<std::endl;
//    print(std::cout,current_card);
//    std::cout<<std::endl;
//
//    //Begin game
//    while(players.size()>1 && person.inGame){
//        //iterator
//        int index = 0;
//        if(current_card.symbol == "reverse"){
//            reverse(players.begin(), players.end());
//            std::cout<<"New order: ";
//            for(Player p: players){
//            std::cout<<p.name<<", ";
//            }
//            std::cout<<std::endl;
//        }
//        for(Player &player: players){
//            if (current_card.is_plus_4){
//                player.draw(4);
//            }
//            if (current_card.symbol == "skip"){
//                current_card.symbol = "scip";
//                continue;
//            }
//            std::cout<<player.name<<" turn: "<<std::flush;
//            if(player.name != "You"){
//                int i = 1;
//                for(Card card: player.hand){
//                    if(card.is_valid_play(current_card.color, current_card.symbol)){
//                        break;
//                    }
//                    i++;
//                }
//                //if valid card exists in hand
//                if(i!= (player.hand.size()+1)){
//                    current_card = player.play_card(i);
//                    std::cout<<"Drew 0 Cards. Played ";
//                    print(std::cout,current_card);
//                    std::cout<<std::endl;
//                    player.print_hand_to_others();
//                }
//                //if valid card does not exist in hand.
//                else{
//                    int num_drawn = 0;
//                    while(true){
//                        player.draw(1);
//                        ++num_drawn;
//                        if(player.hand[player.hand.size()-1].is_valid_play(current_card.color,current_card.symbol)){
//                            current_card = player.play_card(player.hand.size());
//                            std::cout<<"Drew "<<num_drawn<<" cards. Played "; print(std::cout,current_card); std::cout<<std::endl;
//                            player.print_hand_to_others();
//                            break;
//                        }
//                    }
//                }
//                if(current_card.is_wild || current_card.is_plus_4){
//                    current_card.color = player.most_freq_color();
//                    std::cout<<"The color is "<<current_card.color<<std::endl;
//                }
//
//
//            }
//            else{
//                std::cout<<std::endl;
//                draw:
//                player.print_hand();
//                std::cout<<"Would you like to draw? (y/n) (Current Card: "; print(std::cout,current_card); std::cout<<")"<<std::endl;
//
//                std::string go_again;
//                std::cin>>go_again;
//                if(go_again == "y"){
//                    player.draw(1);
//                    goto draw;
//                }
//                std::cout<<"enter card to play (Current Card: "; print(std::cout,current_card); std::cout<<")"<<std::endl;
//                int cardno;
//                std::cin>>cardno;
//                if(player.hand[cardno-1].is_valid_play(current_card.color, current_card.symbol)){
//                    current_card = player.play_card(cardno);
//                }
//                else{
//                    std::cout<<"Not a valid play. Try again."<<std::endl;
//                    goto draw;
//                }
//                if (current_card.is_wild || current_card.is_plus_4){
//                    std::cout<<"Enter color: Yellow, Green, Red, Blue. (First letter capitalized is important)"<<std::endl;
//                    std::cin>>current_card.color;
//                }
//            }
//            ++index;
//            if(player.hand.size() == 0){
//                    std::cout<<player.name<<" has finished"<<std::endl;
//                    player.inGame == false;
//                    players.erase(players.begin()+index);
//                }
//            if (current_card.symbol == "reverse"){
//                break;
//            }
//
//        }
//        std::cout<<"Current card: ";
//        print(std::cout,current_card);
//        std::cout<<std::endl;
//
//    }
//
//}


