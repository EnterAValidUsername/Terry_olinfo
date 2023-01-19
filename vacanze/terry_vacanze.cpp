#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");

// complesso come il cristo 

int N, M, ans = 0;
vector < vector < int > > graph;
map < vector < int >, bool > visited;


int main () {
    int T;
    fin >> T;

    for (int t = 0; t < T; t++) {
        fin >> N >> M;

        graph.resize(N);

        int i, x;
        for (int i = 0; i < M; i++) {
            fin >> i >> x;

            graph[i].push_back(x);
        }
    }
    
    return 0;
}