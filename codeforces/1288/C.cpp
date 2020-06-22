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

int nCrModp(ll n, ll r, ll p=mod) { 
    if (r > n - r) 
        r = n - r; 
    ll C[r + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (ll i = 1; i <= n; i++) { 
        for (ll j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j - 1]) % p; 
    } 
    return C[r]; 
} 

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    cout<<nCrModp(n + 2*m - 1, 2*m)<<endl;
    
    return 0;
}