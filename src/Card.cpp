#include "Card.h"

Card::Card(){
    color = colors[randint(0,3)];
    int randomSymbol = randint(1,14);
    if(randomSymbol <= 10) symbol = std::to_string(randomSymbol-1);
    if(randomSymbol == 11) symbol = "Skip";
    if(randomSymbol == 12) symbol = "Reverse";
    if(randomSymbol == 13) symbol = "+2";
    if(randomSymbol == 14) {
        int wildOrPlus = randint(1, 2);
        if (wildOrPlus == 1) {
            symbol = "Wild";
            color = "";
        }
        else {
            symbol = "+4";
            color = "";
        }
    }
}

bool Card::is_valid_play(Card &cardInPlay) {
    if(symbol == "+4" || symbol == "Wild"){
        return true;
    }
    if(color == cardInPlay.color || symbol == cardInPlay.symbol){
        return true;
    }
    return false;
}

std::string Card::to_string() {
    if(symbol == "+4") return "+4";
    if(symbol == "Wild") return "Wild";
    return color + " " + symbol;
}

std::ostream & print(std::ostream &os, const Card &item){
    if(item.symbol == "+4"){
        os<<"+4";
        return os;
    }
    if(item.symbol == "Wild"){
        os<<"Wild Card";
        return os;
    }
    os<<item.color<<" "<<item.symbol;
    return os;
}

int randint(int lower, int upper){ 
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(lower, upper);

    return distr(generator);
}