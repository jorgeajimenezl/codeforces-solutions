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

        int sum = 0, x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
        }

        cout << (sum == m ? "YES\n" : "NO\n");
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}