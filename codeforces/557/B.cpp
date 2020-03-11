#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    double w;
    cin>>n>>w;
    
    ll arr[2*n];
    for(ll i=0;i<2*n;i++)
        cin>>arr[i];
        
    sort(arr,arr+ n+n);
    
    double x = min(arr[0]*1.0, min(arr[n]*1.0/2*1.0, w*1.0/(3*n)));
    
    double ans = (3*1.0)*(n*1.0)*x;
    cout<<fixed<<setprecision(6)<<ans<<endl;
    
    return 0;
}