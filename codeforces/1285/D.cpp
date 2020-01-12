//http://codeforces.com/contest/1285/problem/D
//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

struct node {
    int i;
    node* next[2];
} *root = new node() ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;
    node* pt;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pt = root;

        for (int j = 30; j >= 0; j--) {
            bool u = (x & (1 << j));
            pt->i = j;

            if (pt->next[u] == nullptr)
                pt->next[u] = new node();
                
            pt = pt->next[u];
        }
    }

    function<int (node*)> compute = [&](node* u) {  
        if (u->next[0] != nullptr && u->next[1] != nullptr)
            return (1 << u->i) + min(compute(u->next[0]), 
                                  compute(u->next[1]));

        if (u->next[0] != nullptr)
            return compute(u->next[0]);

        if (u->next[1] != nullptr)
            return compute(u->next[1]);

        return 0;
    };

    cout << compute(root);
}