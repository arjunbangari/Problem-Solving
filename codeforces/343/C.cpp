#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> h(n), p(m);
    
    for(auto &u: h)
        cin>>u;
    
    for(auto &u: p)
        cin>>u;
    
    ll l = 0, r = inf, ans;
    
    while(l<=r){
        ll t = (l+r)/2;
        // ll t = 5;
        
        ll hl = 0, pl = 0;
        
        // cout<<t<<" ";
        
        while(hl<n && pl<m){
            ll mx;
            if( h[hl]<= p[pl])
                mx = h[hl]+t;
            else  {
                if( (h[hl]-p[pl])>t )
                    break;
                
                ll x = h[hl] - p[pl];
                mx = h[hl] + max( t - 2*x, (t - x)/2 );
            }
            
            // cout<<hl<<" "<<pl<<" "<<mx<<" ";
            
            hl++;
            while(pl<m && p[pl]<=mx)
                pl++;
            
            // cout<<pl<<endl;
        }
        
        // cout<<hl<<" "<<pl<<endl;
        
        if(pl<m){
            l = t+1;
        } else {
            ans = t;
            r = t-1;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}