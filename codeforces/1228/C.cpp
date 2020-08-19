#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> prime;

void prime_factors(ll n){
    if(n%2==0)
        prime.push_back(2);
    
    while (n%2 == 0)
        n /= 2; 
 
    for (int i = 3; i <= sqrt(n); i = i+2) { 
        if(n%i==0)
            prime.push_back(i);
            
        while (n%i == 0) 
            n /= i;
    } 
    
    if (n > 2) 
        prime.push_back(n);
}

ll binpow(ll a, ll b, ll m=mod) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    fast;
    
    ll x,n;
    cin>>x>>n;
    
    prime_factors(x);
    
    ll ans = 1;
    
    for(auto u: prime){
        ll x = u;
        while(1){
            ld tmp = ((ld)n/(ld)x);
            if((ld)u>tmp)
                break;
            x *= u;
        }
        
        ll sum = 0;
        
        while(x!=1){
            ll cnt = n/x;
            cnt -= sum;
            sum += cnt;
            
            ans = (ans*binpow(x, cnt));
            ans %= mod;
            x /= u;
        }
    }
    
    cout<<ans%mod<<endl;
    
    return 0;
}