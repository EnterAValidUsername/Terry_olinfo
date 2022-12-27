#include <bits/stdc++.h>
using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main () {
	
	// this is the best i could do, it returns 3221225620
	
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
							
							for (int k = 0; k < N; k++) {
								if (a[k].second && a[k].first % a[j].first == 0) {
									a[k].first /= a[j].first;
								}
							}
						}
					}
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (a[i].second) {
				ans *= a[i].second;
			}
		}
		
		fout << "case #" << t << ": " << ans << "\n";
		
	}
	
	return 0;
}
