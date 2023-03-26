
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;


#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"


int HowManyCardsTaken(Player& p){
    return p.cardesTaken();
    //return the number of cards taken by the player
}
int HowManyCardsHave(Player& p){
    return p.stacksize();
    //return the number of cards in the stack
}
int HowManyCardsInDeck(Game& g){
    return g.deckSize();
    //return the number of cards in the deck
}
int HowManyCardsInPile(Game& g){
    return g.pileSize();
    //return the number of cards in the pile
}
int HowManyCardsInHand(Player& p){
    return p.handSize();
    //return the number of cards in the hand
}
int HowManyCardsInStack(Player& p){
    return p.stackSize();
    //return the number of cards in the stack
}
int HowManyCardsInDiscard(Player& p){
    return p.discardSize();
    //return the number of cards in the discard pile
}
bool IsCardInHand(Player& p, Card& c){
    return p.isCardInHand(c);
    //return true if the card is in the hand
}
bool IsCardInStack(Player& p, Card& c){
    return p.isCardInStack(c);
    //return true if the card is in the stack
}
bool IsCardInDiscard(Player& p, Card& c){
    return p.isCardInDiscard(c);
    //return true if the card is in the discard pile
}
bool IsCardInPile(Game& g, Card& c){
    return g.isCardInPile(c);
    //return true if the card is in the pile
}
bool IsCardInDeck(Game& g, Card& c){
    return g.isCardInDeck(c);
    //return true if the card is in the deck
}
bool IsCardInGame(Game& g, Card& c){
    return g.isCardInGame(c);
    //return true if the card is in the game
}
bool IsCardInPlayer(Player& p, Card& c){
    return p.isCardInPlayer(c);
    //return true if the card is in the player
}
bool IsCardInPlayerHand(Player& p, Card& c){
    return p.isCardInPlayerHand(c);
    //return true if the card is in the player hand
}
bool IsCardInPlayerStack(Player& p, Card& c){
    return p.isCardInPlayerStack(c);
    //return true if the card is in the player stack
}
bool IsCardInPlayerDiscard(Player& p, Card& c){
    return p.isCardInPlayerDiscard(c);
    //return true if the card is in the player discard pile
}
bool IsCardInPlayerGame(Player& p, Card& c){
    return p.isCardInPlayerGame(c);
    //return true if the card is in the player game
}
void PrintCard(Card& c){
    cout << c << endl;
    //print the card
}
void PrintPlayer(Player& p){
    cout << p << endl;
    //print the player
}
void PrintGame(Game& g){
    cout << g << endl;
    //print the game
}
void PrintDeck(Game& g){
    cout << g.deck() << endl;
    //print the deck
}
void PrintPile(Game& g){
    cout << g.pile() << endl;
    //print the pile
}
void PrintHand(Player& p){
    cout << p.hand() << endl;
    //print the hand
}
void PrintStack(Player& p){
    cout << p.stack() << endl;
    //print the stack
}
void PrintDiscard(Player& p){
    cout << p.discard() << endl;
    //print the discard pile
}


TEST_CASE("Test Number1 - Init Deck"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    CHECK(HowManyCardsInDeck(g) == 52);
}

TEST_CASE("Test Number2 - Init Card"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    CHECK(HowManyCardsTaken(p1) == 0);
    CHECK(HowManyCardsTaken(p2) == 0);
}
TEST_CASE("Test Number3 - Init Player"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    CHECK(HowManyCardsHave(p1) == 26);
    CHECK(HowManyCardsHave(p2) == 26);
}
TEST_CASE("Test Number4 - Play Turn"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playTurn();
    bool case1 = (HowManyCardsTaken(p1) == 2 && HowManyCardsTaken(p2) == 0&& HowManyCardsHave(p1) == 27 && HowManyCardsHave(p2) == 25);
    bool case2 = (HowManyCardsTaken(p1) == 0 && HowManyCardsTaken(p2) == 2&& HowManyCardsHave(p1) == 25 && HowManyCardsHave(p2) == 27);
    bool case3 = (HowManyCardsTaken(p1) == 6 && HowManyCardsTaken(p2) == 0&& HowManyCardsHave(p1) == 29 && HowManyCardsHave(p2) == 23);
    bool case4 = (HowManyCardsTaken(p1) == 0 && HowManyCardsTaken(p2) == 6&& HowManyCardsHave(p1) == 23 && HowManyCardsHave(p2) == 29);
    bool case5 = (HowManyCardsTaken(p1) == 10 && HowManyCardsTaken(p2) == 0&& HowManyCardsHave(p1) == 31 && HowManyCardsHave(p2) == 21);
    bool case6 = (HowManyCardsTaken(p1) == 0 && HowManyCardsTaken(p2) == 10&& HowManyCardsHave(p1) == 21 && HowManyCardsHave(p2) == 31);
    CHECK(case1 || case2 || case3 || case4 || case5 || case6);
}
TEST_CASE("Test Number5 - Play All"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(HowManyCardsInPile(g) == 52);
    CHECK(HowManyCardsInDeck(g) == 0);
}
TEST_CASE("Test Number6 - Print Last Turn"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playTurn();
    g.printLastTurn();
    CHECK(HowManyCardsInPile(g) == 2);
    CHECK(HowManyCardsInDeck(g) == 50);
}
TEST_CASE("Test Number7 - Print Winer"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    g.printWiner();
    CHECK(HowManyCardsInPile(g) == 52);
    CHECK(HowManyCardsInDeck(g) == 0);
}
TEST_CASE("Test Number8 - Print Log"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    g.printLog();
    CHECK(HowManyCardsInPile(g) == 52);
    CHECK(HowManyCardsInDeck(g) == 0);
}
TEST_CASE("Test Number9 - Print Stats"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    g.printStats();
    CHECK(HowManyCardsInPile(g) == 52);
    CHECK(HowManyCardsInDeck(g) == 0);
}
TEST_CASE("Test Number10 - Print Game"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    g.printGame();
    CHECK(HowManyCardsInPile(g) == 52);
    CHECK(HowManyCardsInDeck(g) == 0);
}
TEST_CASE("Test Number11 - Print Player"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    g.printPlayer(p1);
    CHECK(HowManyCardsInPile(g) == 52);
    CHECK(HowManyCardsInDeck(g) == 0);
}
TEST_CASE("Test Number12 - Print Card"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    g.printCard(g.getCardFromDeck());
    CHECK(HowManyCardsInPile(g) == 52);
    CHECK(HowManyCardsInDeck(g) == 0);
}
TEST_CASE("Test Number13 - Is Card In Discard"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(IsCardInDiscard(p1, g.getCardFromPile()));
    CHECK(IsCardInDiscard(p2, g.getCardFromPile()));
    CHECK(!IsCardInDiscard(p1, g.getCardFromDeck()));
    CHECK(!IsCardInDiscard(p2, g.getCardFromDeck()));
}
TEST_CASE("Test Number14 - Is Card In Deck"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(IsCardInDeck(g, g.getCardFromDeck()));
    CHECK(!IsCardInDeck(g, g.getCardFromPile()));
}
TEST_CASE("Test Number15 - Is Card In Hand"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(IsCardInHand(p1, g.getCardFromDeck()));
    CHECK(IsCardInHand(p2, g.getCardFromDeck()));
    CHECK(!IsCardInHand(p1, g.getCardFromPile()));
    CHECK(!IsCardInHand(p2, g.getCardFromPile()));
}
TEST_CASE("Test Number16 - Is Card In Pile"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(IsCardInPile(g, g.getCardFromPile()));
    CHECK(!IsCardInPile(g, g.getCardFromDeck()));
}
TEST_CASE("Test Number17 - Is Card In Player"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(IsCardInPlayer(p1, g.getCardFromDeck()));
    CHECK(IsCardInPlayer(p2, g.getCardFromDeck()));
    CHECK(!IsCardInPlayer(p1, g.getCardFromPile()));
    CHECK(!IsCardInPlayer(p2, g.getCardFromPile()));
}
TEST_CASE("Test Number18 - Is Card In Taken"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(IsCardInTaken(p1, g.getCardFromPile()));
    CHECK(IsCardInTaken(p2, g.getCardFromPile()));
    CHECK(!IsCardInTaken(p1, g.getCardFromDeck()));
    CHECK(!IsCardInTaken(p2, g.getCardFromDeck()));
}
TEST_CASE("Test Number19 - Is Card In Player Hand"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(IsCardInPlayerHand(p1, g.getCardFromDeck()));
    CHECK(IsCardInPlayerHand(p2, g.getCardFromDeck()));
    CHECK(!IsCardInPlayerHand(p1, g.getCardFromPile()));
    CHECK(!IsCardInPlayerHand(p2, g.getCardFromPile()));
}
TEST_CASE("Test Number20 - Is Card In Player Discard"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    g.playAll();
    CHECK(IsCardInPlayerDiscard(p1, g.getCardFromPile()));
    CHECK(IsCardInPlayerDiscard(p2, g.getCardFromPile()));
    CHECK(!IsCardInPlayerDiscard(p1, g.getCardFromDeck()));
    CHECK(!IsCardInPlayerDiscard(p2, g.getCardFromDeck()));
}




