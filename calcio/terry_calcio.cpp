#include <bits/stdc++.h>
using namespace std;

ifstream fin ("calcio_input_1.txt");
ofstream fout ("output.txt");

int main () {
	
	// va ma è troppo lento
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
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
		
		// - - - - - - - - - - - - - - - - - - -
		
		/*
		l'idea è quella di inserire una matrice AxB nella matrice NxM la quale parta dalla cella 0,0 di NxM;
		cercare poi se è vantagggioso spostarla di 1 colonna a destra piuttosto che di una riga in giù finché
		non sarà più conveniente fare spostamenti.
		
		problemi: ponendo il caso che ci sia un aagglomerato denso di alberi in un punto della foresta il quale 
		impedisca di spostare vantaggiosamente AxB ma che la soluzione sia dopo questo agglomerato allora
		la soluzione fallirebbe; tuttavia è possibile controllare le soluzioni dai 4 angoli, questo però invece che richiedere
		N * M * (tot1*A + tot2*B), ne richiederebbe il quadruplo
		*/
		
		int x = 0, y = 0; // indici della prima cella della matrice AxB
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				
			}
		}
		
		cout << "case #" << t << ": " << ans << "\n";
	}

return 0;
}

