#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    if(n>m)
        cout<<0<<endl;
    else{
        ll ans = 1;
        for(ll i=0;i<n;i++)
            for(ll j=i+1;j<n;j++)
                ans = (ans*abs(arr[i]-arr[j]))%m;
        cout<<ans%m<<endl;
    }
    
    return 0;
}