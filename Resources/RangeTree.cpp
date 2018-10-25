typedef int Ptype;
typedef pair<Ptype, Ptype> Pt;
const Pt Pinf = Pt(numeric_limits<Ptype>::max(), numeric_limits<Ptype>::max());
class RangeTree {
public:
	int n;
	vector<Pt> xsorted;

	vector<vector<Pt> > dat;
	vector<vector<pair<int,int> > > bsearch_speedup;
	RangeTree(vector<Pt>& a) {
		n = 1;
		while (n < sz(a)) n <<= 1;
		dat.resize(2 * n - 1);

		//sort by first
		sort(a.begin(), a.end());
		xsorted = a;
		xsorted.resize(n, Pinf);
		bsearch_speedup.resize(n);

		rep(i, n) {
			int k = n - 1 + i;
			if (i < sz(a)) dat[k].push_back(a[i]);
			else dat[k].push_back(Pinf);
		}
		for (int i = n - 2; i >= 0; i--) {
			auto& cur_dat = dat[i], &lchild = dat[2 * i + 1], rchild = dat[2 * i + 2];
			cur_dat.resize(sz(lchild) + sz(rchild));
			//sort by second
			merge(lchild.begin(), lchild.end(), rchild.begin(), rchild.end(),
				cur_dat.begin(),
				[](const Pt& l, const Pt&  r) { return l.second != r.second ? l.second < r.second : l.first < r.first; }
			);
			//binary_search speed up with fractional cascading
			auto& bs = bsearch_speedup[i];
			bs.resize(sz(cur_dat));
			int a1 = 0, a2 = 0;
			rep(k, sz(cur_dat)) {
				while (a1 < sz(lchild) && lchild[a1].second < cur_dat[k].second) a1++;
				bs[k].first = a1;
				while (a2 < sz(rchild) && rchild[a2].second < cur_dat[k].second) a2++;
				bs[k].second = a2;
			}
			bs.emplace_back(sz(lchild), sz(rchild));
		}
	}
	// The number of verticies in [lx,rx) * [ly,ry) (O(log n))
	int query(Ptype lx, Ptype rx, Ptype ly, Ptype ry) {
#define CMP [](const Pt& l, const Ptype val) { return l.second < val; }
		int ly_index = lower_bound(dat[0].begin(), dat[0].end(), ly, CMP) - dat[0].begin();
		int ry_index = lower_bound(dat[0].begin(), dat[0].end(), ry, CMP) - dat[0].begin();
#undef  CMP
		return query(lx, rx, ly_index, ry_index, 0, 0, n);
	}
	int query(Ptype lx, Ptype rx, int ly_index, int ry_index, int k, int a, int b) {
		if (rx <= xsorted[a].first || xsorted[b - 1].first < lx) return 0;
		if (lx <= xsorted[a].first && xsorted[b - 1].first < rx) {
			return ry_index - ly_index;
		}

		int nly_idx_f, nly_idx_s, nry_idx_f, nry_idx_s;
		tie(nly_idx_f, nly_idx_s) = bsearch_speedup[k][ly_index];
		tie(nry_idx_f, nry_idx_s) = bsearch_speedup[k][ry_index];
		int lval = query(lx, rx, nly_idx_f, nry_idx_f, 2 * k + 1, a, (a + b) / 2);
		int rval = query(lx, rx, nly_idx_s, nry_idx_s, 2 * k + 2, (a + b) / 2, b);
		return lval + rval;
	}
};

void range_tree_test() {
  vector<Pt> vpt = { Pt(0, 0), 
    Pt(1, 0), Pt(2, 0), Pt(3, 0), Pt(0, 10), 
    Pt(0, 20), Pt(0, 30), Pt(5, 5), Pt(-3, -3)
  };

  RangeTree rt(vpt);
  assert(rt.query(0, 1, 0, 1) == 1);
  assert(rt.query(0, 4, 0, 4) == 4); 
  assert(rt.query(-10, 1, -10, 1) == 2); 
  assert(rt.query(-100, 100, -100, 100) == 9); 
} 
