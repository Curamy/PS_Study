h, m = map(int, input().split())
time = int(input())

plus_hour = time // 60
plus_min = time % 60

if m + plus_min >= 60:
  m = (m + plus_min) % 60
  plus_hour += 1
else:
  m += plus_min

if h + plus_hour >= 24:
  h = (h + plus_hour) % 24
else:
  h += plus_hour

print(h, m)