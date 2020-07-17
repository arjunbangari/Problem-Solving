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
        vector<ll> arr(3);
        cin>>arr[0]>>arr[1]>>arr[2];
        
        sort(arr.begin(), arr.end());
        
        if(arr[0]==arr[1] || arr[1]==arr[2] || arr[0]==arr[2]){
            if(arr[0]==arr[1] && arr[1]!=arr[2]){
                cout<<"NO"<<endl;
                continue;
            }
            cout<<"YES"<<endl;
            cout<<arr[0]<<" "<<arr[0]<<" "<<arr[1]<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}