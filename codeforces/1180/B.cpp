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
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>=0)
            arr[i] = -(arr[i]+1);
    }
    
    if(n%2){
        ll mx = -1, pos = -1;
        
        for(ll i=0;i<n;i++){
            ll val = abs(arr[i]);
            if(val>mx){
                mx = val;
                pos = i;
            }
        }
        
        arr[pos] = -arr[pos]-1;
    }
    
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}