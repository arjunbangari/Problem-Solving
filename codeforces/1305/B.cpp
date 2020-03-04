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
    vector<ll> ans;
    
    ll l=0,r=sz-1;
    
    while(l<sz && l<r){
        if(s[l]=='('){
            while(r>l){
                if(s[r]==')')
                    break;
                r--;
            }
            if(r>l){
                ans.push_back(l+1);
                ans.push_back(r+1);
            }
            r--;
        } 
        l++;
    }
    
    ll p = ans.size();
    if(p==0){
        cout<<0<<endl;
    } else {
        cout<<1<<endl;
        cout<<p<<endl;
        sort(ans.begin(),ans.end());
        for(ll i=0;i<p;i++)
            cout<<ans[i]<<" ";
    }
    
    return 0;
}