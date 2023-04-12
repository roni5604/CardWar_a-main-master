# include <iostream>
# include <fstream>
# include "game.hpp"
# include "player.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2)
    {
        for (int i = 1; i <= 26; i++)
        {
            p1.addCard(getRandomCard());
            p2.addCard(getRandomCard());
        }
        draw = 0;
        turn = 0;
        p1_cardsTaken = 0;
        p2_cardsTaken = 0;
        p1_stacksize = p1.stacksize();
        p2_stacksize = p2.stacksize();
        
    }
    void Game::playAll(){

    }
    void Game::printLastTurn(){
        cout << lastTurn << endl;
    }
    void Game::printWiner(){
        if (gameOver() == 1)
        {
            cout << "The winner is: " << p1.getName() << endl;
        }
        else if (gameOver() == 2)
        {
            cout << "The winner is: " << p2.getName() << endl;
        }   
    }
    void Game::printLog(){
        for (int i = 0; i < log.size(); i++)
        {
            cout << log[i] << endl;
        }
    }
    void Game::printStats(){
        for (int i = 0; i < stats.size(); i++)
        {
            cout << stats[i] << endl;
        }
    }
    Game::~Game(){

    }
    
    void Game::playTurn(){
        if (gameOver() == 0)
        {
            turn++;
            string p1_card = p1.pop_pile();
            string p2_card = p2.pop_pile();
            lastTurn = p1.getName() + " played: " + p1_card + " " + p2.getName() + " played: " + p2_card;
            if (p1_card[0]>p2_card[0])
            {
                p1_cardsTaken++;
                p1.addCard(p1_card);
                p1.addCard(p2_card);
                addLog(p1.getName() + " took " + p1_card + " and " + p2_card);
                addStats(p1.getName() + " took " + p1_card + " and " + p2_card);
            }
            else if (p1_card[0]<p2_card[0])
            {
                p2_cardsTaken++;
                p2.addCard(p1_card);
                p2.addCard(p2_card);
                addLog(p2.getName() + " took " + p1_card + " and " + p2_card);
                addStats(p2.getName() + " took " + p1_card + " and " + p2_card);
            }
            else if (p1_card[0]==p2_card[0])
            {

                addLog("There is a tie "+p2.getName() + " took " + p1_card + " and " + p2_card);
                addStats("There is a tie");
                stack<string> tie;
                tie.push(p1_card);
                tie.push(p2_card);
                bool tieBreak = true;
                while (tieBreak)
                {
                 tie.push(p1.pop_pile());
                 tie.push(p2.pop_pile());
                 string p1_tie=p1.pop_pile();
                 string p2_tie=p2.pop_pile();
                 if (p1_tie[0]>p2_tie[0])
                 {
                  tie.push(p1_tie);
                    tie.push(p2_tie);
                    while (!tie.empty())
                    {
                        p1.addWin(tie.top());
                        tie.pop();
                    }
                 addLog(p1.getName() + " took " + p1_card + " and " + p2_card);
                 addStats(p1.getName() + " took " + p1_card + " and " + p2_card);
                 tieBreak= false;
                }
                else if (p1_tie[0]<p2_tie[0])
                {
                    tie.push(p1_tie);
                    tie.push(p2_tie);
                    while (!tie.empty())
                    {
                        p2.addWin(tie.top());
                        tie.pop();
                    }
                    addLog(p2.getName() + " took " + p1_card + " and " + p2_card);
                    addStats(p2.getName() + " took " + p1_card + " and " + p2_card);
                    tieBreak= false;
                }
                else
                {
                    tie.push(p1_tie);
                    tie.push(p2_tie);
                    addLog("There is a tie "+p2.getName() + " took " + p1_card + " and " + p2_card);
                    addStats("There is a tie");
                } 
                
            }
        }
        else
        {
            printWiner();
        }
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
   

}