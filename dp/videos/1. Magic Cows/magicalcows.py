nums = input().split()

c = int(nums[0]) # the maximum number of cows allowed on a farm
n = int(nums[1]) # the number of farms with at least one cow on Day 0
m  = int(nums[2]) # the number of different days the regulator visits

cows = [] # [1,1,1,1,1]

for i in range(n):
    cow = int(input())
    cows.append(cow)

days = [] # [0,1,2,3,4]

for i in range(m):
    day = int(input())
    days.append(day)

def solve(c,cows,days):

    u = max(days) 
    dp = [0] * (1050)
    dp[1] = 1 
    x = 1
    i = 1
    while x<c:
        dp[i+1] = 1
        i += 1
        x *= 2

    i += 1

    while i < (len(dp)):
        dp[i] = dp[i-1]*2
        i += 1
    

    for day in days:
        t = 0
        for cow in cows:
            t += dp[cow+day]
        print(t)
    

solve(c,cows,days)