#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
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
        ll n,k;
        cin>>n>>k;
        
        vector<ll> arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
            
        ll mx = 0, left = 0;
        vector<ll> ispeak(n, 0);
        
        for(ll i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                ispeak[i] = 1;
        }
        
        for(ll i=1;i<n;i++)
            ispeak[i] += ispeak[i-1];
        
        ll i =0, j= i+k-1;
        // for(ll p=1;p<j;p++){
        //     if(arr[p]>arr[p-1] && arr[p]>arr[p+1]){
        //         ispeak[p] = 1;
        //         mx++;
        //     }
        // }
        
        while(i<n && j<n){
            
            ll temp = ispeak[j-1] - ispeak[i];
            if(temp>mx)
                left = i;
            mx = max(mx, temp);
            i++;
            j++;
            
            // ll maxi = 0;
            
            // i++;
            // if(ispeak[i])
            //     maxi--;
                
            // if((j+1)!=n){
            //     if(arr[j]>arr[j-1] && arr[j]>arr[j+1]){
            //         maxi++;
            //         ispeak[j] = 1;
            //     }
            // }

            // if(maxi>mx)
            //     left = i;
            // mx = max(mx, maxi);
            // j++;
        }
        
        cout<<mx+1<<" "<<left+1<<endl;
    }
    
    return 0;
}