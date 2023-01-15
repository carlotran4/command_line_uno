#include "Card.h"
#include "Player.h"

int main(){
    vector<Player> myvec;
    myvec[1].draw(4);
    myvec[1].print_hand();
}