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
ll colors;
vector<ll> v[maxn], sz(maxn);
vector<pll> edges;
map<pll, ll> mp;

void get_edge(){
    ll x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
    edges.push_back({x,y});
    sz[x]++;
    sz[y]++;
}

void dfs(ll i, ll p=-1, ll c = 0){
    ll cur = 1;
    for(auto u: v[i]){
        if(u==p)
            continue;
        if(cur==c)
            cur++;
        if(cur>colors)
            cur = 1;
        mp[{i, u}] = cur;
        dfs(u, i, cur);
        cur++;
    }
}

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    for(ll i=1;i<n;i++)
        get_edge();
    
    ll l = 1, r = n;
    
    while(l<=r){
        ll m = (l+r)/2;
        ll cnt = 0;
        
        for(ll i=1;i<=n;i++)
            if(sz[i]>m)
                cnt++;
        
        if(cnt<=k){
            colors = m;
            r = m - 1;
        } else
            l = m+1;
    }
    
    dfs(1);
    
    cout<<colors<<endl;
    for(auto u: edges){
        ll val = mp[u] | mp[{u.second, u.first}];
        cout<<val<<" ";
    }
    
    return 0;
}