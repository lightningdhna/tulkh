import random

from matplotlib import pyplot as plt

n = 12
k = 3
cor = []

for i in range(n+1):
    x = random.randrange(-10,10);
    y = random.randrange(-10,10);
    cor.append([x,y])

plt.plot(cor)
plt.show()
