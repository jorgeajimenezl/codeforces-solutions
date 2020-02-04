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
        cin >> n;

        vector<int> v(n);
        bool imp = 0, par = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] % 2 == 0)
                par = 1;
            if (v[i] % 2 != 0)
                imp = 1;
        }

        if (imp && n % 2 != 0 || imp && par)
            cout << "YES\n";
        else
            cout << "NO\n";
    }    
}