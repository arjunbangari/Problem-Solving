#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;

    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        
        vector<ll> ind;
        for(ll i=0;i<n;i++){
            if(s[i]=='1')
                ind.push_back(i);
        }
        
        ll cnt = 0, last = -inf;

        
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){
                auto it = upper_bound(ind.begin(), ind.end(), i);
                
                ll flag = 1;
                
                if(it!=ind.end() && (*it-i)<=k)
                    flag = 0;
                
                if((i-last)<=k)
                    flag = 0;
                    
                if(flag){
                    cnt++;
                    last = i;
                }
            } else {
                last = i;
            }
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}
