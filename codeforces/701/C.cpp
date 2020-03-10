#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    set<char> se;
    for(ll i=0;i<n;i++)
        se.insert(s[i]);
    ll sz = se.size();
    
    map<char,ll> mp;
    
    ll l=0,r=0, count=0, ans=n+1;
    
    while(l<n){
        while( r<n && count<sz ){
            if(mp[s[r]]==0)
                count++;
            mp[s[r]]++;
            r++;
        }
        if(r==n && count<sz)
            break;
        
        ans = min(ans,r-l);
        if(mp[s[l]]==1)
            count--;
        mp[s[l]]--;
        l++;
    }
    
    cout<<ans<<endl;
    return 0;
}