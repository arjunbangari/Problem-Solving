#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(ll i=1;i<n;i++)
        arr[i]+=arr[i-1];
    ll ans[n];
    for(ll i=0;i<m;i++){
        ans[i] = arr[i];
        cout<<ans[i]<<" ";
    }
    for(ll i=m;i<n;i++){
        ans[i] = arr[i] + ans[i-m];
        cout<<ans[i]<<" ";
    }
    return 0;
}
