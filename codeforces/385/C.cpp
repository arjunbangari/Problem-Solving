#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e7+1;
ll const mod = 1e9+7;

// code begins here
vector<ll> arr(maxn), prime(maxn, true), val(maxn), crr(maxn);
ll n;

void sieve(){
    for(ll i=2;i<maxn;i++){
        if(prime[i]){
            for(ll j=i;j<maxn;j+=i){
                val[i] += crr[j];
                prime[j] = false;
            }
        }
    }
}

int main(){
    fast;
    
    cin>>n;
    
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        crr[arr[i]]++;
    }
    
    sieve();
    
    for(ll i=1;i<maxn;i++)
        val[i] += val[i-1];
    
    ll m;
    cin>>m;
    
    while(m--){
        ll l, r;
        cin>>l>>r;
        
        ll ans = val[min(r, maxn-1)] - val[min(l-1, maxn-1)];
        cout<<ans<<endl;
    }
    
    return 0;
}