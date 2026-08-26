#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<long long> dp(n+1,0);
    dp[0] = 1;
    int mod  = 1000000007;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(j>i)
                continue;
            dp[i] += dp[i-j];
            dp[i] = dp[i]%mod;
        }
    }
    cout << dp[n]%mod << endl;
}
