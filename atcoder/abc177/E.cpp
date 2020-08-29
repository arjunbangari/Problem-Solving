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

vector<ll> spf(maxn);

void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<maxn; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (ll i=4; i<maxn; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<maxn; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (ll j=i*i; j<maxn; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
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
    
    ll flag = 0;
    
    map<ll, ll> mp;
    
    for(auto u: arr){
        set<ll> s;
        ll x = u;
        while(x!=1){
            s.insert(spf[x]);
            x /= spf[x];
        }
        
        for(auto v: s){
            if(mp[v]){
                flag = 1;
                break;
            }
            mp[v] = 1;
        }
        
        if(flag)
            break;
    }
    
    if(!flag){
        cout<<"pairwise coprime"<<endl;
        return 0;
    }

    ll g = 0;
    for(auto u: arr)
        g = __gcd(g, u);
    
    if(g==1){
        cout<<"setwise coprime"<<endl;
    } else {
        cout<<"not coprime"<<endl;
    }
    
    return 0;
}