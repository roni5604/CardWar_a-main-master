#include "card.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

namespace ariel{
    Card::Card(){
        cardGiven = 0;
        allCardsBefore = {{"A diamond",true}, {"A spade",true}, {"A heart",true}, {"A club",true}, 
        {"2 diamond",true}, {"2 spade",true}, {"2 heart",true}, {"2 club",true}, 
        {"3 diamond",true}, {"3 spade",true}, {"3 heart",true}, {"3 club",true}, 
        {"4 diamond",true}, {"4 spade",true}, {"4 heart",true}, {"4 club",true}, 
        {"5 diamond",true}, {"5 spade",true}, {"5 heart",true}, {"5 club",true}, 
        {"6 diamond",true}, {"6 spade",true}, {"6 heart",true}, {"6 club",true},
         {"7 diamond",true}, {"7 spade",true}, {"7 heart",true}, {"7 club",true},
          {"8 diamond",true}, {"8 spade",true}, {"8 heart",true}, {"8 club",true},
           {"9 diamond",true}, {"9 spade",true}, {"9 heart",true}, {"9 club",true},
            {"10 diamond",true}, {"10 spade",true}, {"10 heart",true}, {"10 club",true}, 
            {"J diamond",true}, {"J spade",true}, {"J heart",true}, {"J club",true}, 
            {"Q diamond",true}, {"Q spade",true}, {"Q heart",true}, {"Q club",true},
             {"K diamond",true}, {"K spade",true}, {"K heart",true}, {"K club",true}};
        
    }
    Card::~Card(){
       
    }
    string Card::getRandomCard(){
        while (cardGiven!=52)
        {
            int random = rand() % 52;
            if (allCardsBefore[random].second == true)
            {
                cardGiven++;
                allCardsBefore[random].second = false;
                return allCardsBefore[random].first;
            }
        }
    }
    string Card::getCardInfo(){
        return " ";
    }
    
    
}