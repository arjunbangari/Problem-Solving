#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){   
    fast;
    ll n,m,sum=0,t,v,x,y,q;
    cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    while(m--){
        cin>>t;
        if(t==1){
            cin>>v>>x;
            arr[v-1] = x-sum;
        }
        else if(t==2){
            cin>>y;
            sum+=y;
        }
        else {
            cin>>q;
            cout<<arr[q-1]+sum<<"\n";
        }
    }
}
