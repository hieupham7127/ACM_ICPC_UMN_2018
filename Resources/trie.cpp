
int nextNode[200001][26];
int z = 1;
int add(string s)
{
  int node = 1;
  for (int i = 0; i < sz(s); i++)
  {
    int which = nextNode[node][s[i]-'a'];
    if (which == 0)
    {
      z++;
      nextNode[node][s[i]-'a'] = z;
      which = z;
    }
    node = which;
  }
  return 0;
}

