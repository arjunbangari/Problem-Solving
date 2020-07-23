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

vector<ll> v[maxn], value(maxn), sum(maxn), dp(maxn);
ll ans = 0;

void dfs1(ll i, ll p=0){
    sum[i] = value[i];
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs1(u, i);
        dp[i] += sum[u] + dp[u];
        sum[i] += sum[u];
    }
}

void make_changes(ll i, ll u){
    dp[i] = dp[i] - dp[u] - sum[u];
    sum[i] -= sum[u];
    
    dp[u] += dp[i] + sum[i];
    sum[u] += sum[i];
}

void rollback(ll i, ll u){
    dp[u] = dp[u] - dp[i] - sum[i];
    sum[u] -= sum[i];
    
    dp[i] += dp[u] + sum[u];
    sum[i] += sum[u];
}

void dfs2(ll i, ll p=0){
    ans = max(ans, dp[i]);
    
    for(auto u: v[i]){
        if(u==p)
            continue;
        
        make_changes(i, u);
        dfs2(u, i);
        rollback(i, u);
    }
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=1;i<=n;i++)
        cin>>value[i];
    
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs1(1);
    dfs2(1);
    
    cout<<ans<<endl;
    
    return 0;
}