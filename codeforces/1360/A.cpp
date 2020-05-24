#include <bits/stdc++.h>
using namespace std;

// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, press Ctrl+Shift+P and select "ICIE Template configure" from the list 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝
// 🎉 ... or just ask me about anything via Discord at https://discord.gg/ffSEhtb 🎉

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int a, b;
        cin >> a >> b;
        if (min(a, b) * 2 >= max(a, b))
            cout << min(a, b) * min(a, b) * 4 << "\n";
        else
            cout << max(a, b) * max(a, b) << "\n";
    }
}
