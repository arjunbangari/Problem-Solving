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
        ll n,x;
        cin>>n>>x;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll zero = 0, sum = 0;
        
        for(ll i=0;i<n;i++){
            arr[i] %= x;
            sum += arr[i];
            if(!arr[i])
                zero++;
        }
        
        if(zero==n){
            cout<<-1<<endl;
            continue;
        }
        
        ll i = 0, tmp = sum;
        while(tmp%x==0){
            tmp -= arr[i];
            i++;
        }
        
        ll j = n-1, tmp2 = sum;
        while(tmp2%x==0){
            tmp2 -= arr[j];
            j--;
        }
        
        ll mn = max(n-i, j+1);
        
        cout<<mn<<endl;
    }
    
    return 0;
}
