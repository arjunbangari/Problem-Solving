#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    
    if(k<n/2 || (n==1 && k!=0))
        cout<<-1<<endl;
    else if(n==1 && k==0)
        cout<<1<<endl;
    else{
        ll arr[n];
        
        ll x = (n-2)/2;
        arr[0] = k-x;
        arr[1] = 2*(k-x);
        ll temp = arr[1]+1;
        
        for(ll i=2;i<n;i++)
            arr[i] = (temp++);
        
        for(ll i=0;i<n;i++)
            cout<<arr[i]<<" ";
            
    }
    
    return 0;
}