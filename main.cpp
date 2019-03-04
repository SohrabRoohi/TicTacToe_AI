/*
  Sohrab Roohi
*/
#pragma once
#include <bits/stdc++.h>
#include "AI.h"
#include "GameManager.h"

using namespace std;

const double pi=acos(-1.0);
typedef long long int int64;

bool doCommand(game &g) {
    string command = g.getCommand();
    if(command == "move") {
        cout << "Input two space seperated integers from (1-3) representing row and column." << endl;
        int R, C;
        cin >> R >> C;
        if(R < 1 || R > 3 || C < 1 || C > 3) {
            return false;
        }
        return g.makeMove(R-1,C-1,true, false);
    }
    else if(command == "undo") {
        return g.undo();
    }
    else if(command == "new") {
        g.newGame();
        return true;
    }
    else if(command == "exit") {
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    game g(true);
    AI AI;
    GameManager manager(g);

    while(true) {
        if(g.getTurn()) {
            g.printGrid();
            while(!doCommand(g));
            if(manager.checkWon(true)) continue;
            if(manager.checkDraw()) continue;
            if(manager.newCheck()) continue;
            if(manager.undoCheck()) continue;
            AI.makeMove(g);
            if(manager.checkWon(false)) continue;
            if(manager.checkDraw()) continue;
        }
        else {
            AI.makeMove(g);
            if(manager.checkWon(false)) continue;
            if(manager.checkDraw()) continue;
            g.printGrid();
            while(!doCommand(g));
            if(manager.checkWon(true)) continue;
            if(manager.newCheck()) continue;
            if(manager.undoCheck()) continue;
            if(manager.checkDraw()) continue;
        }
    }

    return 0;
}
