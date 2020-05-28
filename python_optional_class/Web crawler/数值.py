def iter(x1, x2, x3):
    x1 = 0.2 * x2 + 0.1 * x3 + 0.3
    x2 = 0.2 * x1 + 0.1 * x3 + 1.5
    x3 = 0.2 * x1 + 0.4 * x2 + 2
    return x1, x2, x3


x12 = x22 = x32 = 0


for i in range(1,7):
    x12, x22, x32 = iter(x12, x22, x32)
    print(i, x12, x22, x32)

