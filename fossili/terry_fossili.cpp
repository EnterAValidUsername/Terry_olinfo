#include<bits/stdc++.h>
using namespace std;

ifstream fin ("fossili_input_1.txt");
ofstream fout ("output.txt");

int main() {
	
	unsigned long long int first, last, last_born = -1, first_death = (long long int)1<<60;
	int T;
	string trash;
	fin >> T;
	
	
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 3; i++) {
			fin >> first >> last;
			if (last_born == -1) {
				last_born = first;
			}
			if (first_death == (long long int)1<<60) {
				first_death = last;
			}
			
			last_born = max(last_born, first);
			first_death = min(first_death, last);
		}
		
		fout << "case #" << t << ": " << (unsigned long long int)(first_death - last_born) << "\n";
		
		last_born = -1;
		first_death = -1;
	
	}

	return 0;
}

