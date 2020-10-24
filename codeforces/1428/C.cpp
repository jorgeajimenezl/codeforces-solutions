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
        string s;
        cin >> s;

        int ans = 0;
        for (auto x : s) {
            if (ans > 0 && x == 'B')
                ans--;
            else
                ans++;
        }

        cout << ans << "\n";
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}