// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif
// #define max(a, b) ((a > b) ? a : b)
// #define min(a, b) ((a < b) ? a : b)


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
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        string s;
        cin >> s;

        vector<pair<int, int>> liked, disliked;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                liked.push_back({p[i], i});
            else
                disliked.push_back({p[i], i});
        }

        // sort(p.begin(), p.end());
        sort(liked.begin(), liked.end());
        sort(disliked.begin(), disliked.end());

        vector<int> ans(n);
        int cnt = disliked.size() + 1;
        for (auto x : liked)
            ans[x.second] = cnt++;
        cnt = 1;
        for (auto x : disliked)
            ans[x.second] = cnt++;
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}