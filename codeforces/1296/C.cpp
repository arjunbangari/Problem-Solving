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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<pair<ll,ll>,ll> mp;
        ll sz=s.length();
        ll x=0,y=0;
        ll ansi=-1,anse=1e8;
        
        mp[make_pair(0,0)]=-1;
        for(ll i=0;i<sz;i++){
            if(s[i]=='L')
                x--;
            else if(s[i]=='R')
                x++;
            else if(s[i]=='U')
                y++;
            else
                y--;
            if(mp.find(make_pair(x,y))!=mp.end()){
                if((anse-ansi)>(i-mp[{x,y}])){
                    ansi = mp[{x,y}]+1;
                    anse = i;
                }
            }
            mp[{x,y}] = i;
        }
            if(ansi==-1 && anse==1e8)
                cout<<-1<<endl;
            else
                cout<<ansi+1<<" "<<anse+1<<endl;
    }

    return 0;
}