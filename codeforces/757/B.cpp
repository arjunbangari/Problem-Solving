#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll MAXN = 100005;
map<ll,ll> mp;

ll spf[100005];

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
    spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
void getFactorization(ll x) { 
    unordered_set<ll> us;
    while (x != 1) { 
        us.insert(spf[x]);
        x = x / spf[x]; 
    } 
    for(ll u: us)
        mp[u]++;
}

int main(){
    fast;
    ll n,s;
    cin>>n;
    
    sieve();
    
    for(ll i=0;i<n;i++){
        cin>>s;
        getFactorization(s);
    }
    
    ll mx = 1;
    
    for(auto u: mp)
        mx = max(mx,u.second);

    cout<<mx<<endl;
    
    return 0;
}