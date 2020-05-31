#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> cost(n);
    for(auto &u: cost)
        cin>>u;
        
    vector<string> arr(n), rev(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        rev[i] = arr[i];
        reverse(rev[i].begin(), rev[i].end());
    }
    
    ll dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    
    for(ll i=1;i<n;i++){
        dp[i][0] = inf;
        dp[i][1] = inf;
    }

    for(ll i=1;i<n;i++){
        if(arr[i]>=arr[i-1])
            dp[i][0] = dp[i-1][0];
        if(arr[i]>=rev[i-1])
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if(rev[i]>=arr[i-1])
            dp[i][1] = dp[i-1][0] + cost[i];
        if(rev[i]>=rev[i-1])
            dp[i][1] = min(dp[i][1], dp[i-1][1] + cost[i]);
    }
    
    ll ans = min(dp[n-1][0], dp[n-1][1]);
    
    cout<< (ans>=inf ? -1 : ans ) <<endl;
    
    return 0;
}