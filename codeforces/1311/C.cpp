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
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        ll val;
        ll ans[n+1] = {0};
        for(ll i=0;i<m;i++){
            cin>>val;
            ans[0]++;
            ans[val]--;
        }
        for(ll i=1;i<=n;i++)
            ans[i]+=ans[i-1];
        
        // for(ll i=0;i<n;i++)
        //     cout<<ans[i]<<" ";
        // cout<<endl;
        
        map<char,ll> mp;
        
        for(ll i=0;i<n;i++){
            mp[s[i]]+=(ans[i]+1);
            //cout<<s[i]<<" "<<mp[s[i]]<<" "<<ans[i]<<endl;
        }
        
        string alpha("abcdefghijklmnopqrstuvwxyz");
        for(ll i=0;i<26;i++){
            cout<<mp[alpha[i]]<<" ";
        }

        cout<<endl;
        
    }
    return 0;
}