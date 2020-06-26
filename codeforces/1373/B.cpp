#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

using namespace std;

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
        // Code here
        string s;
        cin >> s;

        bool flag = 0;
        int j = 0;
        while (!s.empty()) {
            bool st = 0;
            for (auto i = s.begin(); i != s.end(); i++)
                if ((i + 1) != s.end() && *i != *(i + 1)) {
                    s.erase(i, i + 2);
                    flag = !flag;
                    st = 1;
                    break;
                }

            if (!st)
                break;
        }
        cout << (flag ? "DA\n" : "NET\n");
    }
}
