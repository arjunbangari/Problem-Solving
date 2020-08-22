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
    
    ll a,b,c,d,e,f,g;
    cin>>a>>b>>c>>d>>e>>f;
    
    g = min(b,c);
    
    ll ans = 0;
    
    if(e>f){
        ll x = min(a, d);
        ans = x*e;
        a -= x;
        d -= x;
    } else {
        ll y = min(g, d);
        ans = y*f;
        g -= y;
        d -= y;
    }
    
    ans += min(a, d)*e;
    ans += min(g, d)*f;
    
    cout<<ans<<endl;
    
    return 0;
}