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
        ll n,k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        
        sort(s.begin(), s.end());
        
        set<char> cnt;
        
        for(ll i=0;i<k;i++)
            cnt.insert(s[i]);
        
        ll sz = cnt.size();
        
        if(sz>1){
            cout<<s[k-1]<<endl;
        } else {
            string ans;
            ans.push_back(s[0]);
            
            cnt.clear();
            
            for(ll i=k;i<n;i++)
                cnt.insert(s[i]);
            
            sz = cnt.size();
            
            if(sz==1){
                ll i = k;
                for(ll i=k;i<n;i+=k)
                    ans.push_back(s[i]);
                if(i>n)
                    ans.push_back(s[k]);
            } else {
                for(ll i=k;i<n;i++)
                    ans.push_back(s[i]);
            }
            
            cout<<ans<<endl;
        }
    }
    
    return 0;
}