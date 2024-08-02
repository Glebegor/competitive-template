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
using namespace std;

// Hlib Arseniuk Template
class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 1);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]); // Path compression
        }
        return parent[node];
    }
    
    bool unionSets(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        
        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1] += 1;
            }
            return true;
        }
        return false;
    }
};