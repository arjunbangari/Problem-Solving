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
    
    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    
    ll x = lcm(a,b);
    ll ans = (n/x)*max(p, q) + (n/a - n/x)*p + (n/b - n/x)*q;
    
    cout<<ans<<endl;
    
    return 0;
}