//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

template<typename T>
struct fenwick_tree {
    vector<T> tree;

    fenwick_tree(int n) : tree(n + 1) { }
    T query (int i) {
        T ans = 0;

        while (i < tree.size()) {
            ans += tree[i];
            i += (i & -i);
        }

        return ans;
    }

    void update (int i, T x) {
        while (i) {
            tree[i] += x;
            i -= (i & -i);
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
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> v(n);
        vector<stack<int>> c(256);
        for (int i = 0; i < n; i++)
            c[s[i]].push(n - i);
        
        fenwick_tree<int> fw(n);
        int64_t ans = 0;

        for (int i = 0; i < n; i++) {
            int u = c[s[i]].top(); c[s[i]].pop();
            ans += fw.query(u);            
            fw.update(u, 1);
        }

        cout << ans << "\n";
    }	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}