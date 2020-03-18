#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    
    ll arr[n], brr[m];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    for(ll i=1;i<n;i++)
        arr[i] += arr[i-1];
    
    for(ll i=0;i<m;i++)
        cin>>brr[i];
    
    for(ll i=0;i<m;i++){
        ll temp = upper_bound(arr,arr+n,brr[i]-1) - arr;
        ll ans;
        if(temp==0)
            ans = brr[i];
        else
            ans = brr[i] - arr[temp-1];
        cout<<temp+1<<" "<<ans<<endl;
    }
    
    return 0;
}