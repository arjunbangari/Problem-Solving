#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn], vis(maxn, 0);

void dfs(ll i){
    vis[i] = 1;
    for(auto u : v[i])
        if(!vis[u])
            dfs(u);
}

int main(){
    fast;
    
    ll n,m,a,b, component=0;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            component++;
            dfs(i);
        }
    }
    
    if(component==1 && m==(n-1))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    
    return 0;
}