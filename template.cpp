#include <algorithm>
#include <iostream>
#include <memory.h>
#include <numeric>
#include <sstream>
#include <iterator>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <vector>
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

// HLIB ARSENIUK
// TEMPLATE VERSION 1.4
// DESCRIPTION:
// Main template that I'm using in CP by Hlib Arseniuk. :>
// 2024 y.

// '*UUUUUwUUUUU*'
// 'q1-H-+-X---M-'
// 'q2-H-X-+--M|-'
// '----------||-'
// 'me--------==-'

// START OF THE TEMPLATE HELL

// Standard types
using ll = long long;
using ld = long double;

// Some constants
#define INF 1e12 + 7
#define MOD 1000000009
#define MAX 100000
#define MIN 0
#define EU exp(1.0)
const ld PI = acos((ld)-1);

// Vectors
template<typename T>
using V = std::vector<T>;
typedef V<int> vi;
typedef V<std::string> vs;
typedef V<bool> vb;
typedef V<ll> vl;
typedef V<ld> vd;

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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &pair) const {
        auto h1 = std::hash<T1>{}(pair.first);
        auto h2 = std::hash<T2>{}(pair.second);
        return h1 ^ h2;
    }
};

// Pairs
#define f first
#define s second
#define mkp make_pair


using namespace std;

// Test cases solution

// void solve() {
// }

// int main() {
//     // freopen("task.in", "r", stdin);
// 	// freopen("task.out", "w", stdout);
    
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     while (t--) {
//         solve();
//     }

//     return 0;
// }


// Single cases solution

void solve() {
}

int main() {
    // freopen("task.in", "r", stdin);
	// freopen("task.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}