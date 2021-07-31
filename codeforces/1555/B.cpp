//Coder: jorgeajimenezl
#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")

using namespace std;

#if _DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#endif

int main() {
#if _DEBUG
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T = 1;
    cin >> T;

    while (T--) {
        int x1, x2, y1, y2, w, h, W, H;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;

        int ans = INT_MAX;
        if (w <= W - abs(x1 - x2)) {
            if (w < x1 || w < W - x2)
                ans = 0;
            else
                ans = min({ans, w - (W - x2), w - x1});
        }
        if (h <= H - abs(y1 - y2)) {
            if (h < y1 || h < H - y2)
                ans = 0;
            else
                ans = min({ans, h - (H - y2), h - y1});
        }
            
        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }

#if _DEBUG
    cout << "Time elapsed: " << double(clock()) / double(CLOCKS_PER_SEC) << "s\n";
#endif
}