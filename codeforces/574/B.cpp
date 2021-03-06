#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define bs(v,x) binary_search((v).begin(),(v).end(),(x))

int main(){
    fast;
    
    ll n,m,a,b;
    cin>>n>>m;
    
    vector<ll> v[n+1], sz(n+1,0);
    vector<pair<ll,ll>> edges;
    
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        sz[a]++;
        sz[b]++;
        edges.push_back({a,b});
    }
    
    for(ll i=1;i<=n;i++)
        sort(v[i].begin(), v[i].end());
        
    ll mx = 1e10;
    
    for(auto u: edges){
        ll f = u.first, s = u.second;
        for(ll i=1;i<=n;i++){
            if( bs(v[f],i) && bs(v[s],i) )
                mx = min(mx, sz[f]+sz[s]+sz[i]-6);
        }
    }
    
    cout<< ( mx==1e10 ? -1 : mx )<<endl;
    
    return 0;
}