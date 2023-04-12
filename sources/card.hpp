#pragma once
#include <string>
using namespace std;
namespace ariel
{
    class Card
    {
 
    public:

        Card();
        ~Card();
        string getCardInfo();
        string getRandomCard();
   
    private:
     string allCardsBefore[];
        int cardGiven;
    };
}