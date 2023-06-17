#include "Card.h"

Card::Card(){
    std::experimental::reseed();
    color = colors[std::experimental::randint(0,3)];
    std::experimental::reseed();
    int randomSymbol = std::experimental::randint(1,14);
    if(randomSymbol <= 10) symbol = std::to_string(randomSymbol-1);
    if(randomSymbol == 11) symbol = "skip";
    if(randomSymbol == 12) symbol = "reverse";
    if(randomSymbol == 13) symbol = "+2";
    if(randomSymbol == 14) {
        std::experimental::reseed();
        int wildOrPlus = std::experimental::randint(1, 2);
        if (wildOrPlus == 1) {
            symbol = "wild";
            is_wild = true;
        } else {
            symbol = "+4";
            is_plus_4 = true;
        }
    }
}

bool Card::is_valid_play(std::string color_in_play, std::string symbol_in_play) {
    if(is_plus_4 || is_wild){
        return true;
    }
    if(color == color_in_play || symbol == symbol_in_play){
        return true;
    }
    if(symbol_in_play == "scip" && symbol == "skip"){
        return true;
    }
    return false;
}

std::ostream & print(std::ostream &os, const Card &item){
    if(item.is_plus_4){
        os<<"Plus 4";
        return os;
    }
    if(item.is_wild){
        os<<"Wild Card";
        return os;
    }
    os<<item.color<<" "<<item.symbol;
    return os;
}