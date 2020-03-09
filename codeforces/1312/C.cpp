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
        ll n,k,flag=0;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll count[64] = {0};
        
        for(ll i=0;i<n;i++){
            ll val = arr[i];
            ll j = 0;
            while(val>0){
                ll rem = val%k;
                count[j] += rem;
                if(count[j]>1){
                    flag = 1;
                    break;
                }
                val = val/k;
                j++;
            }
        }
        
        cout<<( flag ? "NO" : "YES")<<endl;
    }
    
    return 0;
}