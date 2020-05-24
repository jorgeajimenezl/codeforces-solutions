#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

char st[55][55];
bool mk[55][55];

void dfs (int r, int c) {
    if (mk[r][c])
        return;

    mk[r][c] = 1;

    if (r > 1 && st[r - 1][c] == '1')
        dfs(r - 1, c);
    
    if (c > 1 && st[r][c - 1] == '1')
        dfs(r, c - 1);
}

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

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> st[i][j];

        for (int i = 1; i <= n; i++) {
            if (st[i][n] == '1')
                dfs(i, n);

            if (st[n][i] == '1')
                dfs(n, i);
        }
        bool ans = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (st[i][j] == '1' && !mk[i][j])
                    ans = 0;

                mk[i][j] = 0;
            }

        cout << (ans ? "YES\n" : "NO\n");
    }
}

