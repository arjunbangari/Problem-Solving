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
        ll n;
        cin>>n;
        
        set<ll> s;
        
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            s.insert(x);
        }
        
        ll ans = -1;
        
        for(ll i=1;i<=1024;i++){
            set<ll> st;
            
            for(auto u: s)
                st.insert(u^i);
            
            if(s==st){
                ans = i;
                break;
            }
        }
        
        cout<<ans<<endl;
        
        
        
    }
    
    return 0;
}