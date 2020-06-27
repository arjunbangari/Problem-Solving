#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;
 
// code begins here

ll power(ll x, ll y, ll p = mod) { 
    ll res = 1;  
    x = x % p; 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 

        y = y >> 1; 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
ll modInverse(ll n, ll p = mod) { 
    return power(n, p - 2, p); 
} 
 
ll ncr(ll n, ll r, ll p = mod) { 
    if (r == 0) 
        return 1; 

    ll fac[n + 1]; 
    fac[0] = 1; 
    for (ll i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    if(n==2){
        cout<<0<<endl;
        return 0;
    }
    
    ll ans = ncr(m, n-1)%mod;
    ans = (ans*(n-2))%mod;
    ans = (ans*power(2, n-3))%mod;
    
    cout<<ans%mod<<endl;
    
    return 0;
}