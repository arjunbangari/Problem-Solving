#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n, score, maxscore = -1e9;
    string name, ans;
    cin>>n;

    map<string,ll> mp;
    map<string,ll> mp1;
    vector<pair<string,ll>> v;
    
    for(ll i=0;i<n;i++){
        cin>>name>>score;
        v.push_back({name,score});
        mp[name] += score;
    }
    
    for(auto i: mp)
        maxscore = max(maxscore, i.second);
    
    for(ll i=0;i<n;i++){
        string name1 = v[i].first;
        ll sc = v[i].second;
        mp1[name1] += sc;
        if(mp1[name1]>=maxscore && mp[name1]==maxscore){
            cout<<name1<<endl;
            return 0;
        }
    }
    
    return 0;
}