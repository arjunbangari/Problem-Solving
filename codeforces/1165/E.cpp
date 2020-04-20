#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n, m=998244353;
    cin>>n;
    
    vector<ll> arr(n), brr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    for(ll i=0;i<n;i++)
        cin>>brr[i];
    
    vector<ll> newarr(n);
    for(ll i=0;i<n;i++)
        newarr[i] = arr[i]*(i+1)*(n-i);
        
    
    sort(brr.rbegin(), brr.rend());
    sort(newarr.begin(), newarr.end());
    
    ll ans = 0;
    
    for(ll i=0;i<n;i++)
        ans = ( ans + (brr[i]*(newarr[i]%m))%m )%m;
    
    cout<<ans%m<<endl;
    
    return 0;
}