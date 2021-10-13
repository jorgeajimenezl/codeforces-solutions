//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif


int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int T = 1;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(k);
        for (int& x : v) cin >> x;
        
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0, t = 0;
        for (int i = 0; i < k; i++) {
            if (t < v[i]) {
                t += n - v[i];
                ans++;
            }
        }
        cout << ans << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}