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
    
    ll n,t;
    cin>>n>>t;
    
    ll ans, mn = inf;
    
    for(ll i=0;i<n;i++){
        ll s,d;
        cin>>s>>d;
        
        while(s<t)
            s += d;
        
        if(s<mn)
            ans = i+1;
        mn = min(mn, s);
    }
    
     cout<<ans<<endl;
    
    return 0;
}