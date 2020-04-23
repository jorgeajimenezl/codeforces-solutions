#include <bits/stdc++.h>

using namespace std;

string numbs[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
vector<string> v;
int memo[2005][2005];

bool can (const string &a, const string &b) {
    for (int i = 0; i < 7; i++)
        if (a[i] == '1' && b[i] == '0')
            return false;
    return true;
}

int diff (const string &a, const string &b) {
    int ans = 0;
    for (int i = 0; i < 7; i++)
        ans += (a[i] != b[i]);
    return ans;
}

bool solve (int i, int k) {    
    if (i >= v.size())
        return k == 0;

    if (memo[i][k] >= -1) {
        int x = memo[i][k];
        if (x == -1)
            return false;
        else {
            v[i] = numbs[x];
            return true;
        }
    }
    
    for (int j = 9; j >= 0; j--) {
        if (!can(v[i], numbs[j]))
            continue;
                    
        int x = diff(v[i], numbs[j]);
        
        if (k - x >= 0 && solve(i + 1, k - x)) {
            v[i] = numbs[j];
            memo[i][k] = j;
            return true;
        }
    }

    memo[i][k] = -1;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif

    map<string, int> id;
    for (int i = 0; i < 10; i++)
        id[numbs[i]] = i;

    int T = 1;
    //cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i <= n + 2; i++)
            for (int j = 0; j <= k + 3; j++)
                memo[i][j] = -10;

        v.resize(n);
        for (auto &x : v)
            cin >> x;

        int val = 0;
        vector<int> valid(n + 1);

        for (int i = 0; i < n; i++) {
            int mn = 1 << 30;
            for (int j = 0; j < 10; j++)
                if (can(v[i], numbs[j]))
                    mn = min(mn, diff(v[i], numbs[j]));
            val += mn;
            valid[i] = mn;
        }

        if (val > k) {
            cout << "-1\n";
            continue;
        } else {       
            if (solve(0, k)) {
                for (int i = 0; i < n; i++)
                    cout << id[v[i]];

                cout << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}
