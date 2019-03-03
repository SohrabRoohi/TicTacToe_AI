/*
  Sohrab Roohi
*/

#include <bits/stdc++.h>
#include "game.h"

using namespace std;

typedef long long int int64;

class AI {
    private:
    pair<int,int> block(game g);
    pair<int,int> doubleBlock(game g);
    pair<int,int> win(game g);
    pair<int,int> fork(game g);
    pair<int,int> neutral(game g);

    public:
    AI(){}
    void makeMove(game &g);
};