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

ll n, m;
vector<ll> g[maxn], gr[maxn];
vector<ll> cost(maxn), vis(maxn), order;
map<ll, ll> mp;
ll min_money = 0, ways = 1, mn = inf;

void dfs1(ll v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u])
            continue;
        dfs1(u);
    }
    
    order.push_back(v);
}

void dfs2(ll v){
    vis[v] = 1;
    mn = min(mn, cost[v]);
    mp[cost[v]]++;
    
    for(auto u: gr[v]){
        if(vis[u])
            continue;
        dfs2(u);
    }
}

int main(){
    fast;
    
    cin>>n;
    
    for(ll i=1;i<=n;i++)
        cin>>cost[i];
    
    cin>>m;
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    
    vis.assign(n+1, 0 );
    
    for(ll i=1;i<=n;i++){
        if(!vis[i])
            dfs1(i);
    }
    
    vis.assign(n+1, 0);
    
    for(ll i=0;i<n;i++){
        ll v = order[n-i-1];
        if(!vis[v]){
            mn = inf;
            dfs2(v);
            min_money += mn;
            ways = (ways*mp[mn])%mod;
            mp.clear();
        }
    }
    
    cout<<min_money<<" "<<ways<<endl;
    
    return 0;
}