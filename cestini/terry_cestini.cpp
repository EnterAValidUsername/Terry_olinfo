#include <bits/stdc++.h>
using namespace std;

ifstream fin ("cestini_input_1.txt");
ofstream fout ("output.txt");

int main () {
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		int N, M, Q;
		string oggetti, ans = "";
		vector < vector < char > > cestini;
		
		fin >> N >> M >> Q;
		fin >> oggetti;
		
		cestini.resize(M);
		
		for (int i = 0; i < N; i++) {
			cestini[0].push_back(oggetti[i]);
		}
		
		for (int i = 0; i < Q; i++) {
			char cmd;
			int primo, secondo;
			
			fin >> cmd >> primo >> secondo;
			//fout << cmd << " ";
			
			if (cmd == 's') {
				//fout << "cmd == s: " << primo << ", " << secondo << "\n";
				cestini[secondo].push_back(cestini[primo][cestini[primo].size() - 1]);
				cestini[primo].pop_back();
			}
			
			if (cmd == 'c') {
				//fout << "cmd == c: " << primo << ", " << secondo << "\n";
				ans += cestini[primo][secondo];
			}
		}
		
		fout << "case #" << t << ": " << ans << "\n";
	}

return 0;
}

