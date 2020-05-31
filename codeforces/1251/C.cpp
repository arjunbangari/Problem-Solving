#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        ll n;
        n = s.length();
        
        vector<ll> even, odd, ans;
        
        for(ll i=0;i<n;i++){
            ll val = s[i]-'0';
            if(val%2)
                odd.push_back(val);
            else
                even.push_back(val);
        }
        
        ll sz1 = even.size(), sz2 = odd.size();
        ll l = 0, r = 0;
        
        while(l<sz1 && r<sz2){
            if(even[l]<odd[r]){
                ans.push_back(even[l]);
                l++;
            } else {
                ans.push_back(odd[r]);
                r++;
            }
        }
        
        if(l==sz1){
            while(r<sz2){
                ans.push_back(odd[r]);
                r++;
            }
        }
        
        if(r==sz2){
            while(l<sz1){
                ans.push_back(even[l]);
                l++;
            }
        }
        
        for(auto u: ans)
            cout<<u;
        cout<<endl;    
    }
    
    return 0;
}