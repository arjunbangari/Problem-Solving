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

string secret = "skdsksdsddssdsd";
vector<ll> pre(maxn);
string a,b;
ll a_hash = 0 , b_hash = 0, n1, inverse, key=26;

void compute_key(){
    key = 0;
    for(ll i=1;i<secret.length();i++)
        key = ( key + pre[i]*(secret[i]-'a'+1))%mod;
}

void precompute(){
    pre[0] = 1;
    for(ll i=1;i<maxn;i++)
        pre[i] = (pre[i-1]*key)%mod;
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

void compute_hash(){
    for(ll i=0;i<n1;i++){
        a_hash = (a_hash + pre[i]*(a[i]-'a'+1))%mod;
        b_hash = (b_hash + pre[i]*(b[i]-'a'+1))%mod;
    }
    
}

string longest_prefix_palindrome(){
    b = a;
    reverse(b.begin(), b.end());
    
    compute_hash();
    
    ll i = n1-1;
    
    while(i>=0){
        if(a_hash==b_hash)
            break;
        
        a_hash = (a_hash - ((a[i]-'a'+1)*pre[i])%mod + mod)%mod;
        b_hash = (b_hash - (a[i]-'a'+1) + mod)%mod;
        b_hash = ( b_hash * inverse)%mod;
        i--;
    }
    
    return a.substr(0,i+1);
    
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    precompute();
    compute_key();
    precompute();
    
    inverse = modInverse(key, mod);
    inverse %= mod;
    
    while(t--){
        string s;
        cin>>s;
        
        ll n = s.length();
        
        //Find palindrome from both sides
        
        ll i = 0;
        while(i<n && s[i]==s[n-i-1])
            i++;
        
        if(i==n){
            cout<<s<<endl;
            continue;
        }
        
        string ans = s.substr(0,i);
        string ans2 = ans;
        reverse(ans2.begin(), ans2.end());
        
        // Remaining string
        a = s.substr(i,n - 2*i);
        
        // length of remaining string
        n1 = n - 2*i;
        
        // calculate longest_prefix_palindrome for string
        a_hash = 0; b_hash = 0;
        string fi = longest_prefix_palindrome();
        
        // cout<<fi<<endl;
        
        //calculate longest_prefix_palindrome for reverse
        a = b;
        a_hash = 0; b_hash = 0;
        string se = longest_prefix_palindrome();
        reverse(se.begin(), se.end());
        
        ll c = fi.length(), d = se.length();
        
        if(c>d){
            ans += fi + ans2;
        } else {
            ans += se + ans2;
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}