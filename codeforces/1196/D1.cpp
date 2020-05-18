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
    
    ll q;
    cin>>q;
    
    while(q--){
    
        ll n,k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        
        vector<string> arr(3);
        arr[0] = "RGB";
        arr[1] = "GBR";
        arr[2] = "BRG";
        
        for(ll i=0;i<3;i++)
            for(ll j=0;j<n;j++)
                arr[i].push_back(arr[i][j%3]);
        
        ll l = 0, r = k-1, ans = inf;
        
        while(r<n){
            for(ll i=0;i<3;i++){
                ll cnt = 0;
                for(ll j=0;j<k;j++){
                    if(s[l+j]!=arr[i][j])
                        cnt++;
                }
                
                ans = min(ans, cnt);
            }
            l++;
            r++;
        }
        
        cout<<ans<<endl;
    
    }
    
    return 0;
}