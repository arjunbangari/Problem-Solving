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
        string s,t;
        cin>>s;
        cin>>t;
        ll ans = 0,flag = 0;
        map<char,vector<ll>> mp;
        ll sz=s.size();
        ll tz = t.size();
        for(ll i=0;i<sz;i++)
            mp[s[i]].push_back(i);
        
        for(ll i=0;i<tz;i++){
            if(mp.find(t[i])==mp.end()){
                flag = 1;
                break;
            }
        }
        
        if(flag)
            cout<<-1<<endl;
        else{
            ll last = -1;
            for(ll i=0;i<tz;i++){
                auto temp = upper_bound(mp[t[i]].begin(),mp[t[i]].end(),last);
    
                if(temp==mp[t[i]].end()){
                    ans++;
                    auto te = upper_bound(mp[t[i]].begin(),mp[t[i]].end(),-1);
                    last = *te;
                } else {
                    last = *temp;
                }
            }
            cout<<ans+1<<endl;
        }
    }
    
    return 0;
}