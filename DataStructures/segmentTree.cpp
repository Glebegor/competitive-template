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

// Geeksforgeeks Template
const int N = 100000;  
  
int n; // array size 
  
// Max size of tree 
int tree[2 * N]; 
  
// function to build the tree 
void build( int arr[])  
{  
    for (int i=0; i<n; i++)     
        tree[n+i] = arr[i]; 
    for (int i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] + tree[i<<1 | 1];     
} 
  
// function to update a tree node 
void updateTreeNode(int p, int value)  
{  
    tree[p+n] = value; 
    p = p+n; 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
} 
  
// function to get sum on interval [l, r) 
int query(int l, int r)  
{  
    int res = 0; 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res += tree[l++]; 
        if (r&1)  
            res += tree[--r]; 
    } 
    return res; 
} 
  
// driver program to test the above function  
int main()  
{ 
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
  
    // n is global 
    n = sizeof(a)/sizeof(a[0]); 
      
    // build tree  
    build(a); 
      
    // print the sum in range(1,2) index-based 
    cout << query(1, 3)<<endl; 
      
    // modify element at 2nd index 
    updateTreeNode(2, 1); 
      
    // print the sum in range(1,2) index-based 
    cout << query(1, 3)<<endl; 
  
    return 0; 
} 