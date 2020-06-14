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
    
    ll n,q,a,b;
    cin>>n>>q;
    
    vector<pll> arr(n);
    vector<multiset<ll>> v(maxn);
    multiset<ll> final;
    
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        v[b].insert(a);
        arr[i] = {a,b};
    }
    
    for(ll i=1;i<maxn;i++){
        if(!v[i].empty()){
            auto tmp = v[i].rbegin();
            final.insert(*tmp);
        }
    }
    
    while(q--){
        cin>>a>>b;
        a--;
        
        ll prev = arr[a].second;
        ll next = b;
        arr[a].second = b;
        
        ll key = *v[prev].rbegin();
        auto it1 = final.lower_bound(key);
        final.erase(it1);
        
        if(!v[next].empty()){
            key = *v[next].rbegin();
            auto it2 = final.lower_bound(key);
            final.erase(it2);
        }
        
        auto it3 = v[prev].lower_bound(arr[a].first);
        v[prev].erase(it3);
        if(!v[prev].empty())
            final.insert(*v[prev].rbegin());
        
        v[next].insert(arr[a].first);
        final.insert(*v[next].rbegin());
        
        cout<<(*final.begin())<<endl;
        
    }
    
    return 0;
}
