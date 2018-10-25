const int MAX_N = 100100;
const int bsize = 1000;
int A[MAX_N + 1];
vector<int> B[MAX_N / bsize + 1];

// kind of tested
// check the interval [from, to)
void f(int from, int to)
{
  for (int ub = min((from/bsize+1)*bsize,to);
      from < ub; from++)
  {
    // do something at from
  }
  for (int lb = max((to/bsize)*bsize,from);
      lb < to;)
  {
    to--;
    // do something at to
  }
  for (int fromb = from/bsize, tob = to/bsize;
    fromb < tob; fromb++)
  {
    // do something at fromb
  }
}
