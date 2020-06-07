#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

char st[55][55];
bool vst[55][55];
int T, n, m;
int mr[] = {1, 0, -1, 0}, mc[] = {0, 1, 0, -1};

bool ch (int r, int c) {
    return r < n && r >= 0 && c < m && c >= 0;
}

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    cin >> T;

    while (T--) {        
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> st[i][j]; 

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (st[i][j] == 'B')
                    for (int k = 0; k < 4; k++) {
                        int nr = mr[k] + i;
                        int nc = mc[k] + j;

                        if (ch(nr, nc) && st[nr][nc] == '.')
                            st[nr][nc] = '#';
                    }    

        queue<pair<int, int>> q;
        if (st[n - 1][m - 1] != '#')
            q.push({n - 1, m - 1});
        vst[n - 1][m - 1] = 1;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();            

            for (int i = 0; i < 4; i++) {
                int nr = mr[i] + r;
                int nc = mc[i] + c;

                if (ch(nr, nc) && !vst[nr][nc] && st[nr][nc] != '#') {
                    vst[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }    

        bool flag = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (st[i][j] == 'B')
                    flag |= vst[i][j];
                if (st[i][j] == 'G')
                    flag |= (!vst[i][j]);
            }

        cout << (flag ? "No\n" : "Yes\n");

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vst[i][j] = 0;
    }
}
