#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)   
        cin>>u;
    
    vector<ll> brr(n);
    brr[n-1] = arr[n-1];
    for(ll i=n-2;i>=0;i--){
        brr[i] = arr[i] + brr[i+1];
        brr[i] %= mod;
    }
    
    ll ans = 0;
    
    for(ll i=0;i<n-1;i++){
        ll x = arr[i]*brr[i+1];
        x %= mod;
        ans = ( ans + x )%mod;
        ans %= mod;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
