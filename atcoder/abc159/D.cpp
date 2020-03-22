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
    
    ll brr[n+1]={0}, crr[n+1];
    
    for(ll i=0;i<n;i++)
        brr[arr[i]]++;
    
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        crr[i] = (brr[i]*(brr[i]-1))/2;
        ans += crr[i];
    }
    
    for(ll i=0;i<n;i++)
        cout<<ans - (brr[arr[i]]-1)<<endl;
    
    
    return 0;
}