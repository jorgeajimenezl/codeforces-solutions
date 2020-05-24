#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        auto check = [&](const string &s) {
            for (int i = 0; i < n; i++) {
                int ct = 0;

                for (int j = 0; j < m; j++)
                    ct += (v[i][j] != s[j]);

                if (ct > 1)
                    return false;
            }

            return true;
        };

        string ans = "";
        bool fun = 0;

        for (int i = 0; i < n && !fun; i++) {           
            for (int j = 0; j < m && !fun; j++) {
                string h = v[i];

                for (char p = 'a'; p <= 'z'; p++) {
                    h[j] = char(p);

                    if (check(h)) {
                        cout << h << "\n";
                        fun = 1;
                        break;
                    }
                }
            }
        }

        if (!fun)
            cout << "-1\n";
    }
}

