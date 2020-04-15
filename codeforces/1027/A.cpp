#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        string s;
        cin>>s;
        
        string ans = "YES";
        
        for(ll i=0;i<n/2;i++){
            if(abs(s[i]-s[n-i-1])==0 || abs(s[i]-s[n-i-1])==2)
                continue;
            else
                ans = "NO";
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}