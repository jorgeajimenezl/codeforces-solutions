#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

struct node {
    int s, e;
    bool operator < (const node &o) const {
        return (e - s) != (o.e - o.s) ? (e - s) < (o.e - o.s) : s > o.s;
    }
};

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
        uint64_t n;
        cin >> n;

        priority_queue<node> q;

        q.push({1, n});
        vector<int> ans(n + 1);

        for (int i = 1; i <= n; i++) {
            auto t = q.top();
            q.pop();
            int s = t.s, e = t.e;
            int m = (s + e) >> 1;
            
            ans[m] = i;
            q.push({s, m - 1});
            q.push({m + 1, e});
        }

        cout << ans[1];
        for (int i = 2; i <= n; i++)
            cout << " " << ans[i];
        cout << "\n";
    }
}
