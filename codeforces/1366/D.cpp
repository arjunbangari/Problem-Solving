#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e7+5;
ll const mod = 1e9+7;

// code begins here
vector<bool> prime(maxn, true);
vector<ll> ans1(1e6), ans2(1e6), spf(maxn);

void SieveOfEratosthenes() {
    for(ll i=1;i<maxn;i++)
        spf[i] = i;
    
    for (ll p=2; p*p<=maxn; p++) { 
        if (prime[p]) { 
            for (ll i=p*p; i<maxn; i += p) {
                prime[i] = false; 
                spf[i] = p;
            }
        } 
    } 
} 

void solve(ll ind, ll n){
    ll x = spf[n];
    while(n%x==0)
        n /= x;
        
    if(n==1){
        ans1[ind] = -1;
        ans2[ind] = -1;
    } else {
        ans1[ind] = x;
        ans2[ind] = n;
    }
   return;
}

int main(){
    fast;

    SieveOfEratosthenes();
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    for(ll i=0;i<n;i++)
        solve(i, arr[i]);
    
    for(ll i=0;i<n;i++)
        cout<<ans1[i]<<" ";
    cout<<endl;
    
    for(ll i=0;i<n;i++)
        cout<<ans2[i]<<" ";
    
    return 0;
}
