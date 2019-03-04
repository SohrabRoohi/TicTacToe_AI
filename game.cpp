/*
  Sohrab Roohi
*/

#include <bits/stdc++.h>
#include "game.h"

using namespace std;

typedef long long int int64;

void game::gridSetup() {
    grid.assign(3, vector<char>(3, '-'));
}

game::game(bool playerFirst) {
    nextMove = playerFirst;
    gridSetup();
    nflag = false;
    uflag = false;
}

game::game(const game &o) {
    grid = o.grid;
    nextMove = o.nextMove;
    moveList = o.moveList;
    nflag = false;
}

bool game::makeMove(int i, int j, bool player, bool theory) {
    if(i < 0 || j < 0 || i >= 3 || j >= 3) {
        cout << "Invalid position" << endl;
        return false;
    }
    if(grid[i][j] != '-') {
        if(!theory) {
            cout << "Position already has move" << endl;
        }
        return false;
    }
    char move = player ? 'X' : 'O';
    grid[i][j] = move;
    moveList.push(make_pair(i,j));
    return true;
}

bool game::undo() {
    if(moveList.size() < 2) {
        cout << "Unable to undo" << endl;
        return false;
    }
    pair<int,int> first = moveList.top();
    moveList.pop();
    pair<int,int> second = moveList.top();
    moveList.pop();
    grid[first.first][first.second] = '-';
    grid[second.first][second.second] = '-';
    uflag = true;
    nextMove = true;
    return true;
}

void game::newGame() {
    cout << "-------------------------------------------------------------" << endl << "NEW GAME" << endl << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            grid[i][j] = '-';
        }
    }
    moveList = stack<pair<int,int>>();
    nextMove = !nextMove;
    nflag = true;
}

bool game::checkForWin(bool player) {
    char move = player ? 'X' : 'O';
    for(int i = 0; i < 3; i++) {
        int count = 0;
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] == move) {
                count++;
            }
        }
        if(count == 3) {
            return true;
        }
    }
    for(int i = 0; i < 3; i++) {
        int count = 0;
        for(int j = 0; j < 3; j++) {
            if(grid[j][i] == move) {
                count++;
            }
        }
        if(count == 3) {
            return true;
        }
    }
    if((grid[0][0] == move && grid[1][1] == move && grid[2][2] == move) || (grid[2][0] == move && grid[1][1] == move && grid[0][2] == move)) {
        return true;
    }
    return false;
}

string game::getCommand() {
    string command;
    int count = 0;
    do {
        if(count) {
            cout << "Invalid command!" << endl;
        }
        cout << "Please enter a command. move/undo/new/exit" << endl;
        cin >> command;
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        count++;
    }
    while(command != "move" && command != "undo" && command != "new" && command != "exit");
    cout << endl;
    return command;
}

void game::printGrid() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool game::getTurn() {
    return nextMove;
}

bool game::getnewflag() {
    return nflag;
}

bool game::getundoflag() {
    return uflag;
}

void game::setundoflag(bool flag) {
    uflag = flag;
}

void game::setnewflag(bool flag) {
    nflag = flag;
}

bool game::checkForDraw() {
    return moveList.size() == 9 && !checkForWin(true) && !checkForWin(false);
}


