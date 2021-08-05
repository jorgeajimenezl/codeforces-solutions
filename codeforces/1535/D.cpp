//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif

int64_t sum(int64_t x) {
    return (x * (x + 1)) / 2;
}

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T = 1;
    // cin >> T;

    while (T--) {
        int k;
        cin >> k;
        
        string s;
        cin >> s;
        
        int n = 1 << k;
        vector<int> st((n << 1) + 1), id((n << 1) + 1), id2((n << 1) + 1);
        for (int u = n; u <= (n << 1) - 1; u++)
            st[u] = 1;
        
        int cnt = k - 1;
        int j = 1 << cnt;
        vector<int> index(j);

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '0')
                st[j] = st[j << 1];
            if (s[i - 1] == '1')
                st[j] = st[j << 1 | 1];
            if (s[i - 1] == '?')            
                st[j] = st[j << 1] + st[j << 1 | 1];
                
            id[i] = j;
            id2[j] = i;

            if (j == (1 << (cnt + 1)) - 1) {
                cnt--;
                j = 1 << cnt;
            } else
                j++;                
        }

        int q, x;
        cin >> q;

        while (q--) {
            char c;
            cin >> x >> c;

            s[x - 1] = c;
            int p = id[x];

            while (p) {
                // int i = 
                if (s[id2[p] - 1] == '0')
                    st[p] = st[p << 1];
                if (s[id2[p] - 1] == '1')
                    st[p] = st[p << 1 | 1];
                if (s[id2[p] - 1] == '?')
                    st[p] = st[p << 1] + st[p << 1 | 1];
                p >>= 1;
            }

            cout << st[1] << "\n";            
        }
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}