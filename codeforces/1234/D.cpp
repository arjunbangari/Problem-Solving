#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    string s;
    cin>>s;
    
    set<ll> v[26];
    
    ll lt = s.length();
    for(ll i=0;i<lt;i++)
        v[s[i]-'a'].insert(i);
    
    ll q,pos,l,r;
    char c;
    cin>>q;
    
    while(q--){
        ll type;
        cin>>type;
        
        if(type==1){
            cin>>pos>>c;
            pos--;
            v[s[pos]-'a'].erase(pos);
            v[c-'a'].insert(pos);
            s[pos] = c;
        } else {
            cin>>l>>r;
            l--;
            r--;
            ll ans = 0; 
            for(ll i=0;i<26;i++){
                auto it = v[i].upper_bound(l-1);
                if(it!=v[i].end()){
                    ll val = *it;
                    if(val<=r)
                        ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}