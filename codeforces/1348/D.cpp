#include <bits/stdc++.h>

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

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

        vector<int> ans;

        for (int i = 0; i <= 30; i++)
            if (n - (1 << i) >= 0) {
                ans.push_back(1 << i);
                n -= (1 << i);
            }
       
        if (n != 0)
            ans.push_back(n);

        sort(ans.begin(), ans.end());

        cout << ans.size() - 1 << "\n" << ans[1] - ans[0];
        for (int i = 2; i < ans.size(); i++)
            cout << " " << ans[i] - ans[i - 1];
        cout << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}