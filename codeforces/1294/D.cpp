#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("a.in", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, x;   
    cin >> q >> x;
    int mex = 0;
    vector<int> st (x + 1, 0);

    for (int i = 0; i < q; i++) {
        int p;
        cin >> p;
        st[p % x]++;

        while (st[mex % x]) {
            st[mex % x]--;
            mex++;
        }

        cout << mex << "\n";        
    }
}