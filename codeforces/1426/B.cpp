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
        int n, m;
        cin >> n >> m;

        bool flag = 0;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            if (c == b)
                flag = 1;
        }

        cout << (!(m & 1) && flag ? "YES\n" : "NO\n");
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}