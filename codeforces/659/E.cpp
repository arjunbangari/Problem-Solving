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
vector<ll> v[maxn], vis(maxn);
ll cycle = 0;

void dfs(ll i, ll p=0){
    vis[i] = 1;
    for(auto u: v[i]){
        if(u==p)
            continue;
        if(vis[u]){
            cycle = 1;
            continue;
        }
        dfs(u, i);
    }
}

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    ll ans = 0;
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            cycle = 0;
            dfs(i);
            if(!cycle)
                ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}