#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

ll solve(ll lc, ll mx, ll n){
    ll x = n/lc;
    ll rem = n%lc;
    ll val = (lc - mx)*x;
    val += max(0LL, rem - mx + 1 );
    
    return val;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll a,b,q;
        cin>>a>>b>>q;
        
        ll lc = lcm(a,b);
        ll mx = max(a,b);
        
        while(q--){
            ll l,r;
            cin>>l>>r;
            
            ll ans1 = solve(lc,mx,r);
            ll ans2 = solve(lc,mx,l-1);
            
            cout<<ans1 - ans2<<" ";
        }
        
        cout<<endl;
    }
    
    return 0;
}