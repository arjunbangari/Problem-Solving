#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e7;
ll const mod = 1e9+7;

// code begins here

vector<ll> spf(maxn);
 
void sieve() { 
    spf[1] = 1; 
    for (ll i=2; i<maxn; i++) 
        spf[i] = i; 
    for (ll i=4; i<maxn; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<maxn; i++) { 
        if (spf[i] == i) { 
            for (ll j=i*i; j<maxn; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    sieve();
    
    ll allgcd = 0;
    for(auto u: arr)
        allgcd = __gcd(allgcd, u);
    
    map<ll, ll> mp;
    
    for(auto u: arr){
        ll x = u/allgcd;
        set<ll> s;
        while(x!=1){
            s.insert(spf[x]);
            x = x/spf[x];
        }
        for(auto v: s)
            mp[v]++;
    }
    
    ll ans = inf;
    
    for(auto u: mp)
        ans = min(ans, n - u.second);
    
    cout<< ( ans==inf ? -1 : ans ) <<endl;
    
    return 0;
}