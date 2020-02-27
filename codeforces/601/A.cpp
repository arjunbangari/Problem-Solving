#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m,u,v;
    cin>>n>>m;
    map<pair<ll,ll>,ll> mp;
    
    for(ll i=0;i<m;i++){
        cin>>u>>v;
        mp[{u,v}] = 1;
        mp[{v,u}] = 1;
    }
    
    ll vis[n+1] = {0};
    ll level[n+1] = {0};
    queue<ll> q;
    q.push(1);
    vis[1] = 1;
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        
        for(ll i=1;i<=n;i++){
            if(!vis[i] && mp[{val,i}]){
                q.push(i);
                vis[i] = 1;
                level[i] = level[val] + 1;
            }
        }
    }
    
    ll ans = level[n], flag=0;
    if(level[n]==0)
        flag = 1;
    
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    q.push(1);
    vis[1] = 1;
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        
        for(ll i=1;i<=n;i++){
            if(!vis[i] && !mp[{val,i}]) {
                q.push(i);
                vis[i] = 1;
                level[i] = level[val] + 1;
            }
        }
    }
    
    ans = max(ans,level[n]);
    
    if(level[n]==0)
        flag = 1;   
    
    
    cout<<(flag ? -1 : ans)<<endl;
    
    return 0;
}