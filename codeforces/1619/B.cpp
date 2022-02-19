// Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    
    int T;
    cin >> T;

    vector<int> ans;    
    for (int i = 1; i*i <= 1e9; i++)
        ans.push_back(i*i);
    for (int i = 1; i*i*i <= 1e9; i++)
        ans.push_back(i*i*i);        
    for (int i = 1; i*i*i*i*i*i <= 1e9; i++)
        ans.push_back(i*i*i*i*i*i);
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

    while (T--) {
        int n;
        cin >> n;
        cout << upper_bound(ans.begin(), ans.end(), n) - ans.begin() << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}