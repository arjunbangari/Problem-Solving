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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n+1);
    arr[1] = 2;
    for(ll i=2;i<=n;i++)
        arr[i] = arr[i-1]*2;
    
    ll ans = 0;
    for(ll i=1;i<=n;i++)
        ans += arr[i];
    
    cout<<ans<<endl;
     
    return 0;
}