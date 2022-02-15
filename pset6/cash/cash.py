from cs50 import get_float
change = 0
while change <= 0:
    change = get_float("Change owed: ")
cents = change * 100
q = 0
d = 0
n = 0
p = 0
while cents >= 25:
    cents -= 25
    q += 1
while cents >= 10:
    cents -= 10
    d += 1
while cents >= 5:
    cents -= 5
    n += 1
while cents >= 1:
    cents -= 1
    p += 1
coins = q + d + n + p
print(f"{coins}")