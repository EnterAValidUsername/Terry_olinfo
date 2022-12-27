#include <bits/stdc++.h>
using namespace std;

ifstream fin ("pile_input_1.txt");
ofstream fout ("output.txt");

int main () {
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		
		int N, ans = 0, temp = 0;
		int x, y, z;
		fin >> N;
		
		for (int i = 0; i < N; i++) {
			fin >> x >> y >> z;
			temp = x;
			temp = max(temp, y);
			temp = max(temp, z);
			
			ans += temp;
			temp = 0;
		}
		
		fout << "case #" << t << ": " << ans << "\n";
	}

return 0;
}

