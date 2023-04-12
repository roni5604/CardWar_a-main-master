#pragma once
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
namespace ariel
{
    class Player
    {
    private:
        int numOfWins;
        int numOfLoses;
        string Name;
        int myCardsTaken;
        stack<string> myCards;
        stack<string> myCardsTakenStack;

    public:
        Player(const string &name);
        ~Player();
        Player(const Player &other);
        Player &operator=(const Player &other);
        Player(Player &&other)=default;
        Player& operator=(Player&& other)=default;
        string getName();
        void addCard(string card);
         int getWin();
        void addWin();
        int getlose();
        void addLose();
        int cardesTaken();
        int stacksize();
        string pop_pile();
        void push_pile(stack<string> myStack);
        void push_pile(string newCardToAdd);
        stack <string> getMyCards();
        void addCardsTaken(int cardsTaken);
        void startGameAddCard(string card);
    };
}