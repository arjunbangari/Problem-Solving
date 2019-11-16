#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){   
    fast;
    int q;
    cin>>q;
    while(q--){
        ll n,flag=0,bad=0,ans;
        string s;
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>s;
            ll l = s.length();
            if(l%2!=0)
                flag = 1;
            else{
                ll one = count(s.begin(),s.end(),'1');
                if(one%2!=0)
                    bad++;
            }
        }
        
        if(bad%2==0)
            ans = n;
        else if(flag==1)
            ans = n;
        else
            ans = n-1;
        cout<<ans<<"\n";
            
    }
    return 0;
}
