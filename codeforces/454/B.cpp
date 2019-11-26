#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll count=0,ind;
    
    for(ll i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            count++;
            ind = i;
        }
    }
    
    if(count==0)
        cout<<0<<"\n";
    else if(count==1){
        ll flag=0;
        for(ll i=ind+1;i<(n+ind);i++){
            if(arr[i%n]>arr[(i+1)%n]){
                flag = 1;
                break;
            }
        }
        
        if(flag)
            cout<<-1<<"\n";
        else
            cout<<n-ind-1<<"\n";
    }
    else
        cout<<-1<<"\n";
    
    return 0;
}
