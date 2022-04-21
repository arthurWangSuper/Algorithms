class Solution:
    def frogPosition(self, n: int, edges: List[List[int]],
                     t: int, target: int) -> float:
        p = [0, 1] + [0]*(n-1)
        seen = [False, True] + [False] * (n-1)
        q = [1]
        # 创建 10个[] 单纯的执行 n+1次循环
        g = [[] for _ in range(n+1)]
        for i, j in edges:
            g[i].append(j)
            g[j].append(i)
        for _ in range(t):
            q2 = []
            for cur in q:
                children = sum([not seen[nxt] for nxt in g[cur]])
                for nxt in g[cur]:
                    if seen[nxt]: continue
                    seen[nxt] = True
                    q2.append(nxt)
                    p[nxt] = p[cur] / children
                if children > 0: p[cur] = 0
            q = q2
        return p[target]