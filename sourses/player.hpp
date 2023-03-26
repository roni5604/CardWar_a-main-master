#pragma once
#include "card.hpp"
using namespace std;
namespace ariel
{
    class Player
    {
      private:
        string name;
        int cardsTaken;
        vector<Card> cards;
        public:
        Player(string name);
        ~Player();
        int cardesTaken();
        int stacksize();

    };
}