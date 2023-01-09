#include <bits/stdc++.h>
using namespace std;

ifstream fin ("calcio_input_1.txt");
ofstream fout ("output.txt");

int main () {
	
	// va ma è troppo lento, i tempi "ragionevoli" si fermano al case 10
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		cout << "calculating case #" << t << "...\n";
		
		int N, M, K, A, B;
		fin >> N >> M >> K >> A >> B;
		
		vector < vector < int > > alberi(N);
		
		for (int i = 0; i < N; i++) {
			alberi[i].resize(M);
			
			for (int j = 0; j < M; j++) {
				alberi[i][j] = 0;
			}
		}
		
		for (int i = 0; i < K; i++) {
			int x, y;
			fin >> x >> y;
			
			alberi[x][y]++;
		}
		
		// input
		// - - - - - - - - - - - - - - - - - - -
		// calcoli
		
		int CurMatrice, ans = 1<<30;
		
		for (int i = 0; i <= N - A; i++) {
			
			CurMatrice = 0;
			
			for (int k = i; k < A + i; k++) {
				for (int l = 0; l < B; l++) {
					CurMatrice += alberi[k][l];
				}
			}
			
			ans = min(ans, CurMatrice);
			
			for (int j = B; j < M; j++) {
				for (int pi = i; pi < A + i; pi++) {
					CurMatrice += alberi[pi][j];
					CurMatrice -= alberi[pi][j - B];
				}
				
				ans = min(ans, CurMatrice);
			}
		}
		
		fout << "case #" << t << ": " << ans << "\n";
	}

return 0;
}

