#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll n,k,a,b;
vector<ll> v[200005];
vector<ll> vis(200005, 0), level(200005), sz(200005,0);

void dfs(ll i){
    vis[i] = 1;
    for(auto u: v[i]){
        if(!vis[u]){
            level[u] = level[i]+1;
            dfs(u);
            sz[i] += sz[u]+1;
        }
    }
}

void dfs1(ll i){
    
}

int main(){
    fast;
    
    cin>>n>>k;
    
    for(ll i=1;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    level[1] = 0;
    dfs(1);
    
    vector<ll> happiness;
    
    for(ll i=2;i<=n;i++)
        happiness.push_back(level[i]-sz[i]);
    
    sort(happiness.rbegin(), happiness.rend());
    
    ll ans = 0;
    
    for(ll i=0;i<k;i++)
        ans += happiness[i];
    
    cout<<ans<<endl;
    
    return 0;
}