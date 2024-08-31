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