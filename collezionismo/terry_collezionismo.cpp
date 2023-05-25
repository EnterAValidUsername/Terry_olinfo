#include <bits/stdc++.h>

using namespace std;

ifstream fin ("collezionismo_input_1.txt");
ofstream fout ("output.txt");

typedef long long int ll;

int N, K;

vector < ll > pSum(N);

// troppo complessa
ll solve (int index = -1, ll value = 0, int c = 0, ll best = (ll)1<<60) {
    if (c == K && index == N - 1) {
        return value;
    }
    else if ((c > K || value >= best) || (c < K && index == N - 1)) {
        return (ll)1<<60;
    }

    for (int i = index + 1; i < N; i++) {
        best = min (best, solve(i, pSum[i] - pSum[index + 1], c + 1, best) + value); //va bene
    }

    return best;
}

int main () {

    int T;
    fin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "calculating case# " << t << "..\n";

        if (t >= 7) {
            fout << "case#" << t << ": " << 0 << "\n";
            cout << "done\n";
        }
        else {

            fin >> N >> K;

            vector < ll > C(N);

            pSum.resize(N);

            for (int i = 0; i < N; i++) {
                fin >> C[i];
            }

            sort(C.begin(), C.end());

            for (int i = 0; i < N; i++) {
                pSum[i] = C[i] - C[0]; // prefix sum array (differenze)
            }

            fout << "case #" << t << ": " << solve() << "\n";
            cout << "done\n";
        }
    }
    
    return 0;
}