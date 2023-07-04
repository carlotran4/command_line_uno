#include "gameModes.h"
#include "gameflow.h"

//TODO: Make main function more concise/easy to follow
//TODO: Make a README

int main(){
    animatedPrint("Welcome to Command Line Uno!\n");
    animatedPrint("Enter S for single player, or M for multiplayer\n");
    std::string gameMode;
    std::cin>>gameMode;

    if(gameMode == "S") {
        singlePlayer();
    }

    if(gameMode == "M"){
        animatedPrint("Enter C to create a lobby, or J to join a lobby\n");
        std::string multiMode; std::cin>>multiMode;
        if(multiMode == "C") hostMultiMode();
        if(multiMode == "J") defaultMultiMode();
    }

}



