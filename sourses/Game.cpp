# include <iostream>
# include <fstream>
# include "game.hpp"
# include "player.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player& p1, Player& p2){
        this->p1 = p1;
        this->p2 = p2;
    }
    void Game::playAll(){
    }
    void Game::printLastTurn(){
    }
    void Game::printWiner(){
    }
    void Game::printLog(){
    }
    void Game::printStats(){
    }
    Game::~Game(){
    }
    
    void Game::playTurn(){
    }
}