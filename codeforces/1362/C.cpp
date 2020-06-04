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

ll func(ll n){
    ll ans = 1;
    while(n>0){
        n /= 2;
        ans *= 2;
    }
    
    return ans;
}

ll solve(ll n){
    if(n==0)
        return 0;
    
    if(n==1)
        return 1;
    
    if(n==2)
        return 3;
    
    ll val = func(n);
    ll ans = val - 1;
    
    ans += solve(n - val/2);
    return ans;
    
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll ans = solve(n);
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}