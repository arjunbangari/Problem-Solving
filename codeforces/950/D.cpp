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

ll n, q;

ll solve(ll x){
    if(x&1)
        return (x+1)/2;
    
    ll to_right = n - x/2;
    return solve(x+to_right);
}

int main(){
    fast;
    
    cin>>n>>q;
    
    while(q--){
        ll x;
        cin>>x;
        
        ll ans = solve(x);
        cout<<ans<<endl;
    }
    
    return 0;
}