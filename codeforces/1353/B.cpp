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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        
        vector<ll> a(n), b(n);
        for(auto &u: a)
            cin>>u;
            
        for(auto &u: b)
            cin>>u;
            
        sort(b.rbegin(), b.rend());
        for(ll i=0;i<k;i++)
            a.push_back(b[i]);
        
        ll ans = 0;
        
        sort(a.rbegin(), a.rend());
        
        for(ll i=0;i<n;i++)
            ans += a[i];
        
        cout<<ans<<endl;
        
        
    }
    
    return 0;
}