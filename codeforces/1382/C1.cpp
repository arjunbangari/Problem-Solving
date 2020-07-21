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
        
        string a,b;
        cin>>a>>b;
        
        vector<ll> ans;
        
        for(ll i=n-1;i>=0;i--){
            if(a[i]!=b[i]){
                if(i==0){
                    ans.push_back(0);
                    break;
                }
                if(a[i]!=a[0]){
                    ans.push_back(0);
                    a[0] = (a[0]=='0' ? '1' : '0');
                    ans.push_back(i);
                } else {
                    ans.push_back(i);
                }
                
                for(ll j=0;j<=i;j++)
                    a[j] = (a[j]=='0' ? '1' : '0');
                reverse(a.begin(), a.begin()+i+1);
            }
        }
        
        ll k = ans.size();
        cout<<k<<" ";
        for(auto u: ans)
            cout<<u+1<<" ";
        cout<<endl;
    }
    
    return 0;
}