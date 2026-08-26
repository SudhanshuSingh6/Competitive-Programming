#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int dp[x + 1];
    int mod = 1e9 + 7;
    fill(dp, dp + x + 1, 0);
    dp[0] = 1;
    for (int s = 0; s <= x; s++)
    {
        for (int c : coins)
        {
            if (s - c >= 0)
            {
                dp[s] += dp[s - c];
                dp[s] %= mod;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}