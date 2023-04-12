#pragma once
#include "player.hpp"
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
namespace ariel
{
    class Game
    {
    private:
        Player& player1;
        Player& player2;
        std::vector<std::tuple<std::string, bool>> allCardsBefore;
        int draw;
        int turn;
        vector<string> logs;
        vector<string> stats;
        string lastTurn;
        int cardGiven;
        bool isGameOver;

    public:
        Game(Player& player_1, Player& player_2);
        Game(const Game& other)=delete;
        Game& operator=(const Game& other)=delete;
        Game(Game&& other)=delete;
        Game& operator=(Game&& other)=delete;
        void playAll();
        void playTurn();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        void addLog(string str);
        ~Game();
        int gameOver();
        string getRandomCard();
        int howBigger(string card1, string card2);
        std::tuple<std::string, bool> getCardAt(int index);
    };
}
