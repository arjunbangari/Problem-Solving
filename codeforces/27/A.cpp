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
    
    sort(arr,arr+n);
    if(arr[0]!=1)
        cout<<1<<endl;
    else{
        ll flag = 0;
        for(ll i=1;i<n;i++){
            if(arr[i]!=(arr[i-1]+1)){
                cout<<arr[i-1]+1<<endl;
                flag = 1;
                break;
            }
        }
        if(flag==0)
            cout<<arr[n-1]+1<<endl;
    }
    return 0;
}