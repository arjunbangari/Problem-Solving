#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
int main(){
    fast;
    string s;
    cin>>s;
    ll sz = s.length();
    ll pre[sz] = {0};
    ll suf[sz] = {0};
    
    pre[0] = (s[0]=='(');
    
    for(ll i=1;i<sz;i++)
        pre[i] = pre[i-1] + (s[i]=='(');
    
    suf[sz-1] = (s[sz-1]==')');
    for(ll i=sz-2;i>=0;i--)
        suf[i] = suf[i+1] + (s[i]==')');
    
    ll pos=-1;
    for(ll i=0;i<sz;i++){
        if(pre[i]>=suf[i]){
            pos = i;
            break;
        }
    }
    
    if(suf[pos]==0 || pos==-1)
        cout<<0<<endl;
    else{
        cout<<1<<endl;
        vector<ll> ans;
        for(ll i=0;i<=pos;i++)
            if(s[i]=='(')
                ans.push_back(i+1);
        for(ll i=pos;i<sz;i++)
            if(s[i]==')')
                ans.push_back(i+1);
        
        ll temp = (pre[pos]==suf[pos]);
        
        ll sa = ans.size();
        
        if(temp){
            cout<<sa<<endl;
            for(ll i=0;i<sa;i++)
                cout<<ans[i]<<" ";
        } else {
            cout<<sa-1<<endl;
            for(ll i=0;i<sa/2;i++)
                cout<<ans[i]<<" ";
            for(ll i=sa/2+1; i<sa;i++)
                cout<<ans[i]<<" ";
        }
    }
    
    return 0;
}
