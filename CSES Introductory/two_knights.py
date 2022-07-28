n = input()
n = int(n)
def knights(k) :
    m = k*k
    return m*(m-1)/2 - 4*(k-1)*(k-2)

for i in range(1, n+1):
    print(int(knights(i)))