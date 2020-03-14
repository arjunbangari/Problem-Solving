#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define loop for(int i=0;i<n;++i)
#define loopitr(s) for(auto it=(s).begin();it!=(s).end();++it)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll l = n;
    while(1){
        ll pos = -1;
        char c = 'a';
        
        if(l>1 && s[1]==(s[0]-1)){
            pos = 0;
            c = s[0];
        }
        
        for(ll i=1;i<l-1;i++){
            if(s[i-1]==(s[i]-1) || s[i+1]==(s[i]-1)){
                if(s[i]>c){
                    pos = i;
                    c = s[i];
                }
            }
        }
        
        if(l>1 && s[l-2]==(s[l-1]-1)){
            if(s[l-1]>c){
                pos = l-1;
                c = s[l-1];
            }
        }
        
        if(pos==-1)
            break;
        else{
            s.erase(pos,1);
            l--;
        }
    }
    
    cout<<n-l<<endl;
    
    return 0;
}