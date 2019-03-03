/*
  Sohrab Roohi
*/

#include <bits/stdc++.h>
#include "AI.h"

using namespace std;

typedef long long int int64;

void AI::makeMove(game &g) {
    pair<int,int> bad = make_pair(-1,-1);
    pair<int,int> w = win(g);
    if(w != bad) {
        g.makeMove(w.first,w.second,false,false);
        return;
    }
    pair<int,int> b = block(g);
    if(b != bad) {
        g.makeMove(b.first,b.second,false,false);
        return;
    }
    pair<int,int> f = fork(g);
    if(f != bad) {
        g.makeMove(f.first,f.second,false,false);
        return;
    }
    pair<int,int> bb = doubleBlock(g);
    if(bb != bad) {
        g.makeMove(bb.first,bb.second,false,false);
        return;
    }
    pair<int,int> n = neutral(g);
    g.makeMove(n.first,n.second,false,false);
}

pair<int,int> AI::win(game g) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            game o(g);
            if(o.makeMove(i,j, false, true)) {
                if(o.checkForWin(false)) {
                    return make_pair(i,j);
                }
            }
        }
    }
    return make_pair(-1,-1);
}

pair<int,int> AI::block(game g) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            game o(g);
            if(o.makeMove(i,j, true, true)) {
                if(o.checkForWin(true)) {
                    return make_pair(i,j);
                }
            }
        }
    }
    return make_pair(-1,-1);
}

pair<int,int> AI::doubleBlock(game g) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            game o(g);
            if(o.makeMove(i,j, true, true)) {
                int count = 0;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        game f(o);
                        if(f.makeMove(k,l, true, true)) {
                            if(f.checkForWin(true)) {
                                count++;
                            }
                        }
                    }
                }
                if(count >= 2) {
                    return make_pair(i, j);
                }
            }
        }
    }
    return make_pair(-1,-1);
}

pair<int,int> AI::fork(game g) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            game o(g);
            if(o.makeMove(i,j, false, true)) {
                int count = 0;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        game f(o);
                        if(f.makeMove(k,l, false, true)) {
                            if(f.checkForWin(false)) {
                                count++;
                            }
                        }
                    }
                }
                if(count >= 2) {
                    return make_pair(i, j);
                }
            }
        }
    }
    return make_pair(-1,-1);
}

pair<int,int> AI::neutral(game g) {
    if(g.makeMove(1,1,false,true)) {
        return make_pair(1,1);
    }
    vector<pair<int,int>> p = {{0,0}, {0,2}, {2,0}, {2,2}};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(p.begin(),p.end(),default_random_engine(seed));
    for(int i = 0; i < 4; i++) {
        if(g.makeMove(p[i].first, p[i].second, false, true)) {
            return make_pair(p[i].first, p[i].second);
        }
    }
    int i, j;
    srand(time(NULL));
    do {
        i = rand() % 2;
        j = rand() % 2;
    }
    while(!g.makeMove(i,j,false, true));
    return make_pair(i, j);

}