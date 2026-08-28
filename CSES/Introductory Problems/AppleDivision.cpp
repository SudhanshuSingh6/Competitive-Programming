#include <bits/stdc++.h>
using namespace std;
static long long MOD = 1e9 + 7;

long long calc(vector<int> a, long long sum, int i, long long totalsum){
    if (i == a.size()){
        return abs(2 * sum - totalsum);
    }
    return min(calc(a, sum + a[i], i + 1, totalsum), calc(a, sum, i + 1, totalsum));
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    cout << calc(a, 0, 0, sum) << endl;
    return 0;
}