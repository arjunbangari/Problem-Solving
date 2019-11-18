#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int main(){ 
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    ll mid = (n+1)/2;
    ll i = mid-1;
    ll j =n-1;
    ll ans = 0;
    while(i>=0 and j>=mid){
        if(arr[j]>=(2*arr[i])){
            //cout<<arr[i]<<" "<<arr[j]<<"\n";
            ans++;
            j--;
        }
        i--;
    }
    cout<<n-ans<<"\n";
    return 0;
}