#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
        prefix[i] += a[i] + prefix[i - 1];
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
    return 0;
}