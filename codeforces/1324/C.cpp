#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll last=-1, ans = -1;
        ll n = s.length();
        for(ll i=0;i<n;i++){
            if(s[i]=='R'){
                ans = max(ans,i-last);
                last = i;
            }
        }
        
        ans = max(n-last,ans);
        cout<< ans<<endl;
        
    }
    return 0;
}