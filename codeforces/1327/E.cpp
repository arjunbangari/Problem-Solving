#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll modularexp(ll x,ll n,ll M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)  
        return modularexp((x*x)%M,n/2,M);
    else                             
        return (x*modularexp((x*x)%M,(n-1)/2,M))%M;
}

int main(){
    fast;
    
    ll n, m=998244353;
    cin>>n;
    
    ll arr[n+1];
    arr[n] = 10;
    for(ll i=1;i<n;i++){
        arr[i] = (2*9*modularexp(10,n-i,m))%m;
        arr[i] += ((n-i-1)*9*9*modularexp(10,n-i-1,m))%m;
    }
        
    for(ll i=1;i<=n;i++)
        cout<<arr[i]%m<<" ";
    
    return 0;
}