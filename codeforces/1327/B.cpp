#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef OFFLINE
    freopen("a.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        int64_t n;
        cin >> n;        

        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;

            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;

                graph[i].push_back(v);
            }
        } 

        vector<bool> vst(n + 1, false);
        vector<int> match(n + 1, -1);
        vector<int> unmatch, princes;
        

        for (int i = 1; i <= n; i++) {
            int j = 0;
            for (; j < graph[i].size() && vst[graph[i][j]]; j++);
            if (j != graph[i].size()) {
                match[graph[i][j]] = i;
                vst[graph[i][j]] = 1;
            } else
                unmatch.push_back(i);
        }

        for (int i = 1; i <= n; i++)
            if (match[i] == -1)
                princes.push_back(i);

        bool flag = 0;

        for (int u : unmatch) {
            int v = princes.back();
            princes.pop_back();

            if (v != -1) {
                cout << "IMPROVE\n" << u << " " << v << "\n";
                flag = 1;
                break;
            }
        }

        if (!flag)
            cout << "OPTIMAL\n";

        // clear
        for (int i = 1; i <= n; i++)
            graph[i].clear();
    }    
}