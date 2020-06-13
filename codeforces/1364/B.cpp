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
        
        vector<ll> ans;
        ans.push_back(arr[0]);
        
        ll i = 0;
        while(i<n){
            ll j = i+1;
            
            if(j==n)
                break;
            
            if(arr[j]<arr[j-1]){
                while(j<n && arr[j]<arr[j-1])
                    j++;
            } else {
                while(j<n && arr[j]>arr[j-1])
                    j++;
            }
            j--;
            ans.push_back(arr[j]);
            i = j;
        }
        
        ll sz = ans.size();
        
        cout<<sz<<endl;
        for(auto u: ans)
            cout<<u<<" ";
        cout<<endl;
        
        
    }
    
    return 0;
}
