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

ll minimum (ll n){
    ll mn = inf;
    while(n>0){
        ll rem = n%10;
        mn = min(mn, rem);
        n /= 10;
    }
    
    return mn;
}

ll maximum(ll n){
    ll mx = -1;
    while(n>0){
        ll rem = n%10;
        mx = max(mx, rem);
        n /= 10;
    }
    return mx;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll a,k;
        cin>>a>>k;
        
        ll i=1;
        while(i<k){
            ll mn = minimum(a);
            ll mx = maximum(a);
            a += mn*mx;
            i++;
            if(mn*mx==0)
                break;
        }
        
        cout<<a<<endl;
    }
    
    return 0;
}