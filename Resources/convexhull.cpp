double area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }
int mycomp(PT p, PT q) { return mp(p.y,p.x) < mp(q.y,q.x); }
void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end(), mycomp);
  vector<PT> up, dn;
  rep(i,sz(pts)) {
    while (sz(up) > 1 && area2(up[sz(up)-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (sz(dn) > 1 && area2(dn[sz(dn)-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.pb(pts[i]); dn.pb(pts[i]);
  }
  pts = dn;
  rep1(i,sz(up)-2) pts.pb(up[sz(up)-i-1]);
}

