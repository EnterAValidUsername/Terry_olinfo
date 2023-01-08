#include <bits/stdc++.h>
using namespace std;

ifstream fin ("calcio_input_1.txt");
ofstream fout ("output.txt");

int main () {
	
	// va ma è troppo lento
	
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
		
		for (int ii = 0; ii < N; ii++) {
			for (int jj = 0; jj < M; jj++) {
				cout << alberi[ii][jj] << " ";				
			}
			cout << "\n";
		}
		
		cout << "\n";
		
		// input
		// - - - - - - - - - - - - - - - - - - -
		// calcoli
		
		int CurMatrice = 0, ans = 1<<30;
		
		for (int i = 0; i <= N - A; i++) {
			
			for (int k = i; k < A + i; k++) {
				for (int l = 0; l < B; l++) {
					CurMatrice += alberi[k][l];
				}
			}
			
			ans = min(ans, CurMatrice);
			cout << "\nans: " << ans << ", setup\n";
			
			for (int j = B; j < M; j++) {
				cout << "\nrimuovendo la colonna " << j - B << ", aggiungendo la colonna " << j;
				for (int pi = i; pi <= A + i && cout << "\n" << pi << " " ; pi++) {
					CurMatrice -= alberi[pi][j];
					CurMatrice += alberi[pi][j - B]; //non accede all'ultima cella
					cout << "cazzo";
				}
				cout << "\n";
				
				ans = min(ans, CurMatrice);
				cout << "\nans: " << ans << "\n- - - - - - - - - - - - - - - - - - -\n";
			}
		}
		
		cout << "case #" << t << ": " << ans << "\n";
	}

return 0;
}

