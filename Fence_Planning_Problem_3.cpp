#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
//#define int long long
int n, m;
const int N = 2*1e5;
vector<int> networks[N+1];
vector<pair<int, int>> vec(N+1);
bool visited[N+1];

int minx = 1e9, maxx = -1e9, miny = 1e9, maxy = -1e9;

void dfs(int index){
    //check min, max
    //cout << "VEC" << vec[index].ff << " " << vec[index].ss << endl;

    minx = min(minx, vec[index].ff);
    maxx = max(maxx, vec[index].ff);
    miny = min(miny, vec[index].ss);
    maxy = max(maxy, vec[index].ss);
        //cout << minx << " " << maxx << " " << miny << " " << maxy << endl;
    for(auto x:networks[index]){
        if(visited[x]==0){
            visited[x] = 1;
            dfs(x);
        }
    }
    return;
}

void test(){

    ifstream cin("fenceplan.in");
	ofstream cout("fenceplan.out");

    cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> vec[i].ff >> vec[i].ss;


    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        networks[a].pb(b); networks[b].pb(a);
    }
    
    int ans = 1e9;

    for(int i=1; i<=n; i++){
        minx = 1e9; maxx = -1e9; miny = 1e9; maxy = -1e9;
        if(visited[i]==0){
        visited[i] = 1;
        //cout << "YHEE" << endl;
            dfs(i);
        }
        //cout << minx << " " << maxx << " " << miny << " " << maxy << endl;
        int perimeter = 2*(maxx-minx+maxy-miny); //check if this is correct
        //cout << "PPPPP" << perimeter << endl;
        ans = min(ans, perimeter);
    }
        cout << ans << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   //int t;
   //cin >> t;
    //while(t--)
    test();
}
