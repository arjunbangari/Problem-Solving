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
    
    ll l,r,a;
    cin>>l>>r>>a;
    
    ll ans = min(l, r);
    ans += min(a, max(l, r) - min(l, r));
    a -= min(a, max(l, r) - min(l, r));
    ans += a/2;
    
    cout<<2*ans<<endl;
    
    return 0;
}