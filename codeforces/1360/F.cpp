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
        ll n,m;
        cin>>n>>m;
        
        vector<string> arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        string ans("-1");
        
        if(n==1)
            ans = arr[0];
        
        for(ll i=0;i<m;i++){
            set<char> can;
            ll flag = 0;
            
            for(ll j=1;j<n;j++){
                ll cnt = 0;
                for(ll k=0;k<m;k++){
                    if(k==i)
                        continue;
                    if(arr[j][k]!=arr[0][k])
                        cnt++;
                }
                
                if(cnt>=2){
                    flag = 1;
                    break;
                }
                if(cnt==1)
                    can.insert(arr[j][i]);
            }
            
            if(flag)
                continue;
            
            ll sz = can.size();
            if(sz>1)
                continue;
            if(sz==0)
                ans = arr[0];
            if(sz==1){
                arr[0][i] = *can.begin();
                ans = arr[0];
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}