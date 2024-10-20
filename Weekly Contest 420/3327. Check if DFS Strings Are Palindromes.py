lass Solution:


    def findAnswer(self, parent: list[int], s: str) -> list[bool]:
        def dfs(root):
            temp = ""
            for i in graph[root]:
                temp += dfs(i)
            temp += s[root]
            ans[root] = temp==temp[::-1]
            return temp
        n = len(s)
        graph = [[] for _ in range(n)]

        for i in range(1, n):
            graph[parent[i]].append(i)
        
        # If all characters are the same, return True for all
        if len(set(s)) == 1:
            return [True] * n

        dp = ["-"] * n
        ans = [False] * n
        dfs(0)
        return ans