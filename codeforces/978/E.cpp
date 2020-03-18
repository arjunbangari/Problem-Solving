#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,w;
    cin>>n>>w;
    
    ll arr[n+1];
    arr[0] = 0;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        arr[i] = (arr[i-1]-arr[i]);
    }
    
    ll mx = *max_element(arr,arr+n+1);
    ll mn = *min_element(arr,arr+n+1);
    
    ll ans = max(0LL, w - mx + mn + 1);
    
    cout<<ans<<endl;
    
    return 0;
}