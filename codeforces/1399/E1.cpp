#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn], sz(maxn);
map<pll ,ll> mp;
multiset<pair<ll, pll>, greater<pair<ll, pll>>> ms;
ll ts = 0;

void dfs(ll i, ll p=0){
    if((v[i].size())==1)
        sz[i] = 1;
        
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        sz[i] += sz[u];
    }
    
    for(auto u: v[i]){
        if(u==p)
            continue;
        
        ts += sz[u]*mp[{i,u}];
        
        ll x = sz[u]*(mp[{i,u}] - mp[{i,u}]/2);
        ms.insert({x, {sz[u], mp[{i, u}]}});
    }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,s;
        cin>>n>>s;
        
        ts = 0;
        
        for(ll i=0;i<=n;i++){
            v[i].clear();
            sz[i] = 0;
        }
        
        mp.clear();
        ms.clear();
        
        for(ll i=1;i<n;i++){
            ll x,y,w;
            cin>>x>>y>>w;
            
            v[x].push_back(y);
            v[y].push_back(x);
            mp[{x,y}] = w;
            mp[{y,x}] = w;
        }
        
        dfs(1);
        
        ll cnt = 0;
        while(ts>s){
            pair<ll, pll> x = *ms.begin();
            ms.erase(ms.begin());
            cnt++;
            ts -= x.first;
            
            ll a = x.second.first;
            ll b = x.second.second;
            b /= 2;
            ll new_x = a*(b - b/2);
            ms.insert({new_x, {a, b}});
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}