#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()
int nxt() { int x; std::cin >> x; return x; }
#define read_all(v) generate(all(v), nxt);

using namespace std;

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T = nxt();
    
    while (T--) {
        int n = nxt();

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (i & 1)
                cout << abs(x) << " \n"[i == n - 1];
            else 
                cout << -abs(x) << " \n"[i == n - 1];      
        }            
    }
}
