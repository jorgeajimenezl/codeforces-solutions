#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string p, h;
        cin >> p >> h;

        if (h.size() < p.size()) {
            cout << "NO\n";
            continue;
        }

        vector<int> ct(256, 0);

        for (char i : p)
            ct[i]++;

        int n = h.size();
        bool flag = 1;

        for (int i = 0; i < n - p.size() + 1; i++) {
            vector<int> v(256, 0);
            
            for (int j = i; j < i + p.size(); j++) {
                v[h[j]]++;
            }

            flag = 1;          

            for (char j : p)
                if (v[j] != ct[j]) {
                    flag = 0;
                    break;
                }

            if (flag) {
                cout << "YES\n";
                break;
            }
        }

        if (!flag)
            cout << "NO\n";      
    }
}