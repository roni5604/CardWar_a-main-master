#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "player.hpp"
#include <iostream>
#include <stack>

using namespace std;


namespace ariel
{

    Player::Player(const string &name) : Name(name), numOfWins(0), numOfLoses(0), myCardsTaken(0)
    {
        
    }
    Player::Player(const Player &other) : Name(other.Name), numOfWins(other.numOfWins), numOfLoses(other.numOfLoses), myCardsTaken(other.myCardsTaken)
    {
    }
    Player &Player::operator=(const Player &other)
    {
        if (this != &other)
        {
            Name = other.Name;
            numOfWins = other.numOfWins;
            numOfLoses = other.numOfLoses;
            myCardsTaken = other.myCardsTaken;
        }
        return *this;
    }
    
    Player::~Player()
    {
    }
    void Player::addCard(string card){
        myCardsTakenStack.push(card);
    }
    void Player::startGameAddCard(string card){
        myCards.push(card);
    }
    int Player::cardesTaken(){
        return myCardsTakenStack.size();
    }
    int Player::stacksize(){
        return myCards.size();
    }
    string Player::pop_pile(){
        string temp = myCards.top();
        myCards.pop();
        return temp;
    }
    string Player::getName(){
        return Name;
    }
    void Player::push_pile(stack<string> newStack){
        while (!newStack.empty())
        {
            myCardsTakenStack.push(newStack.top());
            newStack.pop();}
    }
       void Player::push_pile(string newCardToAdd){
        myCardsTakenStack.push(newCardToAdd);
    }


    stack <string> Player::getMyCards(){
        return myCards;
    }
    void Player::addCardsTaken(int cardsTaken){
        myCardsTaken += cardsTaken;
    }
    int Player::getWin(){
        return numOfWins;
    }
    void Player::addWin(){
        numOfWins++;
    }
    int Player::getlose(){
        return numOfLoses;
    }
    void Player::addLose(){
        numOfLoses++;
    }

    
}