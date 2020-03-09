#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        sort(arr,arr+n);
        
        for(ll i=n-1;i>=0;i--)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}