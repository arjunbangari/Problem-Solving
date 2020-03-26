#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,d,h;
    cin>>n>>d>>h;
    
    if(d>2*h || d<h)
        cout<<-1<<endl;
    else if(d==1 && n>2){
        cout<<-1<<endl;
    }
    else{
        ll l=1, r=2, cnt=0;
        while(cnt<h){
            cout<<l<<" "<<r<<endl;
            l++;
            r++;
            cnt++;
        }
        
        ll rem = (d-h);
        l=1, cnt=0;
        while(cnt<rem){
            cout<<l<<" "<<r<<endl;
            l = r;
            r++;
            cnt++;
        }
        
        rem = n - 1 - d;
        ll temp=1;
        if(d==h)
            temp=2;
        while(rem--){
            cout<<temp<<" "<<r<<endl;
            r++;
        }
    }
    
    return 0;
}