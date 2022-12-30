#include <bits/stdc++.h>
using namespace std;

ifstream fin ("fortuna_input_1.txt");
ofstream fout ("output.txt");

int main () {

	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		int N;
		fin >> N;
		
		vector < int > prizes(N); // ruota
		vector < int > placement(N); // fisso
		
		for (int i = 0; i < N; i++) {
			fin >> prizes[i];
		}
		for (int i = 0; i < N; i++) {
			fin >> placement[i];
		}
		
		// - - - - - - - - - - - - - - - - - - - - - -
		
		int best = 1<<30, temp = 0;
		
		for (int i = 0; i < N; i++) { // la ruota fa 1 solo giro quidi devo ruotare tutto solo N - 1 volte per ottenere N layouts
			temp = 0;
			for (int j = 0; j < N; j++) { // ad ogni giro della ruota devo calcolare i premi e confrontare se questi sono più bassi di quelli già ottenuti
				temp += prizes[(j + i) % N] * placement[j];
			}
			best = min(best, temp);
		}
		
		fout << "case #" << t << ": " << best << "\n";
	}

return 0;
}

