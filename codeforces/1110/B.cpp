#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m,k;
    cin>>n>>m>>k;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    vector<ll> diff;
    for(ll i=1;i<n;i++)
        diff.push_back(arr[i]-arr[i-1]);
    
    sort(diff.begin(), diff.end());
    
    ll ans = n;
    ll cnt = n-k;
    
    for(ll i=0;i<cnt;i++)  
        ans += diff[i]-1;
    
    cout<<ans<<endl;
    
    return 0;
}