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

        int a = n - 1, b = n;
        cout << "2\n";
        for (int i = 0; i < n - 1; i++) {
            cout << a << " " << b << "\n";            
            if (b - a == 2)
                b--;
            a--;
        }
    }
	
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}