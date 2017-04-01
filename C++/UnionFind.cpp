class UnionFind{
public:
	vector<int> rank;
	vector<int> pa;
	// Ini
	UnionFind(int n) {
		for (int i = 0; i < n; ++i) {
			rank.push_back(1);
			pa.push_back(i);
		}
	}
	// Find the root
	int root(int i) {
		while (i != pa[i]) {
			pa[i] = pa[pa[i]];
			i = pa[i];
		}
		return i;
	}
	// Judge the connectivity
	bool isConnected(int x, int y) {
		return root(x) == root(y);
	}
	// Unite the sets
	void unionSet(int x, int y) {
		x = root(x);
		y = root(y);
		if (rank[x] > rank[y]) {
			pa[y] = x;
		} else {
			pa[x] = y;
			if (rank[x] == rank[y]) ++rank[y];
		}
	}
};