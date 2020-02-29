#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,x,ans=0;
    cin>>n>>x;
    ll arr[n];
    ll count[1000001] = {0};
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        count[arr[i]]++;
    }
    
    for(ll i=0;i<n;i++){
        ll temp = arr[i]^x;
        if(temp==arr[i])
            ans += count[temp]-1;
        else
            ans += count[temp];
    }
    
    cout<<ans/2<<endl;
    
    return 0;
}