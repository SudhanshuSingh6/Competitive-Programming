#include <bits/stdc++.h>
using namespace std;
static long long MOD = 1e9 + 7;
long modpow(int n){
    if (n == 0)
        return 1;
    if (n % 2 == 0){
        long k = modpow(n / 2) % MOD;
        return (k * k)%MOD;
    }
    else
        return (2 * modpow(n - 1)) % MOD;
}
int main(){
    int n;
    cin >> n;
    cout << modpow(n);
    return 0;
}