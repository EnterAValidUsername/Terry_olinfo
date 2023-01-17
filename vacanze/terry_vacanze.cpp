#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");

int N, M;
vector < vector < int > > graph;

bool solve(int node) {
    if (graph[node].size() >= 2) {
        int n = graph[node].size();

        for (int i = 0; i < n; i++) {
            solve(graph[node][i]); 
            // solve ancora non fa nulla e questa chiamata momentaneamente è inutile
            // per ora li controlla tutti poi conclude tutte le chiamate con false
        }
    }

    return false;
}

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