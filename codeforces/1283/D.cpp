//http://codeforces.com/contest/1283/problem/D
//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;
int v[200005];
set<int> st;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        q.push(make_pair(0, v[i]));
        st.insert(v[i]);
    }

    vector<int> ans;
    long long sum = 0;

    while (ans.size() < m) {
        auto u = q.front();
        q.pop();

        if (st.find(u.second + 1) == st.end()) {
            ans.push_back(u.second + 1);
            sum += u.first + 1;
            st.insert(u.second + 1);

            q.push(make_pair(u.first + 1, u.second + 1));
        }

        if (ans.size() == m)
            break;

        if (st.find(u.second - 1) == st.end()) {
            ans.push_back(u.second - 1);
            sum += u.first + 1;
            st.insert(u.second - 1);

            q.push(make_pair(u.first + 1, u.second - 1));
        }
    }

    cout << sum << "\n";
    
    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";
}