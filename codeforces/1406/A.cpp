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

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int& x : v)
            cin >> x;

        sort(v.begin(), v.end());
        vector<bool> a(n + 1);
        vector<bool> b(n + 1);

        for (int i = 0; i < n; i++) {
            if (v[i] > n)
                continue;

            if (!a[v[i]]) {
                a[v[i]] = 1;
                continue;
            }
            if (!b[v[i]]) {
                b[v[i]] = 1;
                continue;
            }
        }

        int mexa = 0, mexb = 0;
        while (a[mexa]) mexa++;
        while (b[mexb]) mexb++;

        cout << mexa + mexb << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}