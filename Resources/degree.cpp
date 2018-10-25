// returns [0, 360)
double EPS = 1e-9; 
struct point { int x, y; };
double mydeg(point p)
{
  double x = p.x;
  double y = p.y;
  double a = asin(y / sqrt(x * x + y * y)) * 180 / pi;
  double ret = 0;
  if (x >= 0 && y >= 0) ret = a;
  if (x <= 0 && y >= 0) ret = 180 - a;
  if (x >= 0 && y <= 0) ret = 360 + a;
  if (x <= 0 && y <= 0) ret = 180 + abs(a);
  while (ret >= 360) ret -= 360;
  return ret;
}
