#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll ans = 1;
        
        ll flag = 0;
        
        for(ll i=0;i<n;i++)
            if(arr[i]!=1)
                flag = 1;
            
        if(!flag){
            cout<< (n%2==0 ? "Second" : "First")<<endl;
            continue;
        }
        
        // for(ll i=0;i<n;i++){
        //     if(arr[i]==1){
        //         ll j = i, cnt = 0;
        //         while(j<n && arr[j]==1){
        //             j++;
        //             cnt++;
        //         }
                
        //         if(cnt==1){
        //             if(i==0){
        //                 ans = !ans;
        //             }
        //         } else {
        //             if(j!=n){
        //                 if(cnt%2)
        //                     ans = !ans;
        //             }
        //         }
        //         i = j;
        //     }
        // }
        
        ll i = 0;
        while(arr[i]==1){
            i++;
        }
        
        if(i%2!=0){
            ans = !ans;
        }
        
        cout<<(ans ? "First" : "Second")<<endl;
        
    }
    
    return 0;
}