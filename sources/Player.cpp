#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <stack>

using namespace std;


namespace ariel
{
  

    Player::Player(const string &name) : Name(name)
    {

    }
    Player::~Player()
    {
    }
    void Player::addCard(string card){
        myCards.push(card);
    }
    int Player::cardesTaken(){
        return 0;
    }
    int Player::stacksize(){
        return myCards.size();
    }
    Card Player::pop_pile(){
        return Card();
    }
    void Player::push_pile(stack<Card> myStack){
    }

    stack <Card> Player::getMyCards(){
        return myCards;
    }
    
}