#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
        
    vector<pair<ll,ll>> v[n+1];
    ll vis[n+1] = {0};
    ll dist[n+1];
    for(ll i=1;i<=n;i++)
        dist[i] = 1e12;
    dist[1] = 0;
    
    multiset<pair<ll,ll>> ms;
    
    for(ll i=1;i<n-1;i++){
        v[i].push_back({i+1,abs(arr[i+1]-arr[i])});
        v[i].push_back({i+2,abs(arr[i+2]-arr[i])});
    }
    v[n-1].push_back({n,abs(arr[n]-arr[n-1])});
    
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
            }
        }
    }
    
    cout<<dist[n]<<endl;
    return 0;
}