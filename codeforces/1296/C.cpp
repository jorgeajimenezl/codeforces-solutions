#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifdef OFFLINE_DEBUG
    freopen("a.in", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;

        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;

        int x = 0, y = 0;
        int l = 0, r = n - 1;
        bool cc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R')
                x++;
            if (s[i] == 'L')
                x--;  
            if (s[i] == 'U')
                y++;
            if (s[i] == 'D')
                y--;

            if (mp.find({x, y}) != mp.end()) {
                if (!cc || r - l > i - mp[{x, y}]) {
                    r = i;
                    l = mp[{x, y}] + 1;
                    cc = 1;
                }
            }

            mp[{x, y}] = i;
        }

        if (cc)
            cout << l + 1 << " " << r + 1 << "\n";
        else
            cout << "-1\n";
    }    
}