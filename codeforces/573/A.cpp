#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    for(ll i=0;i<n;i++){
        while(arr[i]%2==0)
            arr[i] = arr[i]/2;
        while(arr[i]%3==0)
            arr[i] = arr[i]/3;
    }
    ll flag = 1,temp = arr[0];
    for(ll i=1;i<n;i++){
        if(arr[i]!=temp){
            flag = 0;
            break;
        }
    }
    cout<<(flag ? "YES" : "NO");
    return 0;
}