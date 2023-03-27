#pragma once
#include "player.hpp"
using namespace std;
namespace ariel
{
    class Game
    {
    private:
        Player p1;
        Player p2;
    public:
        Game(Player& p1, Player& p2);
        void playAll();
        void playTurn();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        ~Game();
        int get_p1_stacksize();
        int get_p2_stacksize();
        int get_p1_cardsTaken();
        int get_p2_cardsTaken();
        
    };
}
