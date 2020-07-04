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
        int n = nxt(), m = nxt();
        
        vector<vector<int>> v(n, vector<int>(m));
        bool flag = 1;

        auto fn = [&](int r, int c) {
            return r < n && r >= 0 && c < m && c >= 0;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = 0;
                cin >> x;

                int ct = fn(i, j + 1) + fn(i + 1, j) + fn(i - 1, j) + fn(i, j - 1);

                if (x > ct)
                    flag = 0;

                v[i][j] = ct;                
            }
        }

        if (!flag) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                cout << v[i][j] << " \n"[j == m - 1];           
    }
}
