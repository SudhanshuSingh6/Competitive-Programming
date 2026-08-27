#include <bits/stdc++.h>
using namespace std;
static long long MOD = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        int a, b;
        cin >> a;
        cin >> b;
        bool ok = true;
        if ((a + b) % 3 != 0)
            ok = false;
        if (2 * min(a, b) < max(a, b))
            ok = false;

        if (ok)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}