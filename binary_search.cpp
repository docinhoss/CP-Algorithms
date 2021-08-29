#include <bits/stdc++.h>

using namespace std;

#define trav(a,x) for(auto& a : x)
#define sz(v) ((int)((v).size()))
#define all(x) (x).begin(), (x).end()
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

//Adjacency Matrix
bool adjMatrixBool[N][N];
int adjMatrix[N][N];

//Adjacency List
vector<vector<int>> adjList;
vector<int> color; vector<int> red; vector<int> blue;
vector<bool> visited;
vector<bool> isPrime;
vector<string> a;


//---------------------------------------------OTHER ALGO------------------------------------------------

//(ll *)m
void print_matrix(int *m, int r, int c){ for(ll i = 0; i < r; i++) for(ll j = 0; j < c; j++) cout << *((m+i*c)+j) << " \n"[j == c-1];}
vector<int> sieve(int n){int*arr = new int[n + 1]();vector<int> vect;for(int i = 2; i <= n; i++)if (arr[i] == 0){vect.push_back(i);for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}

//---------------------------------------------PROBLEM---------------------------------------------------

int p[] = {0, 5, 13, 19, 22, 41, 55, 68, 72, 81, 98};
int binary_search(int low, int high, int value){
	while(low < high){
		int mid = low + (high - low) / 2;
		if(p[mid] >= value){
			high = mid;
		}else{
			low = mid+1;
		}
	}
	
	if(p[low] < value) return -1;
	
	return low;
}


void solve(){
	
	
	return;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
	
	solve();
	
    return 0;
}
