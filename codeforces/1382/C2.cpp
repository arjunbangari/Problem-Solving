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
        
        string a,b,c;
        cin>>a>>b;
        c = a;
        vector<ll> ans;
        
        ll r = n-1, l = 1, cur = 1;
        
        for(ll i=n-1;i>=0;i--){
            if(i==0){
                if(c[0]!=b[0]){
                    ans.push_back(0);
                    break;
                }
            }
            if(cur%2){
                c[i] = a[r];
                r--;
            } else {
                c[i] = (a[l]=='0' ? '1' : '0');
                l++;
            }
            if(b[i]==c[0]){
                ans.push_back(0);
            }
            ans.push_back(i);
            c[0] = (c[i]=='0' ? '1' : '0');
            cur = !cur;
        }
        
        ll k = ans.size();
        cout<<k<<" ";
        for(auto u: ans)
            cout<<u+1<<" ";
        cout<<endl;
    }
    
    return 0;
}