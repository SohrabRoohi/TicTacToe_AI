/*
  Sohrab Roohi
*/

#include <bits/stdc++.h>
#include "GameManager.h"

using namespace std;

typedef long long int int64;

bool GameManager::checkWon(bool player) {
    if(g.checkForWin(player)) {
        if(player) {
            cout << "You win!" << endl;
        }
        else {
            cout << "You Lose!" << endl;
        }
        g.printGrid();
        g.newGame();
        g.setnewflag(false);
        return true;
    }
    return false;
}

bool GameManager::checkDraw() {
    if(g.checkForDraw()) {
        cout << "It's a draw!" << endl;
        g.printGrid();
        g.newGame();
        g.setnewflag(false);
        return true;
    }
    return false;
}

bool GameManager::newCheck() {
    if(g.getnewflag()) {
        g.setnewflag(false);
        return true;
    }
    return false;
}

bool GameManager::undoCheck() {
    if(g.getundoflag()) {
        g.setundoflag(false);
        return true;
    }
    return false;
}