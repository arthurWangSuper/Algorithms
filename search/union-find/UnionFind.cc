// Pseudo code
/*
class UnionFindSet:
    func UnionFindSet(n):
        parents = [1..n]
        ranks = [0..0](n zeros)
    func Find(x):
        if x != parents[x]:
            parents[x] = Find(parents[x])
        return parents[x]
    func Union(x,y):
        px,py = Find(x),Find(y);
        if ranks[px] > ranks[py]: parents[py] = px
        if ranks[px] < ranks[py]: parents[px] = py
        if ranks[px] == ranks[py]: 
            parents[py] = px
            ranks[px] ++
*/