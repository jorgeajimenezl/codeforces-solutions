//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

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

        vector<int> v(n);
        for (int& x : v)
            cin >> x;

        int64_t sum = 0;
        set<int64_t> st = { 0 };
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += v[i];
            if (st.find(sum) != st.end()) {
                ans++;
                sum = v[i];
                st.clear();
                st.insert({0, v[i]});
            } else
                st.insert(sum);
        }

        cout << ans << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}