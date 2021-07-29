//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T = 1;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<string> v(n);
        vector<pair<int, int>> p;

        for (auto &x : v)
            cin >> x;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (v[i][j] == '*')
                    p.push_back({i, j});

        if (p[0].first != p[1].first && p[0].second != p[1].second)
            v[p[0].first][p[1].second] = '*', v[p[1].first][p[0].second] = '*';
        else if (p[0].first == p[1].first) {
            if (p[0].first < n - 1)
                v[p[0].first+1][p[0].second] = '*', v[p[1].first+1][p[1].second] = '*';
            else
                v[p[0].first-1][p[0].second] = '*', v[p[1].first-1][p[1].second] = '*';
        } else {
            if (p[0].second < n - 1)
                v[p[0].first][p[0].second+1] = '*', v[p[1].first][p[1].second+1] = '*';
            else
                v[p[0].first][p[0].second-1] = '*', v[p[1].first][p[1].second-1] = '*';
        }

        for (auto x : v)
            cout << x << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}
