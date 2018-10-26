import sys
a, b, MOD = 1, 0, 65521
for s in sys.stdin:
  for x in ''.join(s.split()):
    a = (a + ord(x)) % MOD
    b = (b + a) % MOD
h = (b << 16) | a
print h, format(h, '#x')
