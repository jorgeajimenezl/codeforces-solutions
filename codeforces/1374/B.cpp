#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()
int nxt() { int x; std::cin >> x; return x; }
#define read_all(v) generate(all(v), nxt);

using namespace std;

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T = nxt();
    
    while (T--) {
        int64_t n;
        cin >> n;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        if (n % 3 != 0) {
            cout << "-1\n";
            continue;
        }

        int d2 = 0, d3 = 0;
        while (n % 2 == 0) {
            d2++;
            n /= 2;
        }

        while (n % 3 == 0) {
            d3 ++;
            n /= 3;
        }
        if (n != 1 || d2 > d3) {
            cout << "-1\n";
            continue;
        }
        
        cout << (d3 - d2) * 2 + d2 << "\n";
    }
}

