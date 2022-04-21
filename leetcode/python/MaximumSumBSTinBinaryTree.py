def Solution:
    def maxSumBST(self, root)->int:
        # return {lo, hi, sum, valid}
        def dfs(node):
            if not node:return(1e9, -1e9, 0, True)
            ll, lh, ls, lv = dfs(node.left)
            rl, rh, rs, rv = dfs(node.right)
            v = lv and rv and node.val > lh and node.val < rl
            s = ls + rs + node.val if v else -1 # 三元运算符
            self.ans = max(self.ans, s)
            return (min(ll, node.val), max(rh, node.val), s, v)
        self,ans = 0
        dfs(root)
        return self.ans