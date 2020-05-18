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

string s;
ll n;
vector<ll> forwardx(maxn), backwardx(maxn), pre(maxn, 0);

void preprocess(){
    pre[0] = 1;
    for(ll i=1;i<=n;i++)
        pre[i] = (pre[i-1]*31)%mod;
}

void compute_hash(){
    forwardx[0] = s[0]-'a'+1;
    for(ll i=1;i<n;i++)
        forwardx[i] = (forwardx[i-1] + pre[i]*(s[i]-'a'+1))%mod;
    
    backwardx[n-1] = s[n-1] - 'a' + 1;
    for(ll i=n-2;i>=0;i--){
        backwardx[i] = (backwardx[i+1]*31)%mod + (s[i] -'a' + 1);
        backwardx[i] %= mod;
    }
}

ll modInverse(ll a, ll m) { 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
  
    while (a > 1) { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 

bool substring(ll i){
    ll hash = forwardx[i];
    
    ll l=0, r = l + i + 1;
    
    while(r<(n-1)){
        ll hash_value = (forwardx[r] - forwardx[l] + mod)%mod;
        ll val = modInverse(pre[l+1], mod)%mod;
        hash_value = (hash_value * val)%mod;
        hash_value %= mod;
        if(hash_value==hash)
            return true;
        l++;
        r++;
    }    
    
    return false;
}

int main(){
    fast;
    
    cin>>s;
    
    n = s.length();
    
    preprocess();
    compute_hash();
    
    ll i=n-1, flag = 0;
    while(i>=0){
        if(forwardx[i]==backwardx[n-i-1]){
            if(substring(i)){
                flag = 1;
                break;
            }
        }
        i--;
    }
    
    cout<< (flag ? s.substr(0,i+1) : "Just a legend" ) <<endl;
    
    return 0;
}