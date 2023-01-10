#include <bits/stdc++.h>
using namespace std;

ifstream fin ("calcio_input_1.txt");
ofstream fout ("output.txt");

//typedef long long int ll;

int main () {
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		
		/*if (t == 12) {
			for (int i = 0; i < 5; i++) {
				fout << "case #" << t << ": " << 0 << "\n";
			}
			return 0;
		}*/
		cout << "calculating case #" << t << "...\n";
		
		int N, M, K, A, B;
		fin >> N >> M >> K >> A >> B;
		
		map < pair < int, int >, int > matrices;
		
		for (int i = 0; i < N - A; i++) {
			
			for (int j = 0; j < M - B; j++) {
				matrices[{i, j}] = 0;
			}
		}
		
		for (int i = 0; i < K; i++) {
			int x, y;
			fin >> x >> y;
			
			for (int k = A + x/2; k > x/2; k++) {
				for (int h = B + y; h > y; h++) {
					matrices[{k, h}]++;
				}
			}
		}
		
		vector < int > temp;
		for (auto i: matrices) {
			temp.push_back(i.second);
		}
		
		sort(temp.begin(), temp.end());
		
		fout << "case #" << t << ": " << temp[0] << "\n";
	}

return 0;
}

