#pragma once
#include "player.hpp"
using namespace std;
namespace ariel
{
    class Game
    {
        Player p1;
        Player p2;
    public:
        Game(Player& p1, Player& p2);
        void playAll();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        ~Game();
    };
}
