#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m,x,y, temp;
    cin>>n>>m;
    
    vector<ll> v[n+1];     //adjacency list
    ll energy[n+1];        //energy values
    ll cost[n+1] = {0};    //cost of removing each vertex
    
    for(ll i=1;i<=n;i++)
        cin>>energy[i];
    
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        cost[x] += energy[y];
        cost[y] += energy[x];
    }
    
    vector<pair<ll,ll>> ms;
    
    for(ll i=1;i<=n;i++)
        ms.push_back({energy[i],i});
    
    sort(ms.begin(), ms.end());
    
    ll ans=0;
    
    for(ll i=n-1;i>=0;i--){
        ll part = ms[i].second, value = ms[i].first;
        ans += cost[part];
        for(ll u: v[part])
            cost[u] -= value;
    }

    cout<<ans<<endl;
    
    return 0;
}