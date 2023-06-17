#include "Player.h"
#include "Card.h"

Player::Player(std::string n) {
    name = n;
    draw(7);
}

void Player::draw(int no_cards) {
    for(int i = 0; i<no_cards;i++){
        Card card = Card();
        hand.push_back(card);
    }
}

void Player::print_hand() {
    int i = 1;
    for(Card &card: hand){
        std::cout<<i<<" [";
        print(std::cout, card);
        std::cout<<"]    ";
        if(i%7==0) std::cout<<"\n";
        ++i;
    }
    std::cout<<std::endl;
}

void Player::print_hand_to_others() {
    std::cout<<name<<" has "<<hand.size()<<" cards."<<std::endl;
}

Card Player::play_card(int cardNo){
    Card card = hand[cardNo - 1];
    hand.erase(hand.begin()+(cardNo - 1));
    return card;
}

std::string Player::most_freq_color() {
    std::vector<std::string> colors = {"Red", "Blue", "Yellow", "Green"};
    std::vector<int> colorFrequency (4, 0);
    for(Card &card:hand){
        if(card.color == "Red") ++colorFrequency[0];
        if(card.color == "Blue") ++colorFrequency[1];
        if(card.color == "Yellow") ++colorFrequency[2];
        if(card.color == "Green")  ++colorFrequency[3];
    }
    int index_of_max = colorFrequency.front();
    for(int i = 1; i < colorFrequency.size(); ++i){
        if(colorFrequency[i] > colorFrequency[index_of_max]){
            index_of_max = i;
        }
    }
    return colors[index_of_max];
}
