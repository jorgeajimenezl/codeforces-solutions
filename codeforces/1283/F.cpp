//http://codeforces.com/contest/1283/problem/E
//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;
        
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> degree(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        degree[v[i]]++;       
    }

    priority_queue<int> q;

    for (int i = 1; i <= n; i++)
        if (!degree[i])
            q.push(-i);

    stack<pair<int, int>> ans;
    int k = n - 1;
    
    while (!q.empty() && k >= 1) {
        ans.push(make_pair(v[k], -q.top()));
        q.pop();
        degree[v[k]]--;

        if (degree[v[k]] == 0)
            q.push(-v[k]);

        k--;
    }

    if (k) {
        cout << "-1";
        return 0;
    }

    cout << v[1] << "\n";

    while (!ans.empty()) {
        cout << ans.top().first << " " << ans.top().second << "\n";
        ans.pop();
    }
}