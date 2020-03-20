#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    
    ll brr[n];
    for(ll i=0;i<n;i++)
        cin>>brr[i];
    
    ll arr[n];
    ll cur_max = 0;
    
    for(ll i=0;i<n;i++){
        arr[i] = brr[i] + cur_max;
        cur_max = max(cur_max, arr[i]);
    }
    
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}