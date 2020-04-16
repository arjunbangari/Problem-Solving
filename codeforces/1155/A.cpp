#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    string ans("NO");
    ll l,r;
    
    for(ll i=1;i<n;i++){
        if(s[i]<s[i-1]){
            ans = "YES";
            l = i-1;
            r = i;
            break;
        }
    }
    
    cout<<ans<<endl;
    if(ans=="YES")
        cout<<l+1<<" "<<r+1<<endl;
    
    return 0;
}