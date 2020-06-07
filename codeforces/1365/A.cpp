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

        vector<int> r(n, 0), c(m, 0);
        int x;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> x;
                if (x)
                    r[i] = c[j] = 1;
            }

        int a = n, b = m;

        for (int i = 0; i < n; i++)
            a -= r[i];
        for (int i = 0; i < m; i++)
            b -= c[i];
            
        cout << ((min(a, b) & 1ULL) ? 
                "Ashish" : "Vivek") << "\n";
    }
}
