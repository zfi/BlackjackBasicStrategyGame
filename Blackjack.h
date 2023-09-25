#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Blackjack
{
  public:
    void blackjackGame();

  private:
    int randomCard();
    int calcTotal(const vector<int>& hand);
    char toUpperCase(char choice);

};
