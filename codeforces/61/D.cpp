#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,x,y,w;
    cin>>n;
    
    vector<pair<ll,ll>> v[n+1];
    
    ll ans = 0;
    for(ll i=1;i<n;i++){
        cin>>x>>y>>w;
        ans += 2*w;
        v[x].push_back({y,w});
        v[y].push_back({x,w});
    }
    
    ll dist[n+1] = {0};
    ll vis[n+1] = {0};
    
    queue<ll> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        
        for(auto u: v[val] ){
            if(!vis[u.first]){
                dist[u.first] = dist[val] + u.second;
                vis[u.first] = 1;
                q.push(u.first);
            }
        }
    }
    
    ll mx = *max_element(dist,dist+n+1);
    // for(ll i=0;i<=n;i++)
    //     cout<<dist[i]<<" ";
    // cout<<endl<<mx<<endl;
    
    cout<<ans-mx<<endl;
    
    return 0;
}