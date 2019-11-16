#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){   
    ll n;
    cin>>n;
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
        
    sort(arr+1, arr+n+1);
    ll ans=0;
    for(ll i=1;i<=n;i++)
        ans += abs(i-arr[i]);
    
    cout<<ans<<"\n";
        
    return 0;
}
