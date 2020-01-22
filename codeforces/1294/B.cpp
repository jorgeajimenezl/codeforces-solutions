#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> v[1005];
int parent[1005];

int main() {
    //freopen("a.in", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        v[0] = {0, 0};

        for (int i = 1; i <= n; i++) {
            cin >> v[i].first >> v[i].second;
            parent[i] = 0;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        string ans;
        parent[0] = -1;

        while (!q.empty()) {
            int u = q.front().first;
            int d = q.front().second;
            q.pop();

            if (d == n) {
                string s = "";
                int x = u;
                while (parent[x] != -1) {             
                    for (int j = 0; j < v[x].second - v[parent[x]].second; j++)
                        s += 'U';  

                    for (int j = 0; j < v[x].first - v[parent[x]].first; j++)
                        s += 'R';

                    x = parent[x];  
                }

                reverse(s.begin(), s.end());

                if (ans.empty() || s < ans)
                    ans = s;

                continue;
            }

            int best = -1;

            for (int i = 1; i <= n; i++)
                if (v[i].first != v[u].first || v[i].second != v[u].second)
                    if (v[i].first >= v[u].first && v[i].second >= v[u].second) {              
                        if (best == -1 || v[i].second - v[u].second < v[best].second - v[u].second 
                        || v[i].first - v[u].first < v[best].first - v[u].first)                             
                            best = i;
                            
                    }
            if (best != -1)        {
            parent[best] = u;
                q.push({best, d + 1});
            }
        }

        if (ans.empty())
            cout << "NO\n";
        else {
            cout << "YES\n";
            cout << ans << "\n";
        }        
    }
}