#include <bits/stdc++.h>
#include <unistd.h>
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
        string s;
        cin >> s;

        string ans = "";
        bool j = 0;
        for (int i = 1; i < s.length(); i+=2) {
            ans += s[i];
        }

        cout << s[0] + ans << "\n";
    }
    
}

