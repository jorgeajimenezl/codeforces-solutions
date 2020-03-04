#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1005];
bool vst[1005];
int depth[1005];
int direction[1005], parent[1005];

int dfs (int u) {    
    int ans = u;
    
    for (int v : graph[u])
        if (!depth[v] && !vst[v]) {
            depth[v] = depth[u] + 1;
            parent[v] = u;
            int x = dfs(v);

            if (depth[x] > depth[ans]) {
                ans = x;
                direction[u] = v;
            }
        }

    return ans;
}

void clear_array (int n) {
    for (int i = 1; i <= n; i++) {
        depth[i] = 0;
        direction[i] = 0;
        parent[i] = 0;
    }
}

int main() {   
    //freopen("a.in", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;     
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int w = 1;

    while (true) {
        clear_array(n);
        depth[w] = 1;
        int x = dfs(w);

        if (x == w) {
            //anwer
            cout << "! " << w << "\n";
            cout.flush();
            break;
        }

        clear_array(n);
        depth[x] = 1;
        int y = dfs(x);

        //query
        cout << "? " << x << " " << y << "\n";
        cout.flush();
        cin >> w;

        if (w == x || w == y) {
            //answer
            cout << "! " << w << "\n";
            cout.flush();
            break;
        }

        vst[parent[w]] = vst[direction[w]] = 1;
    }
}