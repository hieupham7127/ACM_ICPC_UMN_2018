vector< pair<int,int> > calipers(const vector<PT>& v) {
  vector<pair<int,int> > ret;
  if (sz(v) == 2)  {
    ret.pb(mp(0, 1));
  } else if (sz(v) >= 3) {
    int i = 0, j = 0, ii, jj, si, sj;
    rep(k,sz(v)) {
      if (mp(v[k].x, v[k].y) >= mp(v[i].x, v[i].y)) i = k;
      if (mp(v[k].x, v[k].y) <  mp(v[j].x, v[j].y)) j = k;
    }
    for (si = i, sj = j; i != sj || j != si;) {
      ret.pb(mp(i, j));
      ii = (i + 1) % sz(v); jj = (j + 1) % sz(v); 
      if (cross(v[ii] - v[i], v[jj] - v[j]) < 0)  {
        i = ii;
      } else {
        j = jj;
      }
    }
  }
  return ret;
}
