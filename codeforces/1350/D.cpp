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

void solve(){
    ll n,k;
    cin>>n>>k;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
        
    ll flag = 1;
    for(ll i=0;i<n;i++)
        if(arr[i]==k)
            flag = 0;
    
    if(flag){
        cout<<"no"<<endl;
        return;
    }
    
    if(n==1){
        cout<<"yes"<<endl;
        return;
    }
        
    for(ll i=0;i<n-1;i++){
        ll a = min(arr[i], arr[i+1]);
        if(a>=k){
            cout<<"yes"<<endl;
            return;
        }
    }
    
    for(ll i=0;i<n-2;i++){
        vector<ll> temp({arr[i], arr[i+1], arr[i+2]});
        sort(temp.begin(), temp.end());
        
        if(temp[1]>=k){
            cout<<"yes"<<endl;
            return;
        }
    }
    
    cout<<"no"<<endl;
    return;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    
    while(t--){
        solve();
    }
    
    return 0;
}