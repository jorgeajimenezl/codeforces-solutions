#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()
int nxt() { int x; std::cin >> x; return x; }
#define read_all(v) generate(all(v), nxt);

using namespace std;

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T = nxt();
    
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        
        vector<int64_t> v(n), tp;
        map<int64_t, int64_t> mp; 

        for (int i = 0; i < n; i++) {
            cin >> v[i];    
            if (v[i] % k != 0) {
                int64_t h = k - (v[i] % k);   

                if (mp.find(h) == mp.end())
                    mp[h] = h;

                tp.push_back(mp[h]);  
                mp[h] += k;   
            }     
        }
        int64_t lst = 0;
        int64_t ans = 0;
        sort(tp.begin(), tp.end());

        for (int64_t i : tp) {
            ans += i - lst;
            lst = i;
        }

        cout << (tp.size() != 0 ? ans + 1 : 0) << "\n";
    }
}

