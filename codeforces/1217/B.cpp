#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,x,d,h,ans=0;
        cin>>n>>x;
        
        ll di[n];
        ll diff[n];
        for(ll i=0;i<n;i++){
           cin>>d>>h;
           di[i] = d;
           diff[i] = d-h;
        }
        
        sort(di,di+n);
        sort(diff,diff+n);
        if(di[n-1]<x && diff[n-1]<=0)
            cout<<-1<<endl;
        else {
            if(di[n-1]>=x)
                cout<<1<<endl;
            else{
                ll k = ceil((double)(x - di[n-1])/(double)diff[n-1]);
                cout<<k+1<<endl;
            }
        }
    }
    return 0;
}