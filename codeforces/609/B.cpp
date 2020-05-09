#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll cnt[m+1] = {0};
    
    for(ll i=0;i<n;i++)
        cnt[arr[i]]++;
    
    ll ans = 0;
    for(ll i=1;i<=m;i++)
        ans += cnt[i]*(n - cnt[i]);
    
    cout<<ans/2<<endl;
    
    return 0;
}