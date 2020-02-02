#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m,a,b,w;
    cin>>n>>m;
    vector<pair<ll,ll>> v[n+1];
    ll vis[n+1] = {0};
    ll dist[n+1];
    for(ll i=1;i<=n;i++)
        dist[i] = 1e12;
    dist[1] = 0;
    ll parent[n+1];
    parent[1] = 1;
    multiset<pair<ll,ll>> ms;
    
    for(ll i=0;i<m;i++){
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    
    ms.insert({0,1});
    
    while(!ms.empty()){
        pair<ll,ll> p = *ms.begin();
        ms.erase(ms.begin());
        if(vis[p.second])
            continue;
        vis[p.second] = true;
        
        for(auto u: v[p.second]){
            if(dist[p.second]+u.second<dist[u.first]){
                dist[u.first] = dist[p.second] + u.second;
                ms.insert({dist[u.first],u.first});
                parent[u.first] = p.second;
            }
        }
    }
    
    if(dist[n]==1e12)
        cout<<-1<<endl;
    else{
        vector<ll> ans;
        ll i= n;
        while(i!=1){
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(1);
        ll sz = ans.size();
        for(ll i=sz-1;i>=0;i--)
            cout<<ans[i]<<" ";
        
    }
    
    
    return 0;
}