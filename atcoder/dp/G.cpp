#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn], dp(maxn), vis(maxn);

void dfs(ll i){
    vis[i] = 1;

    for(auto u: v[i]){
        if(!vis[u])
            dfs(u);
        dp[i] = max(dp[u]+1, dp[i]);
    }
}

int main(){
    fast;
    
    ll n, m;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    
    for(ll i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
        
    ll ans = 0;
    for(ll i=1;i<=n;i++)
        ans = max(dp[i], ans);
    
    cout<<ans<<endl;
    
    return 0;
}