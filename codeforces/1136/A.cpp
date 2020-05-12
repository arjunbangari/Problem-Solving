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

int main(){
    fast;
    
    ll n,k;
    cin>>n;
    
    vector<pll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    cin>>k;
    
    
    ll ans = 0;
    
    for(ll i=0;i<n;i++){
        if(arr[i].second<k)
            ans++;
    }
    
    cout<<n - ans<<endl;
    
    
    return 0;
}