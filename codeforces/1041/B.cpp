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
    
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    
    ll lc = __gcd(x,y);

    ld p1 = (ld)a/(ld)x;
    ld p2 = (ld)b/(ld)y;
    
    ll val = min( p1, p2)*lc;
    
    cout<<val<<endl;
    
    return 0;
}