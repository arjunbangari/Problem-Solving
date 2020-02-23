#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,mx=-1,pos;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
        
    ll res;
    mx = -1;
    
    for(ll j=0;j<n;j++){
        pos = j;
        ll i = pos-1,ans=arr[pos],last=arr[pos];
        while(i>=0){
            last = min(arr[i],last);
            ans += last;
            i--;
        }
        i = pos+1;
        last = arr[pos];
        while(i<n){
            last = min(arr[i],last);
            ans += last;
            i++;
        }
        if(ans>mx){
            res = pos;
            mx = ans;
        }
    }
    
    ll i = res-1;
    while(i>=0){
        arr[i] = min(arr[i],arr[i+1]);
        i--;
    }
    i = res+1;
    while(i<n){
        arr[i] = min(arr[i],arr[i-1]);
        i++;
    }
    
    
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}