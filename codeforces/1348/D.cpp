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
        ll n;
        cin>>n;
        
        vector<ll> ans;
        ans.push_back(1);
        ll sum = 1;
        ll power = 1;
        
        while(1){
            power *= 2;
            sum += power;
            if(sum>n)
                break;
            ans.push_back(power);
        }
        sum -= power;
        
        if(sum<n)
            ans.push_back(n-sum);
        
        sort(ans.begin(), ans.end());
        
        ll sz = ans.size();
        cout<<sz-1<<endl;
        
        for(ll i=1;i<sz;i++)
            cout<<ans[i]-ans[i-1]<<" ";
        cout<<endl;
    }
    
    return 0;
}