#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
//#define int long long
//const int N = 1e5;

void dfs(int index, int comp, vector<vector<int>> &vec, vector<int> &components){
    for(auto x:vec[index]){
        if(components[x]!=comp){
            components[x] = comp;
            dfs(x, comp, vec, components);
        }
    }

}

void test(){
 

    //ifstream cin("moocast.in");
	//ofstream cout("moocast.out");
    
    int n, m;
    cin >> n >> m;

        vector<vector<int>> vec(n);

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            vec[a].pb(b);
            vec[b].pb(a);
        }

        vector<int> components(n);

    iota(components.begin(), components.end(), 0);

        //int ip = 1;
    for(int i=0; i<n; i++){
        if(components[i]==i){
            dfs(i, i, vec, components);
            //ip++;
        }
        //cout << components[i] << " ";
    }

    //cout << endl;

    if(components[0]==components[n-1]){
        cout << 0 << endl;
        return;
    }

    
    vector<vector<int>> orderedcomponents(n);

    for(int i=0; i<n; i++){
        orderedcomponents[components[i]].pb(i);
    }
    
    long long ans = 1e9;

    vector<long long> to1(n, 1e9);
    vector<long long> ton(n, 1e9);

    int track1 = 0, trackn = 0;

    for(int i=0; i<n; i++){
        while(track1 < orderedcomponents[components[0]].size()){
            to1[components[i]] = min(to1[components[i]], (long long)abs(i - orderedcomponents[components[0]][track1]));
            if(orderedcomponents[components[0]][track1] < i) track1++;
            else break;
        }
        if(track1) track1--;
        while(trackn < orderedcomponents[components[n-1]].size()){
            ton[components[i]] = min(ton[components[i]], (long long)abs(i - orderedcomponents[components[n-1]][trackn]));
            if(orderedcomponents[components[n-1]][trackn] < i) trackn++;
            else break;
        }
        if(trackn) trackn--;

    }

    for(int i=0; i<n; i++){
        ans = min(ans, (long long)(to1[i]*to1[i]+ton[i]*ton[i]));
        //cout << to1[i] << " " << ton[i] << endl;
    }

    cout << ans << endl;
 
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int t;
   cin >> t;
    while(t--)
    test();
}
