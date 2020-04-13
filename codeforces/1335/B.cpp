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
        ll n,a,b;
        cin>>n>>a>>b;
        
        string s;
        ll i;
        for(i=0;i<b;i++)
            s.push_back('a'+i);
        
        for(;i<a;i++)
            s.push_back(s[i-b]);
        
        for(;i<n;i++)
            s.push_back(s[i-a]);
        
        cout<<s<<endl;
    }
    
    return 0;
}