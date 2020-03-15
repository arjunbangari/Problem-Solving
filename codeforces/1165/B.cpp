#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    
    ll counter=1, i=0;
    while(i<n){
        if(arr[i]>=counter)
            counter++;
        i++;
    }
    
    cout<<counter-1<<endl;
    
    
    return 0;
}