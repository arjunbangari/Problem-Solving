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
vector<ll> hashx(maxn), pre(maxn), dvs;
map<string,ll> mp;

void preprocess(){
    pre[0] = 1;
    for(ll i=1;i<maxn;i++)
        pre[i] = (pre[i-1]*53)%mod;
}

void compute_hash(){
    hashx[0] = s[0]-'a'+1;
    for(ll i=1;i<n;i++)
        hashx[i] = (hashx[i-1] + pre[i]*(s[i]-'a'+1))%mod;
}

ll sub_hash(ll i, ll j){
    ll hash_value;
    if(i)
        hash_value = ( hashx[j] - hashx[i-1] + mod )%mod;
    else
        hash_value = hashx[j];
    hash_value %= mod;
    return hash_value;
}

void find_divisors(){
    dvs.clear();
    
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i==n/i)
                dvs.push_back(i);
            else{
                dvs.push_back(i);
                dvs.push_back(n/i);
            }
        }
    }
}

bool check(ll i1, ll j1, ll i2, ll j2){
    ll h1 = sub_hash(i1, j1);
    ll h2 = sub_hash(i2, j2);
    return (h1*pre[i2-i1])%mod==h2;
}

void solve(){
    cin>>s;
    n = s.length();
    
    compute_hash();
    find_divisors();
    
    for(auto u: dvs){
        ll flag = 1;
        
        for(ll i=u;i+u<=n;i+=u){
            if(check(0, u-1, i, i+u-1))
                continue;
            else{
                flag = 0;
                break;
            }
        }
        
        if(flag)
            mp[s.substr(0,u)]++;
    }
}

int main(){
    fast;
    
    preprocess();
    
    solve();
    solve();
    
    ll cnt = 0;
    
    for(auto u: mp){
        if(u.second>=2)
            cnt++;
    }
    
    cout<<cnt<<endl;

    return 0;
}
