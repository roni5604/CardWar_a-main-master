#include "card.hpp"

using namespace std;

namespace ariel{
    Card::Card(int value, string suit){
        this->value = value;
        this->suit = suit;
    }
    Card::~Card(){
        this->value = 0;
        this->suit = "";
    }
}