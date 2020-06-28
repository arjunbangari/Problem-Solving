#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        map<ll, ll> mp;
        
        multiset<ll> ms;
        
        for(auto u: arr){
            if(u%k==0)
                continue;
            ll x = k - u%k ;
            ll y = x + mp[x]*k;
            mp[x]++;
            ms.insert(y);
        }
        
        auto it = ms.begin();
        ll last = 0, ans = 0;
        
        while(it!=ms.end()){
            ans += (*it) - last + 1;
            last = (*it) + 1;
            it++;
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}