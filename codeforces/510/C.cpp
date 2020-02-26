#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll> v[26];
ll vis[26] = {0};
ll ans[26];
ll pos = 25, flag = 0;
ll color[26] = {0};

void dfs(ll i){
    vis[i] = 1;
    for(ll u: v[i]){
        if(!vis[u])
            dfs(u);
    }
    ans[pos] = i;
    pos--;
}

void cycle(ll i, ll p){
  color[i] = 1;
  for(ll w : v[i]){
    if(color[w] == 1){
      flag = 1;
    }
    if(color[w] == 0) cycle(w, i);
  }
  color[i] = 2;
}

int main(){
    fast;
    ll n;
    cin>>n;
    
    string arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    for(ll i=0;i<n-1;i++){
        ll j=0;
        while(arr[i][j]==arr[i+1][j])
            j++;
        if(j<arr[i].length() && j==arr[i+1].length()){
            flag = 1;
            break;
        }
        if(j<arr[i].length()){
            v[arr[i][j]-'a'].push_back(arr[i+1][j]-'a');
        }
    }
    
    if(flag)
        cout<<"Impossible"<<endl;
    else{
        for(int i = 0; i < 26; i++)
            if(color[i] == 0) 
                cycle(i, -1);
        
        if(flag)
            cout<<"Impossible"<<endl;
        else{
            for(ll i=0;i<26;i++)
                if(!vis[i])
                    dfs(i);
            for(ll i=0;i<26;i++)
                cout<<(char)('a'+ans[i]);
            cout<<endl;
        }
    }
    
    return 0;
}