#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,x,y;
    cin>>n;
    
    vector<pair<ll,ll>> edges;
    
    for(ll i=0;i<n-1;i++){
        cin>>x>>y;
        edges.push_back({x,y});
    }
    
    ll color[n+1];
    for(ll i=1;i<=n;i++)
        cin>>color[i];
    
    map<ll,ll> mp;
    ll cnt=0;
    
    for(auto u: edges){
        if(color[u.first]!=color[u.second]){
            mp[u.first]++;
            mp[u.second]++;
            cnt++;
        }
    }
    
    ll ans=0;
    
    if(cnt){
        for(auto u : mp){
            if(u.second==cnt)
                ans = u.first;
        }
    } else
        ans = 1;
    
    if(ans)
        cout<<"YES"<<endl<<ans<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}