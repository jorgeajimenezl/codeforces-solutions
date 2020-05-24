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
        int64_t n, m;
        cin >> n >> m;

        int64_t k = ((1LL << m) - 1) / 2;
        int64_t l = (1LL << m);
        unordered_set<int64_t> st;

        for (int64_t i = 0; i < n; i++) {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            int64_t p = 0;
            for (int64_t j = 0; j < m; j++)
                if (s[j] == '1')
                    p += (1LL << j);

            st.insert(p);            

            if (k > p && l % 2 == 0 || k == p && l % 2 == 0)
                while (st.find(++k) != st.end());
            if (k < p && l % 2 == 1 || k == p && l % 2 == 1)
                while (st.find(--k) != st.end());

            l--;
        }

        for (int64_t i = m - 1; i >= 0; i--)
            cout << (k & (1LL << i) ? 1 : 0);

        cout << "\n";
    }
}


