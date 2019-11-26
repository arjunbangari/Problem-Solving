#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    ll ans = 1e9;
    
    for(ll i=0;i<n-1;i++){
        ll lower = lower_bound(arr+i,arr+n,2*arr[i]+1) - arr ;
        //cout<<arr[i]<<" "<<lower<<" "<<arr[lower]<<" ";
        lower--;
        if(lower>=0)
            ans = min(ans,n-(lower-i+1));
        //cout<<n-(lower-i+1)<<"\n";
    }

    cout<<ans<<"\n";
    return 0;
}
