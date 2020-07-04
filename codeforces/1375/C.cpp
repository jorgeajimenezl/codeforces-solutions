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
        int n = nxt();
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        int64_t sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += v[i + 1] - v[i];

        if (sum >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
