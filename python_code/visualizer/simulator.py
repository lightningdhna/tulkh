import math
import random
import numpy

from matplotlib import pyplot as plt


def generate_cords(vertices_num: int, file_name: str = "../data/coordinate.txt"):
    cords = []
    for _ in range(vertices_num + 1):
        x = random.randrange(-10, 10)
        y = random.randrange(-10, 10)
        cords.append([x, y])
    data = numpy.array(cords)
    x, y = data.T
    with open(file_name, "w") as file:
        file.write(str(vertices_num) + '\n')
        for cord in cords:
            file.write(str(cord[0]) + ' ' + str(cord[1]) + '\n')
    plt.scatter(x, y)
    plt.show()
    return cords


def get_cords(file_name: str = "../data/coordinate.txt"):
    n = 0
    cords = []
    with open(file_name, "r") as f:
        n = int(f.readline())
        for i in range(n + 1):
            [x, y] = [int(x) for x in f.readline().split(' ')]
            cords.append([x, y])

    data = numpy.array(cords)
    x, y = data.T
    plt.scatter(x, y)
    plt.show()

    return cords
    pass


def generate_input(n: int, k: int, file_name: str = "../data/input.txt"):
    cords = generate_cords(n)
    dis = [[0] * (n + 1)] * (n + 1)

    def distance(x, y):
        return round(math.sqrt(
            (x[0] - y[0]) * (x[0] - y[0]) +
            (x[1] - y[1]) * (x[1] - y[1])
        ))

    # for i in range(n+1):
    #     for j in range(n+1):
    #         dis[i][j] = distance(cords[i],cords[j])
    with open(file_name, "w") as file:
        file.write(str(n) + ' ' + str(k) + '\n')
        for i in range(n + 1):
            for j in range(n + 1):
                file.write(str(distance(cords[i], cords[j])) + ' ')
            file.write('\n')


def show_output(file_name="../data/output.txt"):
    cords = get_cords()
    paths = []
    with open(file_name) as file:
        k = int(file.readline())
        for _ in range(k):
            sz = int(file.readline())
            path = [int(x) for x in file.readline().split(' ')]
            paths.append(path)
            pass

    def show_path(idx: int):
        data = numpy.array([cords[i] for i in paths[idx]])
        plt.plot(data[:, 0], data[:, 1])

    for i in range(k):
        show_path(i)

    data = numpy.array(cords)
    x, y = data.T
    plt.scatter(x, y)
    plt.show()


if __name__ == "__main__":
    # generate_input(12,4)
    show_output()
    pass
