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
map<pll, ll> color;
ll two = 0;

void dfs(ll i){
    vis[i] = 1;
    
    for(auto u: v[i]){
        if(vis[u]){
            if(vis[u]==1){
                two = 1;
                color[{i, u}] = 2;
            } else {
                color[{i, u}] = 1;
            }
            continue;
        }
        color[{i, u}] = 1;
        dfs(u);
    }
    
    vis[i] = 2;
}

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<pll> edges(m);
    
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        edges[i] = {a,b};
    }
    
    for(ll i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
            
    cout<< (two ? 2 : 1)<<endl;
    for(auto u: edges)
        cout<<color[u]<<" ";
    
    return 0;
}