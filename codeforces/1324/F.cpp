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
ll n;
vector<ll> g[maxn], color(maxn), dp(maxn), ans(maxn);

void dfs1(ll v, ll p=0){
    dp[v] = color[v];
    for(auto u: g[v]){
        if(u==p)
            continue;
        dfs1(u, v);
        dp[v] += max(0LL, dp[u]);
    }
}

void dfs2(ll v, ll p=0){
    ans[v] = dp[v];
    for(auto u: g[v]){
        if(u==p)
            continue;
        
        dp[v] -= max(0LL, dp[u]);
        dp[u] += max(0LL, dp[v]);
        
        dfs2(u, v);
        
        dp[u] -= max(0LL, dp[v]);
        dp[v] += max(0LL, dp[u]);
    }
}

int main(){
    fast;
    
    cin>>n;
    
    for(ll i=1;i<=n;i++){
        cin>>color[i];
        if(!color[i])
            color[i] = -1;
    }
    
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dfs1(1);
    dfs2(1);
    
    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    
    return 0;
}