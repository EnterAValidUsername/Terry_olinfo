#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ifstream fin ("caramelle_input_1.txt");
ofstream fout ("output.txt");

map < long long int, int > fact (long long int n) {
	map < long long int, int > facts;
	
	for (long long int i = 2; i*i <= n; i++) {
		while (n % i == 0) {
			if (facts.count(i) == -1) {
				facts.insert(pair < long long int, int > (i, 1));
			}
			else {
				facts[i]++;
			}
			n /= i;
		}
	}
	
	if (n > 1) facts.insert(pair < long long int, int > (n, 1));
	return facts;
}

int main () {
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		int n;
		fin >> n;
		
		long long int a[n];
		
		for (int i = 0; i < n; i++) {
			fin >> a[i];
		}
		
		map < long long int, int > facts, temp;
		
		for (int i = 0; i < n; i++) {
			temp = fact(a[i]);
			
			for (map < long long int, int > :: iterator j = temp.begin(); j != temp.end(); j++) {
				if (facts.count(j -> first) >= 1) {
					facts[j -> first] = max(facts[j -> first], temp[j -> first]);
				}
				else {
					facts.insert(pair < long long int, int > (j -> first, 1));
				}
			}
		}
		
		unsigned long long int ans = 1;
		map < long long int, int > :: iterator it;
		
		for (it  = facts.begin(); it != facts.end(); it++) {
			ans *= pow(it -> first, it -> second);
		}
		
		fout << "case #" << t << ": " << ans << "\n";
	}
	
	return 0;
}
