#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    string s;
    cin>>s;
    
    vector<ll> v[n];
    
    for(ll i=0;i<n-1;i++){
        if(s[i]=='1'){
            v[i].push_back(i+1);
            v[i+1].push_back(i);
        }
    }
    
    ll vis[n] = {0};
    
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            
            vector<ll> indices;
            vector<ll> values;
            queue<ll> q;
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty()){
                ll val = q.front();
                q.pop();
                indices.push_back(val);
                values.push_back(arr[val]);
                for(ll u: v[val]){
                    if(!vis[u]){
                        q.push(u);
                        vis[u] = 1;
                    }
                }
            }
            
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());
            
            ll sz=indices.size();
            
            for(ll j=0;j<sz;j++)
                arr[indices[j]] = values[j];

        }
    }
    
    ll flag=0;
    for(ll i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            flag = 1;
            break;
        }
    }
    
    cout<< ( flag ? "NO" : "YES" ) <<endl;

    return 0;
}