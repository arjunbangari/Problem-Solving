#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,q;
    cin>>n>>q;
    
    vector<ll> coord(n);
    for(auto &u: coord)
        cin>>u;
        
    sort(all(coord));
    
    multiset<ll, greater<ll> > ms;
    set<ll> s;
    
    for(ll i=0;i<n;i++){
        s.insert(coord[i]);
        if(i)
            ms.insert(coord[i]-coord[i-1]);
    }
    
    ll mx, mn, dif_mx;
    
    if(s.empty() || ms.empty()){
        cout<<0<<endl;
    } else {
        mx = *s.rbegin(), mn = *s.begin(), dif_mx = *ms.begin();
        cout<<mx - mn - dif_mx<<endl;
    }
    
    while(q--){
        ll t, x;
        cin>>t>>x;
        
        if(t){
            s.insert(x);
            auto it = s.lower_bound(x);
            
            if(next(it)!=s.end() && it!=s.begin()){
                ll dif = *next(it) - *prev(it);
                ms.erase(ms.lower_bound(dif));
            }
            
            if(next(it)!=s.end())
                ms.insert(*next(it) - x);
            
            if(it!=s.begin())
                ms.insert(x - *prev(it));
                
        } else {
            auto it = s.lower_bound(x);
            
            if(next(it)!=s.end())
                ms.erase(ms.lower_bound(*next(it) - x));
            
            if(it!=s.begin())
                ms.erase(ms.lower_bound(x - *prev(it)));
            
            if(next(it)!=s.end() && it!=s.begin())
                ms.insert(*next(it) - *prev(it));
            
            s.erase(x);
        }
        
        if(s.empty() || ms.empty()){
            cout<<0<<endl;
        } else {
            mx = *s.rbegin(), mn = *s.begin(), dif_mx = *ms.begin();
            cout<<mx - mn - dif_mx<<endl;
        }
    }
    
    return 0;
}