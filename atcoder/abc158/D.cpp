#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    string s;
    cin>>s;
    ll q;
    cin>>q;
    
    ll l =s.length(), rev = 0;
    
    deque<char> dq;
    for(ll i=0;i<l;i++)
        dq.push_back(s[i]);
    
    while(q--){
        ll t,f;
        char c;
        
        cin>>t;
        if(t==1)
            rev = rev^1;
        else{
            cin>>f>>c;
            if(f==1){
                if(rev==0)
                    dq.push_front(c);
                else
                    dq.push_back(c);
            } else {
                if(rev==0)
                    dq.push_back(c);
                else
                    dq.push_front(c);
            }
        }
    }
    
    string ans;
    ll p = dq.size();
    
    if(rev==0){
        for(ll i=0;i<p;i++){
            char val = dq.front();
            ans += val;
            dq.pop_front();
        }
    } else {
        for(ll i=0;i<p;i++){
            char val = dq.back();
            ans += val;
            dq.pop_back();
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}