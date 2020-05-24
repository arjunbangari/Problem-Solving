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
        
        string arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        string ans("YES");
        
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(arr[i][j]=='1'){
                    ll flag = 2;
                    if((i+1)<n && arr[i+1][j]!='1')
                        flag--;
                    if((j+1)<n && arr[i][j+1]!='1')
                        flag--;
                    
                    if(!flag)
                        ans = "NO";
                }
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}