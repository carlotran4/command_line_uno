#ifndef _card_
#define _card_

#include <iostream>
#include <string>
#include <vector>
#include <experimental/random>

using namespace std;
using std::experimental::randint; using std::experimental::reseed;

struct Card{
    string color;
    string symbol;
    bool is_plus_4 = false;
    bool is_wild = false;
    Card(){
        reseed();
        int cint = randint(1,10000);
        if(cint<1875){
            color = "Red";
            symbol = to_string(randint(1,9));}
        else if(cint<3750){
            color = "Blue";
            symbol = to_string(randint(1,9));
        }
        else if(cint<5625){
            color = "Green";
            symbol = to_string(randint(1,9));
        }
        else if(cint<7500){
            color = "Yellow";
            symbol = to_string(randint(1,9));
        }
        else{
            reseed();
            int sint = randint(1,100);
            if(sint<25){is_wild = true;}
            else if(sint<50){is_plus_4 = true;}
            else if(sint<75){
                symbol = "skip";
                color = colors[randint(0,3)];
            }
            else{
                symbol = "reverse";
                color = colors[randint(0,3)];
            }
            
        }
    }
    
    bool is_valid_play(string color_in_play, string symbol_in_play){
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

    private:
        vector<string> colors = {"Red","Blue","Green","Yellow"};
};

ostream & print(std::ostream &os, const Card &item){
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

#endif //_card_