#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    vector<long long> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] < 0)
                continue;
            dp[i] = min(dp[i - a[j]] + 1, dp[i]);
        }
    }
    cout << (dp[x] == INF  ? -1 : dp[x]) << endl;
}