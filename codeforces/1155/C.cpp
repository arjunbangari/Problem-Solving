#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll brr[m];
    for(ll i=0;i<m;i++)
        cin>>brr[i];
        
    ll gcd = arr[1]-arr[0];
    
    for(ll i=2;i<n;i++)
        gcd = __gcd(gcd, arr[i]-arr[i-1]);
    
    ll l= arr[0],r=-1;
    
    for(ll i=0;i<m;i++)
        if(gcd%brr[i]==0)
            r = i+1;
    
    if(r==-1)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<l<<" "<<r<<endl;
    }
    
    return 0;
}