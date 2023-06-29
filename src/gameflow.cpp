#include "gameflow.h"

void sleep(int milliseconds){
using std::chrono::operator""ms;
std::this_thread::sleep_for(milliseconds*1ms);
}

void animatedPrint(std::string text) {
    for(char c : text){
        std::cout<<c;
        sleep(15);
    }
}

void playerPlaySequence(Player &player, Card &cardInPlay){
    animatedPrint("Your turn!\n");
    animatedPrint("Card In Play: "+ cardInPlay.to_string()+"\n");
    std::string input;
    animatedPrint("Your Hand: " + player.to_string(true)+"\n");
    animatedPrint("Enter the number card you would like to play, or enter d for draw.\n");
    std::cin>>input;
    while(input == "d" || !player.hand[std::stoi(input)-1].is_valid_play(cardInPlay)) {
        animatedPrint("Card In Play: "+ cardInPlay.to_string()+"\n");
        if(input == "d") {
            player.draw(1);
            animatedPrint("Your Hand: " + player.to_string(true) + "\n");
            animatedPrint("Enter the number card you would like to play, or enter d for draw.\n");
        }
        else{
            animatedPrint("Not a valid card to play. Enter a different number, or d for draw.\n");
        }
        std::cin>>input;
    }
    cardInPlay = player.play_card(std::stoi(input));
    if(player.hand.empty()) player.inGame = false;
    sleep(500);
    std::cout<<std::endl;
}

void botPlaySequence(Player &player, Card &cardInPlay) {
    animatedPrint(player.name+"'s Turn!\n");
    sleep(500);
    animatedPrint("Card In Play: "+ cardInPlay.to_string()+"\n");
    sleep(500);
    bool playedCard = false;
    for (int i = 0; i<player.hand.size(); ++i){
        if(player.hand[i].is_valid_play(cardInPlay)){
            cardInPlay = player.play_card(i+1);
            playedCard = true;
            break;
        }
    }
    int cards_drawn = 0;
    while(!playedCard){
        cards_drawn++;
        player.draw(1);
        if(player.hand.back().is_valid_play(cardInPlay)){
            cardInPlay = player.play_card(player.hand.size());
            playedCard = true;
        }
    }

    if(player.hand.empty()){
        player.inGame = false;
        animatedPrint(player.name + " Played " + cardInPlay.to_string()+
                      " and drew "+std::to_string(cards_drawn)+" cards.\n");
        animatedPrint(player.to_string(false)+"\n");
        animatedPrint(player.name+" has finished!!!\n\n");
        return;
    }

    animatedPrint(player.name + " Played " + cardInPlay.to_string()+
    " and drew "+std::to_string(cards_drawn)+" cards.\n");
    animatedPrint(player.to_string(false)+"\n\n");
    sleep(1000);

}

void reverse_players(std::vector<Player> &players, int &index) {
    std::vector<Player> temp;
    for(int i = index-1; i>=0; --i){
        temp.push_back(players[i]);
    }
    for(int i = players.size()-1; i>= index; --i){
        temp.push_back(players[i]);
    }
    players = temp;
    index = -1;
}

