#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,ind;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll mx = *max_element(arr,arr+n);
    for(ll i=0;i<n;i++){
        if(arr[i]==mx)
            ind = i; 
    }
    
    ll i=ind+1,flag = 0;
    while(i<n){
        if(arr[i]>arr[i-1]){
            flag = 1;
            break;
        } i++;
    }
    i=ind-1;
    while(i>=0){
        if(arr[i]>arr[i+1]){
            flag=1;
            break;
        }i--;
    }
    
    cout<<(flag ? "NO" : "YES")<<endl;
    
    return 0;
}