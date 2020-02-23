#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll n,m;
vector<ll> v[150005];
ll vis[150005] = {0};

void dfs(ll i, ll &vertices, ll &edges){
    vis[i] = 1;
    vertices++;
    edges += v[i].size();
    for(ll u: v[i])
        if(!vis[u])
            dfs(u,vertices,edges);
}

int main(){
    fast;
    cin>>n>>m;
    ll a,b,uf=0;
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            ll vertices=0,edges=0;
            dfs(i,vertices,edges);
            if (edges!=(vertices*(vertices-1))){
                uf = 1;
                break;
            }
        }
    }
            
    cout<< ( uf ? "NO" : "YES" )<<endl;
    
    return 0;
}