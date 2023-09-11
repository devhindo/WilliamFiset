def knapsack(c, w, v):
    """
        c: capacity of the knapsack
        w: the weight of the items
        v: the value of the items
    """
    n = len(w)
    dp = [[0 for _ in range(c + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, c + 1):
            
            # get the the value and weight of the item
            weight, val = w[i - 1], v[i - 1]
            # for each knapsack size
            for j in range(1, c + 1):
                
                # consider not picking this element
                # intially set that as the best current value
                dp[i][j] = dp[i - 1][j]
                # then we check if we can update to a better value by including the current item
                if j >= weight and dp[i - 1][j - weight] + val > dp[i][j]:
                    dp[i][j] = dp[i - 1][j - weight] + val

        ######################################
        # checking what items are selected
        items = []
        sz = c
        for i in range(n, 0, -1):
            if dp[i][sz] != dp[i - 1][sz]:
                items.append(i)
                sz -= w[i - 1]
        
        # put the items in the natural order
        items.reverse()

        return dp[n][c], items

# test
c = 10
v = [1,4,8,5]
w = [3,3,5,6]

print(knapsack(c, w, v))