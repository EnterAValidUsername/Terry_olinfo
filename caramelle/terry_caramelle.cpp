#include <bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main () {
	
	int T;
	fin >> T;
	
	for (int t = 0; t < T; t++) {
		int N;
		fin >> N;
		
		vector < pair < long long int, bool > > a(N);
		
		for (int i = 0; i < N; i++) {
			fin >> a[i].first;
			a[i].second = true;
		}
		
		long long int ans = 1;
		
		for (int i = 0; i < N; i++) {
			if (a[i].second || a[i].first != 1) {
				for (int j = 0; j < N; j++) {
					if (a[j].second || a[j].first != 1 || a[j].first != a[i].first) {
						if (a[i].first % a[j].second == 0) {
							a[j].second = false;
							
							// ok più o meno l'idea c'e ma manca un pezzo fondamentale:
							/*
								all fine io avrò tutti i numeri più grossi
								i quali potevano essere divisi da altri 
								numeri presenti nella lista, tuttavia 
								questo ragionamento porterebbe ad avere:
								
								utilizzando la lista:
								4 5 2 5 10, i numeri 4 e 10 come restanti, ma il numero
								minimo di caramelle di questo caso non è 40 bensì 20
								
								quindi al momento è incorretto
							*/
						}
					}
				}
			}
		}
		
		// don't mind this line of code,is purpouseless
		fout << "case #" << t << ": " << ans << "\n";
		
	}
	
	return 0;
}
