// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

string solve(string &a, string &s) {
    reverse(s.begin(), s.end());
    reverse(a.begin(), a.end());

    int i = 0, j = 0;
    string ans = "";
    while (i < s.length() && j < a.length()) {
        if (s[i] >= a[j]) {
            ans.push_back(s[i] - a[j] + '0');
            i++;
            j++;
        }
        else {
            if (i + 1 >= s.length())
                return "-1";

            int m = (s[i + 1] - '0') * 10 + (s[i] - '0');
            if (m - (a[j] - '0') > 9 || m < (a[j] - '0'))
                return "-1";
            ans.push_back(m - (a[j] - '0') + '0');
            i+=2;
            j+=1;
        }
    }
    while (i < s.length())
        ans.push_back(s[i++]);
    if (j != a.length())
        return "-1";
    while (ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

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
        string a, s;
        cin >> a >> s;
        cout << solve(a, s) << "\n";        
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}