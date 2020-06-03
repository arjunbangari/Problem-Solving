#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e5+5;
ll const mod = 1e9+7;

// code begins here

ll n,k, ans = 0;
vector<ll> g[maxn];
vector< vector<ll>> dp(maxn, vector<ll> (505, 0));

void dfs(ll v, ll p=0){
    dp[v][0] = 1;
    
    for(auto u: g[v]){
        if(u==p)
            continue;
        dfs(u, v);
        
        for(ll i=0;i<k;i++)
            ans += dp[v][i]*dp[u][k-i-1];
        
        for(ll i=1;i<=k;i++)
            dp[v][i] += dp[u][i-1];
    }
}

int main(){
    fast;
    
    cin>>n>>k;
    
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dfs(1);
    
    cout<<ans<<endl;
    
    return 0;
}