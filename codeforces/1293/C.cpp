#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll n;
bool valid(ll x,ll y){
    return (x>=1 && x<=2 && y>=1 && y<=n);
}

int main(){
    fast;
    ll q,r,c,count=0;
    cin>>n>>q;
    map<pair<ll,ll>,ll> us;
    while(q--){
        cin>>r>>c;
        string ans;
        auto temp = make_pair(r,c);
        if(us.find(temp)==us.end()){
            us[temp] = 1;
            if(r==1){
                if(valid(r+1,c) && us.find(make_pair(r+1,c))!=us.end())
                    count++;
                if(valid(r+1,c-1) && us.find(make_pair(r+1,c-1))!=us.end())
                    count++;
                if(valid(r+1,c+1) && us.find(make_pair(r+1,c+1))!=us.end())
                    count++;
            }
            else{
                if(valid(r-1,c) && us.find(make_pair(r-1,c))!=us.end())
                    count++;
                if(valid(r-1,c-1) && us.find(make_pair(r-1,c-1))!=us.end())
                    count++;
                if(valid(r-1,c+1) && us.find(make_pair(r-1,c+1))!=us.end())
                    count++;
            }
            ans = (count>0 ? "No":"Yes");
        }
        else{
            us.erase(make_pair(r,c));
            if(r==1){
                if(valid(r+1,c) && us.find(make_pair(r+1,c))!=us.end())
                    count--;
                if(valid(r+1,c-1) && us.find(make_pair(r+1,c-1))!=us.end())
                    count--;
                if(valid(r+1,c+1) && us.find(make_pair(r+1,c+1))!=us.end())
                    count--;
            }
            else{
                if(valid(r-1,c) && us.find(make_pair(r-1,c))!=us.end())
                    count--;
                if(valid(r-1,c-1) && us.find(make_pair(r-1,c-1))!=us.end())
                    count--;
                if(valid(r-1,c+1) && us.find(make_pair(r-1,c+1))!=us.end())
                    count--;
            }
            ans = (count>0 ? "No":"Yes");
        }
        cout<<ans<<endl;
    }
    return 0;
}