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

bool isSubSequence(string str1, string str2) {
    ll m = str1.length();
    ll n = str2.length();
    ll j = 0;
    for (ll i=0; i<n&&j<m; i++) 
        if (str1[j] == str2[i]) 
            j++; 
      
    return (j==m); 
} 

int main(){
    fast;
    
    string t, p;
    cin>>t>>p;
    
    ll n = t.length();
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll l = 0, r = n, ans=0;
    
    while(l<=r){
        string s = t;
        ll mid = (l+r)/2;
        
        for(ll i=0;i<mid;i++)
            s[arr[i]-1] = '#';
        
        if(isSubSequence(p, s)){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid-1;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}