#include <bits/stdc++.h>
     
using namespace std;
     
#define trav(a,x) for(auto& a : x)
#define sz(v) ((int)((v).size()))
#define all(x) ((x).begin()), ((x).end())
#define srt(x) sort(all(x))
#define srtrev(x) sort(all(x)); reverse(all(x))
     
#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end())
     
#define MIN(s) *min_element(s.begin(), s.end()); //Min element in vector
#define MAX(s) *max_element(s.begin(), s.end()); //Max element in vector
#define ARR_MIN(s,n,o) *min_element(s, s+n+o); //Min element in array
#define ARR_MAX(s,n,o) *max_element(s, s+n+o); //Max element in array
     
#define FILL_2D(s,v) fill_n(&s[0][0], sizeof(s) / sizeof(**s), v);
     
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
     
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
     
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
     
     
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
     
     
     
//Initialize 2d vector = vector<vector<int>> a(size, vector<int>(size, value));
//vector<int> a(size, grid[0][0]);
     
// a % n = -2, -1, 0, 1, 2
// a % n (+ve) (a%n+n)%n (general)
     
//Convert um string de numeros para int -> s[i] - '0'
     
//__gcd(a,b) -> O(log2n)
     
const int MAX = 100;
const int N = 100;
     
ll arr[100001];
ll inf = 1e7;
     
     
//---------------------------------------------OTHER ALGO------------------------------------------------
     
//(ll *)m
void print_matrix(int *m, int r, int c){ for(ll i = 0; i < r; i++) for(ll j = 0; j < c; j++) cout << *((m+i*c)+j) << " \n"[j == c-1];}
vector<int> sieve(int n){int*arr = new int[n + 1]();vector<int> vect;for(int i = 2; i <= n; i++)if (arr[i] == 0){vect.push_back(i);for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
     
//---------------------------------------------PROBLEM---------------------------------------------------   	

vector<int> BFS(int s, vector<vector<int>> &adjList){
	vector<int> len(sz(adjList), 1e6);
	
	queue<pair<int,int>> q;
	
	q.push({s,0}), len[s] = 0;
	
	int cur, dep;
	while(!q.empty()){
		pair<int,int> p = q.front(); 
		q.pop();
		cur = p.first, dep = p.second;
		for(int i = 0; i < sz(adjList[cur]); i++){
			if(len[adjList[cur][i]] == 1e6){
				q.push({adjList[cur][i], dep+1});
				len[adjList[cur][i]] = dep+1;
			}
		}
	}
	
	return len;

}

vector<int> BFS2(int s, vector<vector<int>> &adjList){
	vector<int> len(sz(adjList), 1e6);
	queue<int> q;
	
	q.push(s);
	len[s] = 0;
	
	int q_sz = 1, cur = s, dep = 0;

	for(; !q.empty(); dep++, q_sz = q.size()){
		while(q_sz--){
			cur = q.front();
			q.pop();
			for(int i = 0; i < sz(adjList[cur]); i++){
				if(len[adjList[cur][i]] == 1e6){
					q.push(adjList[cur][i]);
					len[adjList[cur][i]] = dep+1;
				}
			}
		}
	}
	return len;
}

vector<int> BFSPath(int s, int d, vector<vector<int>> &adjList){
	vector<int> len(sz(adjList), 1e6);
	vector<int> par(sz(adjList), -1);
	queue<int> q;
	
	len[s] = 0;
	q.push(s);
	
	int cur = s, q_sz = 1, dep = 0;
	bool ok = true;
	
	for(; ok && !q.empty(); q_sz = q.size(), dep++){
		cur = q.front();
		q.pop();
		while(ok && q_sz--){
			for(int i = 0; i < sz(adjList[cur]); i++){
				if(len[adjList[cur][i]] == 1e6){
					q.push(adjList[cur][i]);
					len[adjList[cur][i]] = dep+1;
					par[adjList[cur][i]] = cur;
				}
				if(adjList[cur][i] == d){
					ok = false;
					break;
				}
			}
		}
	}
	
	vector<int> path;
	while(d != -1){
		path.push_back(d);
		d = par[d];
	}
	
	reverse(all(path));
	
	return path;
}

vector<int> BFSPath2(int s, int d, vector<vector<int>> &adjList){
	vector<int> len(sz(adjList), 1e6);
	vector<int> par(sz(adjList), -1);
	queue<pair<int,int>> q;
	
	q.push({s,0});
	len[s] = 0;
	
	int cur = s, dep = 0;
	bool ok = true;
	
	while(ok && !q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		cur = p.first, dep = p.second;
		for(int i = 0; ok && i < sz(adjList[cur]); i++){
			if(len[adjList[cur][i]] == 1e6){
				q.push({adjList[cur][i],dep+1});
				len[adjList[cur][i]] = dep+1;
				par[adjList[cur][i]] = cur;
			}
			if(adjList[cur][i] == d){
				ok = false;
				break;
			}
		}
	}
	
	vector<int> path;
	
	while(d != -1){
		path.push_back(d);
		d = par[d];
	}
	
	reverse(all(path));
	
	return path;
	
}

void solve(){
	
	int n, e; cin >> n >> e;
	vector<vector<int>> adjList(n);
	
	for(int i = 0; i < e; i++){
		int from, to; cin >> from >> to;
		adjList[from-1].push_back(to-1);
	}
	
	vector<int> res = BFS2(0, adjList);
	vector<int> path = BFSPath(0, 4, adjList);
	vector<int> path1 = BFSPath2(0, 4, adjList);
	
	debug(res);
	debug(path);
	debug(path1);
	
	return;
}
     
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
    	
	solve();
    	
	return 0;
}
