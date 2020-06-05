#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

struct node {
    int ct;
    node* next[2];

    node () {
        ct = 0;
        next[0] = next[1] = nullptr;
    }
};

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

        vector<int> cnt(1025);
        node* root = new node();

        auto insert = [](node* u, int x) {
            for (int i = 0; i <= 11; i++) {
                bool l = x & (1 << i);
                if (u->next[l] == nullptr)
                    u->next[l] = new node();

                u = u->next[l];
            }
                    
            u->ct++;          
        };

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ++cnt[x];
            insert(root, x);
        }

        bool end = 0;

        for (int64_t k = 1; k <= 1024; k++) {
            queue<tuple<node*, int, int>> q;
            q.push({root, 0, 0});
            bool flag = 1;

            while (!q.empty()) {
                auto s = q.front();
                q.pop();

                if (get<0>(s)->ct != 0) {
                    int64_t x = get<2>(s);
                    int64_t p = x ^ k;
                    if (0 > p || p > 1024 || cnt[p] != get<0>(s)->ct) {
                        flag = 0;
                        break;
                    }
                }

                for (int i = 0; i <= 1; i++)
                    if (get<0>(s)->next[i] != nullptr)
                        q.push({get<0>(s)->next[i], 
                                get<1>(s) + 1, 
                                get<2>(s) + i * (1 << get<1>(s))});
            }

            if (flag) {
                cout << k << "\n";
                end = 1;
                break;
            }       
        }

        if (!end)
            cout << "-1\n";
    }
}

