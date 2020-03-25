#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m,x,y;
    cin>>n>>m;
    
    ll colors[n+1];
    for(ll i=1;i<=n;i++)
        cin>>colors[i];
    
    vector<ll> v[n+1];
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    map<ll,set<ll>> mp;
    
    for(ll i=1;i<=n;i++)
        for(ll u: v[i])
            if(colors[u]!=colors[i])
                mp[colors[i]].insert(colors[u]);
    
    unordered_set<ll> us;
    
    ll mx=-1, ans=-1;
    
    for(ll i=1;i<=n;i++){
        if(us.find(colors[i])==us.end()){
            ll sz = mp[colors[i]].size();
            if(sz==mx && colors[i]<ans)
                ans = colors[i];
            if(sz>mx)
                ans = colors[i];
            mx = max(mx,sz);
            us.insert(colors[i]);
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}