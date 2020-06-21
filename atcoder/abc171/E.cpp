#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n), brr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll x = 0;
    for(ll i=n-1;i>1;i--)
        x ^= arr[i];
    
    brr[0] = x^arr[1];
    
    for(ll i=1;i<n;i++)
        brr[i] = arr[i]^arr[i-1]^brr[i-1];
    
    for(auto u: brr)
        cout<<u<<" ";
    cout<<endl;
    
    return 0;
}