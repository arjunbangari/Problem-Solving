#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;

    ll n;
    cin>>n;
    
    vector<pll> v(n), edges;
    for(ll i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    
    multiset<pll> ms;
    
    for(ll i=0;i<n;i++){
        if(v[i].first==1){
            ms.insert({1LL,i});
        }
    }
    
    while(!ms.empty()){
        pll val = *ms.begin();
        ms.erase(ms.begin());
        
        ll ind = val.second;
        
        if(v[ind].first==0)
            continue;
        
        ll con = v[ind].second;
        edges.push_back({ind, con});
        
        v[con].second ^= ind;
        v[con].first--;
        if(v[con].first==1)
            ms.insert({v[con].first, con});
    }
    
    ll sz = edges.size();
    cout<<sz<<endl;
    for(auto u: edges)
        cout<<u.first<<" "<<u.second<<endl;
    
    return 0;
}
