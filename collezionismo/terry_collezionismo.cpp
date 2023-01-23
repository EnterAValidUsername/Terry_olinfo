#include <bits/stdc++.h>

using namespace std;

ifstream fin ("collezionismo_input_1.txt");
ofstream fout ("output.txt");

typedef long long int ll;

int N, K;

vector < ll > pSum(N);

ll solve (int index = 0, ll value = 0, int c = 0, ll best = (ll)1<<60) {
    cout << "call:\n";
    if (c == K && index == N - 1) {
        //
        cout << "done\n";
        //
        return value;
    }
    else if ((c > K || value >= best) || (c < K && index == N - 1)) {
        //
        cout << "calcolo inutile skippato" << "\n";
        //
        return (ll)1<<60;
    }

    for (int i = index; i < N; i++) {
        //
        cout << "loop: {" << index << ", " << i << "}\n";
        //
        best = min (best, solve(i + 1, pSum[i] - pSum[index], c + 1, best) + value); //va bene
        cout << "best: " << best << "\n";
    }

    return best;
}

// si ferma al primo test case il cui risultato è sempre 1<<60
int main () {

    int T;
    fin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "calculating case# " << t << "..\n";

        if (t >= 7) {
            fout << "case#" << t << ": " << 0 << "\n";
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
        }
    }
    
    return 0;
}