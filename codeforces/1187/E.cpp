#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn], dp(maxn), sz(maxn);
ll ans = 0;

void dfs(ll i, ll p){
    sz[i] = 1;
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        sz[i] += sz[u];
    }
    
    dp[i] = sz[i];
    for(auto u: v[i]){
        if(u==p)
            continue;
        dp[i] += dp[u];
    }
}

void dfs2(ll i, ll p){
    ans = max(ans, dp[i]);
    
    for(auto u: v[i]){
        if(u==p)
            continue;
        
        dp[i] = dp[i] -  dp[u] - sz[u];
        sz[i] -= sz[u];
        dp[u] += dp[i] + sz[i];
        sz[u] += sz[i];
        
        dfs2(u, i);
        
        dp[u] = dp[u] -  dp[i] - sz[i];
        sz[u] -= sz[i];
        dp[i] += dp[u] + sz[u];
        sz[i] += sz[u];
    }
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    sort(v[1].begin(), v[1].end());
    
    dfs(1, 0);
    dfs2(1, 0);
    
    cout<<ans<<endl;
    
    
    return 0;
}