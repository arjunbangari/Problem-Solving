#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
int n;
vector<string> arr;
vector<int> v[200100];
int vis[200100];

void dfs(int i){
    vis[i] = true;
    for(int u: v[i]){
        if(i>=n)
            dfs(u);
        else if(!vis[u])
            dfs(u);
    }
}

int main(){
    memset(vis,0,sizeof(vis));
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        arr.push_back(s);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<arr[i].size();j++){
            int temp = int(arr[i][j]) - int('a');
            v[i].push_back(n+temp);
            v[n+temp].push_back(i);
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}