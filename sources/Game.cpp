# include <iostream>
# include <fstream>
# include "game.hpp"
# include "player.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2)
    {
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
    int Game::get_p1_stacksize(){
        return p1.stacksize();
    }
    int Game::get_p2_stacksize(){
        return p2.stacksize();
    }
    int Game::get_p1_cardsTaken(){
        return p1.cardesTaken();
    }
    int Game::get_p2_cardsTaken(){
        return p2.cardesTaken();
    }
    void Game::there_is_a_tie(){
    }

}