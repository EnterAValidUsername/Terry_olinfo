#include <bits/stdc++.h>
using namespace std;

ifstream fin ("pesci_input_1.txt");
ofstream fout ("output.txt");

int main () {
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		long long int N, K;
		long long int ans = 0, pesci;
		
		fin >> N >> K;
		pesci = N;
		
		int uova = 0;
		while (pesci >= K) {
			uova = pesci / K;
			ans += pesci;
			pesci = uova;
		}
		
		ans += pesci;
		
		fout << "case #" << t << ": " << ans << "\n";
	}

return 0;
}

