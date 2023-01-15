#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");

int main () {
    int T;
    fin >> T;

    for (int t = 0; t < T; t++) {
        int N, M; // N = numero amici, M = numero di legami tra di essi
        fin >> N >> M;

        vector < vector < int > > graph(M);

        int i, x;
        for (int i = 0; i < M; i++) {
            fin >> i >> x;

            graph[i].push_back(x);
        }

        
    }
    
    return 0;
}