#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e7+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;

    ll t;
    cin>>t;
    
    while(t--){
        ll n,x,m;
        cin>>n>>x>>m;
        
        ll low = x, high = x;
        
        while(m--){
            ll l,r;
            cin>>l>>r;
            
            if(l>high || r<low)
                continue;
            
            low = min(low, l);
            high = max(high, r);
        }
        
        cout<<high-low+1<<endl;
    }
    
    return 0;
}
