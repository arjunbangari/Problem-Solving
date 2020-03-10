#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,s;
    cin>>n>>s;
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    ll l=0,r=n,ansk=0,anst=0;
    
    while(l<=r){
        ll k = (l+r)/2;
        ll brr[n+1];
        for(ll i=1;i<=n;i++)
            brr[i] = arr[i] + k*i;
        
        sort(brr+1, brr+n+1);
        ll sum=0;
        for(ll i=1;i<=k;i++)
            sum += brr[i];
        
        if(sum>s)
            r = k-1;
        else{
            ansk = k;
            anst = sum;
            l = k+1;
        }
    }
    
    
    cout<<ansk<<" "<<anst<<endl;
    
    return 0;
}