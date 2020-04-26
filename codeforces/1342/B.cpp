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
        string s;
        cin >> s;

        string ans = "";
        bool k1 = 1, k2 = 1;

        for (int i = 0; i < s.size(); i++) {
            if (i != s.size() - 1)
                if (s[i] != s[i + 1])
                    k1 = 0;
            
            if (i != s.size() - 2)
                if (s[i] != s[i + 1])
                    k2 = 0;
        }
        

        if (k1 || k2) {
            cout << s << "\n";
            continue;
        }
        
        for (int i = 0; i < s.size() - 1; i++) {
            ans.push_back(s[i]);
            
            if (s[i] == s[i + 1])
                ans.push_back(s[i] == '1' ? '0' : '1');
        }

        ans.push_back(s[s.size() - 1]);;
        cout << ans << "\n";
    }
}
