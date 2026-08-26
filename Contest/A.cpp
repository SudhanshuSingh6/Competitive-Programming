#include <bits/stdc++.h>
using namespace std;

int calc(vector<int>& a, vector<int>& b, vector<int>& c, int n) {
    vector<int> pref(n);
    vector<int> suff(n);
    pref[0] = a[0];
    suff[n-1] = c[n-1];
    for(int i =1;i<n;i++){
        pref[i] = max(a[i],pref[i-1]);
    }

    for(int i =n-2;i>=0;i--){
        suff[i] = max(c[i],suff[i+1]);
    }
    int ans =0;
    for(int i =1;i<n-1;i++){
        ans = max(ans,pref[i-1]+b[i]+suff[i+1]);
    }
    return ans;
}
int main()
{
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i =0 ;i<n;i++)
            cin >> a[i];
        bool ok = true;
        map<long long,long long> mp;
        long long c =2;
        while(true){
            for(int i =0;i<n;i++){
                mp[a[i]%c]++;
            }
            if(mp.size()==2){
                cout << c << endl;
                break;
            }
            mp.clear();
            c *=2;
        }
    }
    return 0;
}