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
        int n;
        cin >> n;
        
        vector<int> v(2 * n);
        for (int &x : v) cin >> x;

        sort(v.begin(), v.end());
        cout << v[n] - v[n - 1] << "\n";
    }
}