#include "Card.h"

Card::Card(){
    std::experimental::reseed();
    color = colors[std::experimental::randint(0,3)];
    std::experimental::reseed();
    int randomSymbol = std::experimental::randint(1,14);
    if(randomSymbol <= 10) symbol = std::to_string(randomSymbol-1);
    if(randomSymbol == 11) symbol = "Skip";
    if(randomSymbol == 12) symbol = "Reverse";
    if(randomSymbol == 13) symbol = "+2";
    if(randomSymbol == 14) {
        std::experimental::reseed();
        int wildOrPlus = std::experimental::randint(1, 2);
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

bool Card::is_valid_play(std::string color_in_play, std::string symbol_in_play) {
    if(symbol == "+4" || symbol == "Wild"){
        return true;
    }
    if(color == color_in_play || symbol == symbol_in_play){
        return true;
    }
    //TODO: Why is symbol_in_play scip????
    if(symbol_in_play == "scip" && symbol == "skip"){
        return true;
    }
    return false;
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
