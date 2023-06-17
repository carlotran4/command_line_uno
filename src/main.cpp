#include "Player.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <experimental/random>
#include <experimental/algorithm>
using namespace std;
using std::experimental::randint; using std::experimental::reseed;

int main(){
    cout<< "Welcome to command line uno!"<<endl;
    Player bot1 = Player("Bot 1");
    Player bot2 = Player("Bot 2");
    Player bot3 = Player("Bot 3");
    Player person = Player("You");
    vector<Player> players {bot1,bot2,bot3,person};
    experimental::shuffle(players.begin(), players.end());
    cout<<"ORDER: ";
    for(Player p: players){
        cout<<p.name<<", ";
    }
    cout<<"\n"<<endl;
    cout<<"Your Cards"<<endl;
    person.print_hand();

    //Card in play.
    Card current_card;
    //Ensure first card is not Special card.
    do{
    current_card = Card();
    } while (current_card.is_wild || current_card.is_plus_4);
    cout<<"First card"<<endl;
    print(cout,current_card);
    cout<<endl;

    //Begin game
    while(players.size()>1 && person.is_alive){
        //iterator
        int index = 0;
        if(current_card.symbol == "reverse"){
            reverse(players.begin(), players.end());
            cout<<"New order: ";
            for(Player p: players){
            cout<<p.name<<", ";
            }
            cout<<endl;
        }
        for(Player &player: players){
            if (current_card.is_plus_4){
                player.draw(4);
            }
            if (current_card.symbol == "skip"){
                current_card.symbol = "scip";
                continue;
            }
            cout<<player.name<<" turn: "<<flush;
            if(player.name != "You"){
                int i = 1;
                for(Card card: player.hand){
                    if(card.is_valid_play(current_card.color, current_card.symbol)){
                        break;
                    }
                    i++;
                }
                //if valid card exists in hand
                if(i!= (player.hand.size()+1)){
                    current_card = player.play_card(i);
                    cout<<"Drew 0 Cards. Played ";
                    print(cout,current_card);
                    cout<<endl;
                    player.print_hand_to_others();
                }
                //if valid card does not exist in hand.
                else{
                    int num_drawn = 0;
                    while(true){
                        player.draw(1);
                        ++num_drawn;
                        if(player.hand[player.hand.size()-1].is_valid_play(current_card.color,current_card.symbol)){
                            current_card = player.play_card(player.hand.size());
                            cout<<"Drew "<<num_drawn<<" cards. Played "; print(cout,current_card); cout<<endl;
                            player.print_hand_to_others();
                            break;
                        }
                    }
                }
                if(current_card.is_wild || current_card.is_plus_4){
                    current_card.color = player.most_freq_color();
                    cout<<"The color is "<<current_card.color<<endl;
                }
                

            }
            else{
                cout<<endl;
                draw:
                player.print_hand();
                cout<<"Would you like to draw? (y/n) (Current Card: "; print(cout,current_card); cout<<")"<<endl;

                string go_again;
                cin>>go_again;
                if(go_again == "y"){
                    player.draw(1);
                    goto draw;
                }
                cout<<"enter card to play (Current Card: "; print(cout,current_card); cout<<")"<<endl;
                int cardno;
                cin>>cardno;
                if(player.hand[cardno-1].is_valid_play(current_card.color, current_card.symbol)){
                    current_card = player.play_card(cardno);
                }
                else{
                    cout<<"Not a valid play. Try again."<<endl;
                    goto draw;
                }
                if (current_card.is_wild || current_card.is_plus_4){
                    cout<<"Enter color: Yellow, Green, Red, Blue. (First letter capitalized is important)"<<endl;
                    cin>>current_card.color;
                }
            }
            ++index;
            if(player.hand.size() == 0){
                    cout<<player.name<<" has finished"<<endl;
                    player.is_alive == false;
                    players.erase(players.begin()+index);
                }
            if (current_card.symbol == "reverse"){
                break;
            }
        
        }
        cout<<"Current card: ";
        print(cout,current_card);
        cout<<endl;

    }

}


