#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n, k;
        cin>>n;
        
        ll arr[n];
        ll ans[n];
        
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll flag = (arr[0]==arr[n-1]);
        for(ll i=1;i<n;i++)
            flag &= (arr[i]==arr[i-1]); 
        
        if(flag){
            k = 1;
            for(ll i=0;i<n;i++)
                ans[i] = 1;
        } else if(n%2==0){
            k = 2;
            for(ll i=0;i<n;i++)
                ans[i] = 1 + (i%2);
        } 
        else {
            flag = !(arr[0]^arr[n-1]);
            
            for(ll i=1;i<n;i++)
                flag |= !(arr[i]^arr[i-1]);
            
            if(flag){
                k = 2;
                ll i=1;
                ans[0] = 1;
                for(i=1;i<n;i++){
                    if(arr[i]==arr[i-1]){
                        ans[i] = ans[i-1];
                        break;
                    } else 
                        ans[i] = ( ans[i-1]==1 ? 2 : 1);
                }
                if(i==n)
                    ans[n-1] = ans[0];
                else{
                    i++;
                    for(;i<n;i++)
                        ans[i] = ( ans[i-1]==1 ? 2 : 1 );
                }
            } else {
                k = 3;
                for(ll i=0;i<n;i++)
                    ans[i] = 1 + (i%2);
                ans[n-1] = 3;
            }
        }
        
        cout<<k<<endl;
        for(ll i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}