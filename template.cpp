#include <cstdio>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <complex>

// HLIB ARSENIUK
// TEMPLATE VERSION 2.9
// DESCRIPTION:
// Main template that I'm using in CP :>
// 2024 y.

// '*UUUUUwUUUUU*'
// 'q1-H-+-X---M-'
// 'q2-H-X-+--M|-'
// '----------||-'
// 'me--------==-'
/*
▄███████▀▀▀▀▀▀███████▄
░▐████▀▒ЗАПУСКАЕМ▒▀██████▄
░███▀▒▒▒▒▒ДЯДЮ▒▒▒▒▒▒▀█████
░▐██▒▒▒▒▒▒БОГДАНА▒▒▒▒▒████▌
░▐█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▌
░░█▒▄▀▀▀▀▀▄▒▒▄▀▀▀▀▀▄▒▐███▌
░░░▐░░░▄▄░░▌▐░░░▄▄░░▌▐███▌
░▄▀▌░░░▀▀░░▌▐░░░▀▀░░▌▒▀▒█▌
░▌▒▀▄░░░░▄▀▒▒▀▄░░░▄▀▒▒▄▀▒▌
░▀▄▐▒▀▀▀▀▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒█
░░░▀▌▒▄██▄▄▄▄████▄▒▒▒▒█▀
░░░░▄██████████████▒▒▐▌
░░░▀███▀▀████▀█████▀▒▌
░░░░░▌▒▒▒▄▒▒▒▄▒▒▒▒▒▒▐
░░░░░▌▒▒▒▒▀▀▀▒▒▒▒▒▒▒▐
TAYA 
*/ // by xoxo

// START OF THE TEMPLATE HELL

// Standard types
using ll = long long;
using ld = long double;
using l128 =  __int128_t;
using u32 = unsigned;
using u64 = unsigned long long;

// Complex nums
using Com =  std::complex<ll>;
#define ComX real()
#define ComY real()

// Some constants
#define INF 1e12 + 7
#define MOD7 1e9 + 7;
#define MOD9 1e12 + 9;
#define MAX 100000
#define MIN 0
#define EU exp(1.0)
const ld PI = acos((ld)-1);
const int maxNum = 111111111;

// Vectors
template<typename T>
using V = std::vector<T>;
typedef V<int> vi;
typedef V<V<int>> vii;
typedef V<std::string> vs;
typedef V<bool> vb;
typedef V<ll> vl;
typedef V<ld> vd;
typedef V<V<int>> vvi;
typedef V<V<ll>> vvl;

#define sz(x) int(size(x))
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

// Functions
template<typename T>
ll cdiv(T a, T b) {
    return a / b + ((a ^ b) > 0 && a % b);
}  // Divide a by b rounded up

template<typename T>
ll fdiv(T a, T b) {
    return a / b - ((a ^ b) < 0 && a % b);
}  // Divide a by b rounded down

template<typename T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}  // Set a = min(a, b)

template<typename T>
bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}  // Set a = max(a, b)

template<typename T>
void remDup(V<T> &v) {
    sort(v.begin(), v.end()); // Sort the elements of the vector
    v.erase(unique(v.begin(), v.end()), v.end()); // Remove duplicates
}

template<typename T>
T gdc_euclid(T a, T b) {
    while(b > 0) {
        ll temp = a/b;
        a -= temp*b;
        std::swap(a, b);
    }
    return a;
} // finds greate common div

template<typename T>
T lcd(T a, T b) {
    return a / gdc_euclid(a, b) * b;
} // finds least common denominator by gdc euclid

template<typename T>
T factorial(T a) {
    if(a == 0) {
        return 1;
    }
    return factorial(a-1) * a;
} // finds factorial

template<typename T>
std::vector<T> divisors(T n) {
    std::vector<T> res;
    for (T d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            res.pb(d);
            if (d * d != n) {
                res.pb(n / d);
            }
        }
    }
    sort(all(res));
    return res;
} // finds all divisiors

std::vector<bool> seive_count(int n) {
    std::vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
} // prime numbers

bool is_prime_number(int n) {
    if(n<2) {
        return false;
    }
    for(int x = 2; x*x <= n; x++) {
        if(n%x == 0) {
            return false;
        }
    }
    return true;
} // is_prime

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &pair) const {
        auto h1 = std::hash<T1>{}(pair.first);
        auto h2 = std::hash<T2>{}(pair.second);
        return h1 ^ h2;
    }
}; // pair hash

// Pairs
#define f first
#define s second
#define mkp make_pair
typedef std::pair<int, int> pii;

// Fors
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,b,a) for (int _n(b), i(a); i <= _n; i--)
#define REP(i,n) for (int i = 0; i < n; i++)
#define trav(a,x) for (auto &a : x)

// file output/input
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

using namespace std;

// ###$=-----------------+=:|| MAIN ||:=+-----------------=$### //

void solve() {
    
    return;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
