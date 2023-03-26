#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vactor>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    Player::Player(string name){
        this->name = name;
    }
    Player::~Player(){
        this->name = "";
    }
    int Player::cardesTaken(){
        return this->cardsTaken;
    }
    int Player::stacksize(){
        return this->cards.size();
    }
}