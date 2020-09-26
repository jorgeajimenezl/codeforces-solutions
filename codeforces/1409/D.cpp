//Coder: jorgeajimenezl
#include <bits/stdc++.h>

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

void add_one (vector<uint64_t> &v, int i) {
    if (i == -1) {
        int t = v.size();
        v.clear(); v.push_back(1);
        while (t--) v.push_back(0);
        return;
    }

    if (v[i] == 9) {
        v[i] = 0;
        add_one(v, i - 1);
    } else
        v[i]++;
}

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
        // TODO: Here        
        uint64_t n, s;      
        cin >> n >> s;

        uint64_t x = n, sum = 0;
        vector<uint64_t> v;
        while (x) {          
            v.push_back(x % 10);
            sum += x % 10;
            x /= 10;
        }
        if (sum <= s) {
            cout << "0\n";
            continue;
        }
        reverse(v.begin(), v.end());

        int l = -1, i = 0;
        uint64_t k = 0;
        for ( ; i < v.size(); i++) {
            k += v[i];            
            if (k > s) {
                k -= v[i];
                for (int j = i; j < v.size(); j++)
                    v[j] = 0;
                break;
            }
            l = (v[i] != 0 ? i : l);
        }

        if (k == s) {
            v[l] = 0;
            add_one(v, l - 1);
        } else
            add_one(v, i - 1);

        sum = 0;
        for (int i : v) {
            sum *= 10;
            sum += i;
        }

        cout << sum - n << "\n";
    }
    
#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}