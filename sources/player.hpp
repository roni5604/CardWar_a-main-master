#pragma once
#include "card.hpp"
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
namespace ariel
{
    class Player
    {
    private:
         string Name;
    public:
        Player(const string &name);
        ~Player();
        int cardesTaken();
        int stacksize();
        Card pop_pile();
        void push_pile(stack<Card> myStack);

    };
}