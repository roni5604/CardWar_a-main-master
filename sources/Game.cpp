#include <iostream>
#include <fstream>
#include "game.hpp"
#include "player.hpp"
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;

namespace ariel
{
    //constructor of the game
    Game::Game(Player &player_1, Player &player_2) : player1(player_1), player2(player_2), allCardsBefore(vector<tuple<string, bool>>()), draw(0), turn(0), logs(vector<string>()), stats(vector<string>()), lastTurn(""), cardGiven(0)
    {

        isGameOver = false;
        cardGiven = 0;
        cardsbefore = {"A diamond", "A spade", "A heart", "A club", "2 diamond", "2 spade", "2 heart", "2 club", "3 diamond", "3 spade", "3 heart", "3 club", "4 diamond", "4 spade", "4 heart", "4 club", "5 diamond", "5 spade", "5 heart", "5 club", "6 diamond", "6 spade", "6 heart", "6 club", "7 diamond", "7 spade", "7 heart", "7 club", "8 diamond", "8 spade", "8 heart", "8 club", "9 diamond", "9 spade", "9 heart", "9 club", "10 diamond", "10 spade", "10 heart", "10 club", "J diamond", "J spade", "J heart", "J club", "Q diamond", "Q spade", "Q heart", "Q club", "K diamond", "K spade", "K heart", "K club"};
        allCardsBefore = {{"A diamond", true}, {"A spade", true}, {"A heart", true}, {"A club", true}, {"2 diamond", true}, {"2 spade", true}, {"2 heart", true}, {"2 club", true}, {"3 diamond", true}, {"3 spade", true}, {"3 heart", true}, {"3 club", true}, {"4 diamond", true}, {"4 spade", true}, {"4 heart", true}, {"4 club", true}, {"5 diamond", true}, {"5 spade", true}, {"5 heart", true}, {"5 club", true}, {"6 diamond", true}, {"6 spade", true}, {"6 heart", true}, {"6 club", true}, {"7 diamond", true}, {"7 spade", true}, {"7 heart", true}, {"7 club", true}, {"8 diamond", true}, {"8 spade", true}, {"8 heart", true}, {"8 club", true}, {"9 diamond", true}, {"9 spade", true}, {"9 heart", true}, {"9 club", true}, {"10 diamond", true}, {"10 spade", true}, {"10 heart", true}, {"10 club", true}, {"J diamond", true}, {"J spade", true}, {"J heart", true}, {"J club", true}, {"Q diamond", true}, {"Q spade", true}, {"Q heart", true}, {"Q club", true}, {"K diamond", true}, {"K spade", true}, {"K heart", true}, {"K club", true}};

        for (int i = 0; i < 26; i++)
        {

            player1.startGameAddCard(getRandomCard());

            player2.startGameAddCard(getRandomCard());
        }

        draw = 0;
        turn = 0;
    }
    //check if the game is over
    int Game::gameOver()
    {
        if (isGameOver)
        {
            return 0;
        }
        if ((player1.stacksize() == 0) || (player2.stacksize() == 0))
        {

            return 0;
        }
        return 1;
    }
    void Game::playAll()
    {
        //play all the turns
        while (gameOver() == 1)
        {
            playTurn();
        }
    }
    void Game::printLastTurn()
    {
        cout << lastTurn << endl;
    }

    void Game::printLog()
    {
        for (const auto &line : logs)
        {
            cout << line << endl;
        }
    }
    void Game::printStats()
    {
        double winRateP1 = static_cast<double>(player1.getWin()) / (player1.getWin() + player1.getlose()) * 100;
        double winRateP2 = static_cast<double>(player2.getWin()) / (player2.getWin() + player2.getlose()) * 100;
        string statP1 = player1.getName() + " won " + to_string(player1.getWin()) + " times, lost " + to_string(player1.getlose()) + " times, and win rate is " + to_string(winRateP1) + "%";
        string statP2 = player2.getName() + " won " + to_string(player2.getWin()) + " times, lost " + to_string(player2.getlose()) + " times, and win rate is " + to_string(winRateP2) + "%";
        string statDraw = "Draw: " + to_string(draw);
        cout << statP1 << endl;
        cout << statP2 << endl;
        cout << statDraw << endl;
    }
    Game::~Game()
    {
    }
    string Game::getRandomCard()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        if (cardsbefore.size() != 0)
        {
            size_t random_index = g() % cardsbefore.size();
            std::string picked_card = cardsbefore[random_index];
            cardsbefore.erase(cardsbefore.begin() + static_cast<long>(random_index));
            return picked_card;
        }
        return "no more cards";
    }

    int Game::howBigger(string card1, string card2)
    {
        //return 1 if card1 is bigger, 2 if card2 is bigger, 0 if draw
        int card1_value;
        int card2_value;
        if (card1[0] == 'J')
        {
            card1_value = 11;
        }
        else if (card1[0] == 'Q')
        {
            card1_value = 12;
        }
        else if (card1[0] == 'K')
        {
            card1_value = 13;
        }
        else if (card1[0] == 'A' && card2[0] == '2')
        {
            return 2;
        }
        else if (card1[0] == 'A' && card2[0] != '2')
        {
            card1_value = 14;
        }
        else
        {
            card1_value = card1[0] - '0';
        }

        if (card2[0] == 'A' && card1[0] == '2')
        {
            return 1;
        }
        else if (card2[0] == 'A' && card1[0] != '2')
        {

            card2_value = 14;
        }
        else if (card2[0] == 'J')
        {
            card2_value = 11;
        }
        else if (card2[0] == 'Q')
        {
            card2_value = 12;
        }
        else if (card2[0] == 'K')
        {
            card2_value = 13;
        }
        else
        {
            card2_value = card2[0] - '0';
        }

        if (card1_value > card2_value)
        {
            return 1;
        }
        else if (card1_value < card2_value)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    void Game::printWiner()
    {
        if (gameOver() == 1)
        {
            cout << "the game is not over yet" << endl;
            return;
        }
        if (player1.stacksize() > player2.stacksize())
        {
            cout << player1.getName() << " won the game" << endl;
        }
        else if (player1.stacksize() < player2.stacksize())
        {
            cout << player2.getName() << " won the game" << endl;
        }
    }

    void Game::playTurn()
    {
        // check if the name is the same
        if (player1.getName() == player2.getName())
        {
            throw invalid_argument("The players have the same name");
        }

        // check if the game is over
        if (gameOver() == 1)
        {
            turn++;                              // count the turn
            string p1_card = player1.pop_pile(); // get the card from the player
            string p2_card = player2.pop_pile(); // get the card from the player
            int howIsBigger = howBigger(p1_card, p2_card);
            lastTurn = player1.getName() + " played: " + p1_card + " " + player2.getName() + " played: " + p2_card;
            if (howIsBigger == 0) // draw
            {
                lastTurn.append(" draw. \n ");
                stack<string> tie;
                tie.push(p1_card);
                tie.push(p2_card);
                bool tieBreak = true;
                while (tieBreak)
                {
                    draw++;
                    if (player1.stacksize() < 2 || player2.stacksize() < 2)
                    {
                        while (!tie.empty())
                        {
                            player1.addCard(tie.top());
                            player1.addCardsTaken(1);
                            tie.pop();
                            if (!tie.empty())
                            {
                                player2.addCard(tie.top());
                                player2.addCardsTaken(1);
                                tie.pop();
                            }
                        }
                        lastTurn.append(" tie break by draw ");
                        tieBreak = false;
                    }
                    else
                    {
                        tie.push(player1.pop_pile());
                        player1.addCardsTaken(-1);
                        tie.push(player2.pop_pile());
                        player2.addCardsTaken(-1);
                        string p1_tie = player1.pop_pile();
                        string p2_tie = player2.pop_pile();
                        tie.push(p1_tie);
                        player1.addCardsTaken(-1);
                        tie.push(p2_tie);
                        player2.addCardsTaken(-1);
                        int howBiggertie = howBigger(p1_tie, p2_tie);
                        lastTurn.append(player1.getName() + " played: " + p1_tie + " " + player2.getName() + " played: " + p2_tie);
                        if (howBiggertie == 1)
                        {
                            lastTurn.append(player1.getName() + " won ");
                            player1.addWin();
                            player2.addLose();
                            while (!tie.empty())
                            {
                                player1.addCard(tie.top());
                                player1.addCardsTaken(1);
                                tie.pop();
                            }
                            tieBreak = false;
                        }
                        else if (howBiggertie == 2)
                        {
                            player2.addWin();
                            player1.addLose();
                            lastTurn.append(player2.getName() + " won ");
                            while (!tie.empty())
                            {
                                player2.addCard(tie.top());
                                player2.addCardsTaken(1);
                                tie.pop();
                            }
                            tieBreak = false;
                        }
                        else
                        {
                            tie.push(p1_tie);
                            tie.push(p2_tie);
                        }
                    }
                }
                addLog(lastTurn);
            }
            else if (howIsBigger == 1)// player 1 won
            {
                player1.addWin();
                player2.addLose();
                lastTurn.append(player1.getName() + " won \n");
                player1.addCard(p1_card);
                player1.addCard(p2_card);
                player1.addCardsTaken(2);
            }
            else if (howIsBigger == 2)// player 2 won
            {
                player2.addWin();
                player1.addLose();
                lastTurn.append(player2.getName() + " won \n ");
                player2.addCard(p1_card);
                player2.addCard(p2_card);
                player2.addCardsTaken(2);
            }
            addLog(lastTurn);
        }
        else
        {
            throw "game is over";// game is over
            printWiner();
        }
    }

    void Game::addLog(string log)
    {
        logs.push_back(log);
    }

}