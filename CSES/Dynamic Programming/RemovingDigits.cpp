#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long dp[1000001];
    fill(dp, dp + n + 1, 1e10);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int k = i;
        while (k != 0)
        {
            int r = k % 10;
            dp[i] = min(dp[i], dp[i - r] + 1);
            k /= 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}