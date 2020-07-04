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
    cin>>n>>k;
    
    ll arr[n][n];
    
    ll cur = 1;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<k-1;j++){
            arr[i][j] = cur;
            cur++;
        }
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=k-1;j<n;j++){
            arr[i][j] = cur;
            cur++;
        }
    }
    
    ll ans = 0;
    for(ll i=0;i<n;i++)
        ans += arr[i][k-1];
    
    cout<<ans<<endl;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}