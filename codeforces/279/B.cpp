#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n,t,temp;
    cin>>n>>t;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    for(ll i=1;i<n;i++)
        arr[i]+=arr[i-1];
    
    ll ans = -1;
    for(ll i=0;i<n;i++){
        if(arr[i]<=t){
            temp = i+1;
        } else {
            temp = i - (lower_bound(arr,arr+i,arr[i]-t)-arr);
        }
        ans = max(ans, temp);
    }
    
    cout<<ans<<"\n";
    return 0;
}