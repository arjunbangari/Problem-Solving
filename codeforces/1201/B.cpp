#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,sum=0,mx=-1;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
        if(arr[i]>mx)
            mx=arr[i];
    }
    
    if(sum%2==0 && (sum-mx)>=mx)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}