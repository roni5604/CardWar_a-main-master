
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include <iostream>
#include <stack>

using namespace std;
using namespace ariel;

TEST_CASE("Test 1- Initalization of the game ")
{
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    CHECK(g.get_p1_stacksize() == 26);
    CHECK(g.get_p2_stacksize() == 26);
    CHECK(g.get_p1_cardsTaken() == 0);
    CHECK(g.get_p2_cardsTaken() == 0);
    CHECK(g.get_p1_stacksize() + g.get_p2_stacksize() == 52);
}

TEST_CASE("Test 2 - play one turn ")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playTurn();
    bool bob_won = (g.get_p1_cardsTaken() >= 1 && g.get_p2_cardsTaken() == 0);
    bool alice_won = (g.get_p2_cardsTaken() >= 1 && g.get_p1_cardsTaken() == 0);
    bool tie = (g.get_p1_cardsTaken() == 0 && g.get_p2_cardsTaken() == 0);
    bool valid = (bob_won || alice_won || tie);
    CHECK(valid);
}

TEST_CASE("Test 3 - play all turns ")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
    bool bob_won = (g.get_p1_cardsTaken() > g.get_p2_cardsTaken());
    bool alice_won = (g.get_p2_cardsTaken() > g.get_p1_cardsTaken());
    bool tie = (g.get_p1_cardsTaken() == g.get_p2_cardsTaken());
    bool valid = (bob_won || alice_won || tie);
    CHECK(valid);
}

TEST_CASE("Test 4 - print last turn ")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playTurn();
    
    CHECK_NOTHROW(g.printLastTurn());
    
}
TEST_CASE("Test 5 - print winner ")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
 
    CHECK_NOTHROW(g.printWiner());
}
TEST_CASE("Test 6 - print good log ")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
    CHECK_NOTHROW(g.printLog());
}
TEST_CASE("Test 7 - print is good stats ")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
    CHECK_NOTHROW(g.printStats());
}

TEST_CASE("Test 8 - someone is out of cards ")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
    bool bob_won = (g.get_p1_cardsTaken() > g.get_p2_cardsTaken());
    bool alice_won = (g.get_p2_cardsTaken() > g.get_p1_cardsTaken());
    bool tie = (g.get_p1_cardsTaken() == g.get_p2_cardsTaken());
    bool valid = (bob_won || alice_won || tie);
    CHECK(valid);
}

TEST_CASE("Test 9 - if the pile is even")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playTurn();
    bool someone_take_even = ((g.get_p1_cardsTaken() % 2 == 0) && (g.get_p2_cardsTaken() % 2 == 0));
    CHECK(someone_take_even);
}

TEST_CASE("Test 10 - legal turn")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playTurn();
    bool legal_cards = ((g.get_p1_cardsTaken() == 2) || (g.get_p2_cardsTaken() == 2));
    bool legal_tie = ((g.get_p1_cardsTaken()%3 == 0) || (g.get_p2_cardsTaken()%3 == 0));
    bool legal_turn = (legal_cards || legal_tie);
    CHECK(legal_turn);
}

TEST_CASE("Test 11 - pop works")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    CHECK_NOTHROW(p1.pop_pile());
    CHECK_NOTHROW(p2.pop_pile());
}

TEST_CASE("Test 12 - push works")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    std::stack<Card> myStack;
    myStack.push(p1.pop_pile());
    myStack.push(p2.pop_pile());
    CHECK_NOTHROW(p1.push_pile(myStack));
    CHECK_NOTHROW(p2.push_pile(myStack));
}

TEST_CASE("Test 13 - card info is work")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    Card c = p1.pop_pile();
    CHECK_NOTHROW(c.getCardInfo());
}

TEST_CASE("Test 14 - there is a tie")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    CHECK_NOTHROW(g.there_is_a_tie());
}

TEST_CASE("Test 15 - check if return my cards")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    CHECK_NOTHROW(p1.getMyCards());
    CHECK_NOTHROW(p2.getMyCards());
    CHECK(p1.getMyCards().size() == 26);
    CHECK(p2.getMyCards().size() == 26);
}
TEST_CASE("Test 16 - check if return my cards after turn")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playTurn();
    CHECK_NOTHROW(p1.getMyCards());
    CHECK_NOTHROW(p2.getMyCards());
}
TEST_CASE("Test 17 - check if return my cards after all turns")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
    CHECK_NOTHROW(p1.getMyCards());
    CHECK_NOTHROW(p2.getMyCards());
}
TEST_CASE("Test 18 - check if return my cards after all turns")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
    CHECK_NOTHROW(p1.getMyCards());
    CHECK_NOTHROW(p2.getMyCards());
}
TEST_CASE("Test 19 - check end point")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
    CHECK_NOTHROW(g.playTurn());
}
TEST_CASE("Test 20 - check end point")
{
    Player p1("bob");
    Player p2("alice");
    Game g(p1, p2);
    g.playAll();
    CHECK_NOTHROW(g.playAll());
}









