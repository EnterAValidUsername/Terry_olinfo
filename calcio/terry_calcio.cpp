#include <bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main () {
	int T;
	fin >> T;
	
	for (int t = 0; t < T; t++) {
		int N, M, K, A, B;
		fin >> N >> M >> K >> A >> B;
		
		vector < vector < int > > grid(N);
		
		for (int i = 0; i < N; i++) {
			grid[i].resize(M);
			
			for (int j = 0; j < M; j++) {
				grid[i][j] = 0;
			}
		}
		
		for (int i = 0; i < K; i++) {
			int x, y;
			fin >> x >> y;
			
			grid[x][y]++;
		}
		
		
		//
		
		cout << "case #" << t << ": " /*<< ans*/ << "\n";
	}

return 0;
}

