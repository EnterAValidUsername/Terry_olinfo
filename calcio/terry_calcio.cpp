#include <bits/stdc++.h>
using namespace std;

ifstream fin ("calcio_input_1.txt");
ofstream fout ("output.txt");

// page 85 Competitive Programmer's Handbook -Antti Laaksonen

int main () {
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		cout << "calculating case #" << t << "...\n";
		
		int N, M, K, A, B;
		fin >> N >> M >> K >> A >> B;

		vector < vector < int > > m(N);

		for (int i = 0; i < N; i++) {
			m[i].resize(M);
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				m[i][j] = 0;
			}
		}
		
		// segno dove sono presenti gli alberi

		int x, y;
		for (int i = 0; i < K; i++) {
			fin >> x >> y;
			m[x][y]++;
		}

		// creo la matrice somma per le queries succcessive
		vector < vector < int > > Sum(N + 1); // 1 index, tutti gli indici 0 valgono 0

		for (int i = 0; i < N + 1; i++) {
			Sum[i].resize(M + 1);
		}

		for (int i = 0; i < N + 1; i++) {
			Sum[i][0] = 0;
		}
		for (int j = 0; j < M + 1; j++) {
			Sum[0][j] = 0;
		}
		
		
		for (int i = 1; i <= N; i++) {
			int temp = 0;
			for (int j = 1; j <= M; j++) {
				temp += m[i - 1][j - 1];
				Sum[i][j] = temp + Sum[i - 1][j]; // somma della cella soprastante, corrispondente al subarray rettangolare meno una riga + tutta la riga
			}
		}
				
		int ans = 1<<30;
		for (int i = A; i <= N; i++) {
			for (int j = B; j <= M; j++) {
				ans = min(Sum[i][j] - Sum[i][j - B] - Sum[i - A][j] + Sum[i - A][j - B], ans);
			}
		}
		
		fout << "case #" << t << ": " << ans << "\n";
	}

return 0;
}


