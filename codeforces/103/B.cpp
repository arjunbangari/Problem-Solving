#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> v[105];
ll vis[105];

void dfs(ll i){
    vis[i] = 1;
    for(ll u: v[i])
        if(!vis[u])
            dfs(u);
}

int main(){
    fast;
    
    ll n,m,x,y;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    memset(vis, 0, sizeof(1));
    dfs(1);
    
    ll allvisited=1;
    for(ll i=1;i<=n;i++)
        if(!vis[i])
            allvisited=0;
 
    
    if(allvisited && n==m)
        cout<<"FHTAGN!"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}