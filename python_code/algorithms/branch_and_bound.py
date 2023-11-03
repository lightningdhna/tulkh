import sys
import math

class Node:
    def __init__(self, postman, id, path_len):
        self.postman = postman
        self.id = id
        self.path_len = path_len

def search(postman, id, nodes, cur, vis, best_value, best_ans):
    # update best answer
    if postman > k:
        max_len = 0
        for i in range(k):
            max_len = max(max_len, path_len[i])
        if max_len < best_value:
            best_value = max_len
            for i in range(k):
                best_ans[i] = cur[i]
        return

    rq_left = 0
    for i in range(1, n + 1):
        if vis[i]:
            continue
        rq_left += 1

        # check bound condition
        if path_len[postman] + d[cur[postman][id - 1]][i] > best_value:
            return

        # branch continue to go to rq i
        cur[postman].append(i)
        vis[i] = True
        path_len[postman] += d[cur[postman][id - 1]][i]

        nodes.append(Node(postman, id + 1, path_len))
        search(postman, id + 1, nodes, cur, vis, best_value, best_ans)

        path_len[postman] -= d[cur[postman][id - 1]][i]
        vis[i] = False
        cur[postman].pop()

    # branch and bound go to next postman
    if not rq_left:
        # branch
        search(postman + 1, 1, nodes, cur, vis, best_value, best_ans)
        return

    if postman < k - 1:
        # bound check
        if math.ceil(dsum[rq_left - 1] * 1.0 / (k - postman - 1)) > best_value:
            return

        # branch
        search(postman + 1, 1, nodes, cur, vis, best_value, best_ans)


if __name__ == "__main__":
    input = sys.stdin.readline
    n, k = map(int, input().split())

    d = [[0] * (n + 1) for _ in range(n + 1)]
    dsum = []
    path_len = [0] * k

    for i in range(n + 1):
        d[i] = [int(x) for x in input().split()]
        for j in range(n + 1):
            if i ^ j:
                dsum.append(d[i][j])
    dsum.sort()
    for i in range(1, len(dsum)):
        dsum[i] += dsum[i - 1]

    cur = [[0] for _ in range(k)]
    vis = [False] * (n + 1)
    best_value = 1e9
    best_ans = [[0] for _ in range(k)]

    nodes = []
    search(0, 1, nodes, cur, vis, best_value, best_ans)

    print(k)
    for i in range(k):
        print(len(best_ans[i]))
        print(*best_ans[i])
