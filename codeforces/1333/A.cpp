#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;        

        vector<char> v;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                v.push_back(((i + j) & 1) ? 'W' : 'B');

        if ((n * m) % 2 == 0) {
            for (int i = v.size() - 1; i >= 0; i--)
                if (v[i] == 'W') {
                    v[i] = 'B';
                    break;
                }
        }
        
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if ((i + 1) % m == 0)
                cout << '\n';
        }
    }
}
