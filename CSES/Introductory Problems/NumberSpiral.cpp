#include <bits/stdc++.h>
using namespace std;
static long long MOD = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        int x, y;
        cin >> y;
        cin >> x;
        long long n = max(y, x);
        long long ans;
        if (n % 2 == 0){
            if (y == n)
                ans = n * n - x + 1;
            else
                ans = (n - 1) * (n - 1) + y;
        }
        else{
            if (x == n)
                ans = n * n - y + 1;
            else
                ans = (n - 1) * (n - 1) + x;
        }
        cout << ans << '\n';
    }
    return 0;
}