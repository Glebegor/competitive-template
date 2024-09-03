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
using namespace std;

// Hlib Arseniuk Template
class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(int n) {
        this->n = n;
        tree.resize(2 * n, 0);
        for (int i = n; i < 2 * n; ++i) tree[i] = 1;
        for (int i = n - 1; i > 0; --i) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

public:
    SegmentTree(int n) {
        build(n);
    }

    // Update the segment tree at index idx (set it to 0)
    void update(int idx) {
        idx += n;
        tree[idx] = 0;
        for (idx /= 2; idx > 0; idx /= 2) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
        }
    }

    // Query to find the k-th available slot
    int query(int k) {
        int pos = 1;
        while (pos < n) {
            if (tree[2 * pos] >= k) {
                pos = 2 * pos;
            } else {
                k -= tree[2 * pos];
                pos = 2 * pos + 1;
            }
        }
        return pos - n;
    }
};


// int n;
// vi a;

// void solve() {
//     cin >> n;
//     a.rsz(n*2-1);
//     FOR(i, 0, n-1) {
//         cin >> a[i+n-1];
//     }
//     for(int i = n-2; i>=0; i--) {
//         a[i] = a[2*i+1] + a[2*i+2];
//     }

//     FOR(i, 0, a.size()-1) {
//         cout << a[i] << " ";
//     }
//     return;
// }



// struct segmentTree {
//     int size;
//     vl a;

//     void init(int n) {
//         size = 1;
//         while (size < n) size *= 2;
//         a.assign(2 * size, 0LL);
//     }

//     void set(int i, int v, int x, int lx, int rx) {
//         if (rx - lx == 1) {
//             a[x] = v;
//             return;
//         }
//         int m = (lx + rx) / 2;
//         if (i < m) {
//             set(i, v, 2 * x + 1, lx, m);
//         } else {
//             set(i, v, 2 * x + 2, m, rx);
//         }
//         a[x] = a[2 * x + 1] + a[2 * x + 2];
//     }

//     void set(int i, int v) {
//         set(i, v, 0, 0, size);
//     }

//     ll sum(int l, int r, int x, int lx, int rx) {
//         if (lx >= r || l >= rx) return 0;
//         if (lx >= l && rx <= r) return a[x];
//         int m = (lx + rx) / 2;
//         ll s1 = sum(l, r, 2 * x + 1, lx, m);
//         ll s2 = sum(l, r, 2 * x + 2, m, rx);
//         return s1 + s2;
//     }

//     ll sum(int l, int r) {
//         return sum(l, r, 0, 0, size);
//     }
// };

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     segmentTree sg;
//     sg.init(n);
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         sg.set(i, x);
//     }

//     while (m--) {
//         int op;
//         cin >> op;
//         if (op == 1) {
//             int i, v;
//             cin >> i >> v;
//             sg.set(i, v);
//         } else {
//             int l, r;
//             cin >> l >> r;
//             cout << sg.sum(l, r) << '\n';
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     solve();
//     return 0;
// }



// struct Segment {
//     long long total_sum;
//     long long prefix_sum;
//     long long suffix_sum;
//     long long max_sum;

//     Segment(long long total_sum = 0, long long prefix_sum = 0, long long suffix_sum = 0, long long max_sum = 0)
//         : total_sum(total_sum), prefix_sum(prefix_sum), suffix_sum(suffix_sum), max_sum(max_sum) {}
// };

// struct segTree {
//     int size;
//     vector<Segment> tree;

//     void init(int n) {
//         size = 1;
//         while (size < n) size *= 2;
//         tree.assign(2 * size, Segment());
//     }

//     Segment merge(Segment left, Segment right) {
//         Segment result;
//         result.total_sum = left.total_sum + right.total_sum;
//         result.prefix_sum = max(left.prefix_sum, left.total_sum + right.prefix_sum);
//         result.suffix_sum = max(right.suffix_sum, right.total_sum + left.suffix_sum);
//         result.max_sum = max({left.max_sum, right.max_sum, left.suffix_sum + right.prefix_sum});
//         return result;
//     }

//     void build(const vector<long long>& arr, int x, int lx, int rx) {
//         if (rx - lx == 1) {
//             if (lx < arr.size()) {
//                 tree[x] = Segment(arr[lx], max(0LL, arr[lx]), max(0LL, arr[lx]), max(0LL, arr[lx]));
//             }
//             return;
//         }
//         int mid = (lx + rx) / 2;
//         build(arr, 2 * x + 1, lx, mid);
//         build(arr, 2 * x + 2, mid, rx);
//         tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
//     }

//     void build(const vector<long long>& arr) {
//         build(arr, 0, 0, size);
//     }

//     void set(int i, long long v, int x, int lx, int rx) {
//         if (rx - lx == 1) {
//             tree[x] = Segment(v, max(0LL, v), max(0LL, v), max(0LL, v));
//             return;
//         }
//         int mid = (lx + rx) / 2;
//         if (i < mid) {
//             set(i, v, 2 * x + 1, lx, mid);
//         } else {
//             set(i, v, 2 * x + 2, mid, rx);
//         }
//         tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
//     }

//     void set(int i, long long v) {
//         set(i, v, 0, 0, size);
//     }

//     Segment max_sum_query() {
//         return tree[0];
//     }
// };


// struct segTree {
//     vl sums;
//     ll size;

//     void build(ll n) {
//         size = 1;
//         while (size < n) size *= 2;
//         sums.assign(size * 2, 0);
//     }

//     void set(ll i, ll v) {
//         i += size - 1;
//         sums[i] = v;
//         while (i > 0) {
//             i = (i - 1) / 2;
//             sums[i] = sums[2 * i + 1] + sums[2 * i + 2];
//         }
//     }
    