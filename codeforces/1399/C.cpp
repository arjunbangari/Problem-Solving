#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
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
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll ans = 0;
        
        for(ll i=1;i<=2*n;i++){
            multiset<ll> ms;
            for(auto u: arr)
                ms.insert(u);
            
            ll cnt = 0;
            
            while(!ms.empty()){
                ll val = *ms.begin();
                ms.erase(ms.begin());
                
                auto it = ms.lower_bound(i-val);
                
                if(it!=ms.end() && (*it)==(i-val)){
                    cnt++;
                    ms.erase(it);
                }
            }
            
            ans = max(ans, cnt);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}