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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int &x : v)
            cin >> x;

        sort(v.begin(), v.end());

        int ans = 1;

        for (int j = 0; j < n; j++)
            if (v[j] <= j + 1)
                ans = j + 2;

        cout << ans << "\n";  
    }
}

