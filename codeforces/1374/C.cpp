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
        int n;
        cin >> n;
        
        int ans = 0, cur = 0;
        char s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (s == '(')
                cur++;
            else
                cur--;

            if (cur < 0) {
                ans++;
                cur = 0;
            }
        }
        cout << ans << "\n";
    }
}

