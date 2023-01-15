#ifndef _player_
#define _player_

#include "Card.h"
#include <vector>
#include <iostream>
#include <string>

struct Player{
    vector<Card> hand;
    string name;
    bool is_alive = true;
    Player(string n){
        name = n;
        draw(7);
    }
    void draw(int no_cards){
        for(int i = 0; i<no_cards;i++){
            Card card = Card();
            hand.push_back(card);
        }
    }
    void print_hand(){
        int i = 1;
        for(Card card: hand){
            cout<<i<<" [";
            print(cout, card);
            cout<<"]    ";
            if(i%7==0) cout<<"\n";
            ++i;
        }
        cout<<endl;
    }
    void print_hand_to_others(){
        cout<<name<<" has "<<hand.size()<<" cards."<<endl;
    }
    Card play_card(int cardno){
        Card card = hand[cardno-1];
        hand.erase(hand.begin()+(cardno-1));
        return card;
    }

    //return most prevalent color in hand
    string most_freq_color(){
        vector<int> colors (4,0);
        for(Card &card:hand){
            if(card.color == "Red") ++colors[0];
            if(card.color == "Blue") ++colors[1];
            if(card.color == "Yellow") ++colors[2];
            if(card.color == "Green")  ++colors[3];
        }
        int index_of_max = colors.front();
        for(int i = 1; i<colors.size(); ++i){
            if(colors[i]>colors[index_of_max]){
                index_of_max = i;
            }
        }
        switch (index_of_max){
        case 0:
            return "Red";
            break;
        case 1:
            return "Blue";
            break;
        case 2:
            return "Yellow";
            break;
        default:
            return "Green";
            break;
        }
    }
};

#endif //player