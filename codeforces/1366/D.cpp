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
vector<ll> ans1(1e6), ans2(1e6), spf(maxn, 0);

void find_spf() { 
    for (ll i = 2; i <maxn; i++) { 
        if (spf[i] == 0) { 
            spf[i] = i; 
            for (ll j = 2*i; j < maxn; j += i) 
                spf[j] = i;
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

    find_spf();
    
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
