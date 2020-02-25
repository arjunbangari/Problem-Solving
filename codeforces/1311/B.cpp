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
        ll n,m;
        cin>>n>>m;
        ll arr[n+1];
        arr[n] = 1e6;
        ll p[m];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        for(ll i=0;i<m;i++)
            cin>>p[i];
        
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(arr[p[j]-1]>arr[p[j]])
                    swap(arr[p[j]-1],arr[p[j]]);
            }
        }
        ll flag = 0;
        for(ll i=0;i<n;i++){
            if(arr[i]>arr[i+1])
                flag = 1;
        }
        
        cout<< ( flag ? "NO" : "YES" )<<endl;
    }
    return 0;
}