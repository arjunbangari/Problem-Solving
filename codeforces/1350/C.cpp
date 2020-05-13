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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
        
    vector<ll> suffix_gcd(n);
    suffix_gcd[n-1] = arr[n-1];
    
    for(ll i=n-2;i>=0;i--)
        suffix_gcd[i] = __gcd(suffix_gcd[i+1], arr[i]);
    
    ll ans = 0;
    
    for(ll i=0;i<n-1;i++){
        ll temp = (arr[i]*suffix_gcd[i+1])/suffix_gcd[i];
        ans = __gcd(ans, temp);
    }
    
    cout<<ans<<endl;
    
    return 0;
}