class UnionFind{
private:
	vector<int> rank;
	vector<int> pa;
public:
	// Construct
	UnionFind() {
	}
	// Ini
	UnionFind(vector<int> rank, vector<int> pa) {
		this->rank = rank;
		this->pa = pa;
		int size = (int)rank.size();
		for (int i=0; i<size; ++i) {
		    pa[i] = i;
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
	bool isConnected(int a, int b) {
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