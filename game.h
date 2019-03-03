/*
  Sohrab Roohi
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;

class game {
    private:
    bool nflag;
    bool uflag;
    bool nextMove;
    vector<vector<char>> grid;
    stack<pair<int,int>> moveList;
    void gridSetup();

    public:
    game(bool playerFirst);
    game(const game &o);
    bool makeMove(int i, int j, bool player, bool theory);
    bool undo();
    void newGame();
    string getCommand();
    void printGrid();
    bool getTurn();
    bool getnewflag();
    void setnewflag(bool flag);
    bool getundoflag();
    void setundoflag(bool flag);
    bool checkForWin(bool player);
};