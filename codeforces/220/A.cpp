#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n], brr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        brr[i] = arr[i];
    }
    
    sort(brr, brr+n);
    
    ll count=0;
    for(ll i=0;i<n;i++)
        if(arr[i]!=brr[i])
            count++;
    
    cout<< ( count>2 ? "NO" : "YES" )<<endl;
    
    return 0;
}