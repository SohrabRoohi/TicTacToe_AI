/*
  Sohrab Roohi
*/
#pragma once
#include <bits/stdc++.h>
#include "game.h"

using namespace std;

typedef long long int int64;

class GameManager {
private:
    game &g;
public:
    GameManager(game &g):g(g){};
    bool checkWon(bool player);
    bool checkDraw();
    bool newCheck();
    bool undoCheck();
};