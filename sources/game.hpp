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
        int p1_cardsTaken;
        int p2_cardsTaken;
        int draw;
        int turn;
        int p1_stacksize;
        int p2_stacksize;
        vector<string> log;
        vector<string> stats;
        string lastTurn;
        
    public:
        Game(Player& p1, Player& p2);
        void playAll();
        void playTurn();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        void addLog(string s);
        void addStats(string s);
        ~Game();
        int get_p1_stacksize();
        int get_p2_stacksize();
        int get_p1_cardsTaken();
        int get_p2_cardsTaken();
    };
}
