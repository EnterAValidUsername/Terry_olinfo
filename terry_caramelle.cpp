#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#ifdef EVAL
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define cin fin
#define cout fout
#endif

int main() {
	
	int T; // testcases
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int N; // number of teams
		ll V[N]; // number of players per team (the i-th team will have V[i] players
		
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> V[i];
		}
		
		// N è massimo 1000, quindi una soluzione quadratica non sarebbe da scartare
		// V[i] è al massimo 10^9 quindi è impensabile cercare la scomposizione in fattori primi del singolo
		
		multiset < ll > divisori;
		
		for (int i = 0; i < N; i++) {
			int num = V[i];
			
			while (num != 1) {
				if (divisori.size() != 0) {
					for (multiset < ll > :: iterator j = divisori.begin(); j != divisori.end(); j++) {
						if (num % *j == 0) {
							num /= *j;
							divisori.insert(*j);
						}
					}
				}
				
				int j = 2;
				while (num % j != 0) {
					num++;
				}
				num /= j;
				divisori.insert(j);
				j = 0;
			}
		}
		
		int ans = 1;
		
		for (multiset < ll > :: iterator i = divisori.begin(); i != divisori.end(); i++) {
			ans *= pow(*i, divisori.count(*i));
		}
		
		cout << "Case #" << t << ": " << ans << "\n";
	}
	
	// con i set l'idea c'era e "andava", logicamente era sbagliata, ho provato coi multi set ma ha fatto schifo, ma non è male

	return 0;
}

