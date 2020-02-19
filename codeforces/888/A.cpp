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
    
    ll ans = 0 ;
    for(ll i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            ans++;
        if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
            ans++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}