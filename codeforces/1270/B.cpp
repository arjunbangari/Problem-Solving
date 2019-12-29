#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,maxi=0,mini=1000000001,mxp,mip;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll left=-1,right=-1;
        for(ll i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])>=2){
                left = i;
                right = i+1;
            }
        }
        if(left==-1){
            cout<<"NO"<<"\n";
        } else {
            cout<<"YES"<<"\n";
            cout<<left+1<<" "<<right+1<<"\n";
        }
        
    }
    return 0;
}
