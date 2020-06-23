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

vector<ll> v[maxn], color(maxn), vis(maxn);
ll isbar = 1;

void dfs(ll i, ll c=0){
    vis[i] = 1;
    color[i] = c;
    for(auto u: v[i]){
        if(vis[u]){
            if(color[i]==color[u])
                isbar = 0;
            continue;
        }
        dfs(u, !c);
    }
}

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<pll> edges;
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        edges.push_back({x,y});
    }
    
    dfs(1);
    
    if(!isbar){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    for(auto u: edges)
        cout<<color[u.first];
    
    return 0;
}