
#include <bits/stdc++.h>
using namespace std;

// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, set it in Settings(Ctrl+,) in "Icie Template List" entry 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;
 
        int n = s.length();
 
        vector<vector<int>> dp(s.size() + 1, vector<int>(5));
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++)
                dp[i][j] += dp[i - 1][j];
            
            dp[i][s[i - 1] - '0']++;
        }
 
        auto query = [dp](int a, int b) {
            for (int i = 1; i <= 3; i++)
                if (dp[b][i] - dp[a - 1][i] == 0)
                    return false;
            return true;
        };
 
        int ans = 1 << 30;
        for (int i = 1; i <= n; i++) {
            int lo = i, hi = n;
 
            while (lo < hi) {
                int m = (lo + hi) >> 1;
                if (query(i, m))
                    hi = m;
                else
                    lo = m + 1;
            }
 
            if (!query(i, lo))
                lo++;
                
            if (lo <= n && query(i, lo))
                ans = min(ans, lo - i + 1);
        }
 
        cout << (ans != 1 << 30 ? ans : 0) << "\n";
    }

}

