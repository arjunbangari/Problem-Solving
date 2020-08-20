#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

ll n, l;
vector<ll> adj[maxn];

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;
vector<ll> res(maxn);
map<pll, ll> ans;

pll f(ll x, ll y){
    return make_pair(min(x,y), max(x,y));
}

void dfs(ll v, ll p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (auto u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<ll>(l + 1));
    dfs(root, root);
}

void dfs1(ll i, ll p=-1){
    for(auto u: adj[i]){
        if(u==p)
            continue;
        dfs1(u, i);
    }
    
    for(auto u: adj[i]){
        if(u==p)
            continue;
        ans[f(u, i)] = res[u];
        res[i] += res[u];
    }
}

int main(){
    fast;
    
    cin>>n;
    
    vector<pll> edges;
    
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.push_back(f(x, y));
    }
    
    preprocess(0);
    
    ll k;
    cin>>k;
    
    for(ll i=0;i<k;i++){
        ll x,y;
        cin>>x>>y;
        x--; y--;
        res[x]++;
        res[y]++;
        ll lc = lca(x,y);
        res[lc]-=2;
    }
    
    dfs1(0);

    for(auto u: edges)
        cout<<ans[f(u.first, u.second)]<<" ";
    cout<<endl;
    
    return 0;
}