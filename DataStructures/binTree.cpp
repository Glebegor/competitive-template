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

// USACO Template
template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	void set(int ind, T val) { add(ind, val - arr[ind]); }

	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};