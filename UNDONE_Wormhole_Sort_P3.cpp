#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
//#define int long long
struct Edge{
    int one, two, three;
};

bool com(Edge a, Edge b){
    return a.three<b.three;
}
const int N = 1e5;
int n, m;
vector<int> order;
vector<Edge> wormholes;



vector<int> local;
void func(int index){


}

vector<int> visited(N+1);
vector<vector<int>> v;

void dfs(int index){
    visited[index] = 1;
    for(auto x:)
}
bool comp(int limit){
    //limit is wormholes we can use (before and including limit)

   local = order;
   v.clear(); visited.clear();

    //seeing which holes to which holes connected so making components
   for(int i=0; i<n; i++){
    if(visited[i]==0){dfs(i);}
   }

    for(int i=1; i<=n; i++){
        if(i!=local[i]){
            func(i);
        }
    }


    return is_sorted(local.begin(), local.end());
}
void test(){

    //ifstream cin("moocast.in");
	//ofstream cout("moocast.out");

    cin >> n >> m;
    order.pb(-1);
        for(int i=1; i<=n; i++){
            int num;
            cin >> num;
            order.pb(num);
        }

    for(int i=1; i<=n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        wormholes.pb({a, b, c});
    }

    sort(wormholes.begin(), wormholes.end(), com);

    //base case when array sorted

    if(is_sorted(order.begin(), order.end())==true){
        cout << -1 << endl;
        return;
    }

    //binary search

    int low = 0, high = m-1, ans = -1;
    while(low<=high){
        int mid = low + (high-low+1)/2;
        if(comp(mid)==true){
            ans = wormholes[mid].three;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

        cout << ans << endl;

    //-1 output is no need to sort 

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   //int t;
   //cin >> t;
    //while(t--)
    test();
}
