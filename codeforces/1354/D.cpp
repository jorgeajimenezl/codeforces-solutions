#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

template<typename T>
struct fenwick_tree {
    vector<T> tree;

    fenwick_tree(int n) : tree(n + 1) { }
    T query (int i) {
        T ans = 0;

        while (i) {
            ans += tree[i];
            i -= (i & -i);
        }

        return ans;
    }

    void update (int i, T x) {
        while (i < tree.size()) {
            tree[i] += x;
            i += (i & -i);
        }
    }
};

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
        int n, q;
        cin >> n >> q;

        fenwick_tree<int> st(n);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            st.update(x, 1);
        }

        while (q--) {
            int k;
            cin >> k;

            if (k > 0)
                st.update(k, 1);
            else {
                int lo = 1, hi = n;
                while (lo < hi) {
                    int m = (lo + hi) >> 1;

                    if (st.query(m) >= -k)
                        hi = m;
                    else
                        lo = m + 1;
                }
                
                st.update(lo, -1);
            }        
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (st.query(i)) {
                ans = i;
                break;
            }

        cout << ans << "\n";
    }
}

