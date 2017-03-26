//============================================================================
// Name        : 
// Author      : Atul Kumar Gupta
// Description : 
// Status	   : AC
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define sz(c)  (int) c.size()
#define all(c) c.begin(), c.end()
#define tr(container,it) for(__typeof(container.begin()) it = container.begin();it != container.end(); it++)
#define present(s,x) s.find(x) != s.end()
#define cpresent(c,x) find(all(c),x) != c.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,n) for(int i=0;i<n;i++)
#define dep(i,n) for(int i=n-1;i>=0;i--)
#define repn(i,a,b) for(int i=a; i<b;i++)
#define ini(n) scanf("%d",&n)
#define ind(n,m) scanf("%d %d",&n,&m);
#define ins(n) scanf("%s",n);
#define opi(n) printf("%d",n)
#define ops(n) printf("%s",n)
#define opn printf("\n")
#define opsp printf(" ");
#define opa(n) cout<<n
 
#define TRACE
 
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
 
#else
 
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)    
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif 

typedef pair<int,int> pi;
typedef vector<pi> vp;
typedef vector<vp> vvp;
typedef vector<int> vi;
typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector< vi > vvi;
typedef priority_queue<int> pq;
typedef priority_queue<int, vi , greater<int> >minpq;
typedef priority_queue<pi,vp,greater<pi> > mpq;

//Euclidean GCD
//------------------------------------------
//============================================================================
int gcd(int A, int B) {
    if(B==0)
        return A;
    else
        return gcd(B, A % B);
}
//Fermat MMI
//------------------------------------------
//============================================================================
//a^n % m
ll mod_exponentiation(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int fermat(ll n, ll m){
	return mod_exponentiation(n,m-2,m);
}

struct node{
	int a;
	int cnt;
};
//custom comparator
struct Compare{
	bool operator()(node &a, node &b){
		return a.cnt > b.cnt ;
	}
};

//conversion
//============================================================================
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
//============================================================================
template<class T> inline T sqr(T x) {return x*x;}


//Main Starts
//------------------------------------------
//============================================================================
int dr[] = {0 , -1 , 1 , 0 , -1 , 1 , -1 , 1 };
int dc[] = {1, 1 , 1 , -1 , -1 , -1 , 0 , 0 };

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	ifstream infile("test.c");
	char ch;
	while((ch = infile.get())!=EOF){
		while((ch = infile.get()) != '\n'){
			cout<<ch;
		}
		break;
	}
	
}

	

	

