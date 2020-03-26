#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> v[105];
ll vis[105];

int main(){
    fast;
    
    ll n,m,x,y;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    memset(vis, 0 , sizeof(vis));
    
    queue<pair<ll,ll>> q;
    q.push({1,1});
    vis[1] = 1;
    ll cycle=0;
    
    
    while(!q.empty()){
        auto val = q.front();
        q.pop();
        ll f = val.first, s = val.second;
        
        for(ll u: v[f]){
            if(!vis[u]){
                q.push({u,f});
                vis[u] = 1;
            } else if(u!=s){
                cycle++;
            }
        }
        
    }
    
    cycle/=2;
    
    ll allvisited=1;
    for(ll i=1;i<=n;i++)
        if(!vis[i])
            allvisited=0;
    
    if(allvisited && cycle==1)
        cout<<"FHTAGN!"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}