#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    ll ans = 0;
    
    for(ll i=0;i<n/2;i++)
        ans += (arr[i]+arr[n-i-1])*(arr[i]+arr[n-i-1]);
    
    cout<<ans<<endl;
    
    return 0;
}