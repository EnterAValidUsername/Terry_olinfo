#include <bits/stdc++.h>

using namespace std;

ifstream fin ("collezionismo_input_1.txt");
ofstream fout ("output.txt");

typedef long long int ll;
typedef pair < ll, ll > pll;

int N, K;

map < pll, ll > discrepanze;

//
void stampa (pair < pll, ll > x) {
    cout << "x: {" << x.first.first << ", " << x.first.second << "}: " << x.second << "\n";
}
//

ll solve (pair < pll, ll > curr = {{-1, -1}, 0}, int c = -1, ll best = (ll)1<<60) {
    if (c == K - 1 && curr.first.second == N - 1) {
        //
        cout << "done\n";
        //
        return curr.second;
    }
    else if (c >= K || curr.second >= best) {
        //
        cout << "c eccessivo: " << c << "\n";
        //
        return (ll)1<<60;
    }
    
    //
    cout << "curr: {" << curr.first.first << ", " << curr.first.second << "}:\n";
    cout << "c: " << c << "\n";
    //

    int a = 0;
    for (auto x : discrepanze) {
        a++;
        //
        cout << "loop: " << a << "\n";
        //
        if (x.first.first == curr.first.second + 1) {
            //
            stampa(x);
            cout << "nuova chiamata\n";
            //
            best = min (solve(x, c + 1, best) + x.second, best);
            cout << "best: " << best << "\n";
        }
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
            vector < ll > pSum(N);

            for (int i = 0; i < N; i++) {
                fin >> C[i];
            }

            sort(C.begin(), C.end());

            for (int i = 0; i < N; i++) {
                pSum[i] = C[i] - C[0]; // prefix sum array (differenze)
            }

            for (int i = 0; i < N; i++) {
                discrepanze[{i, i}] = 0;
                for (int j = 0; j < i; j++) {
                    discrepanze[{j, i}] = pSum[i] - pSum[j]; // dati gli indici i e j, discrepanze contiene la loro differenza
                }
            }

            fout << "case #" << t << ": " << solve() << "\n";
        }
    }
    
    return 0;
}