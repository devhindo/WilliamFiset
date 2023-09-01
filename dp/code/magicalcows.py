c = input() # the maximum number of cows allowed on a farm
n = input() # the number of farms with at least one cow on Day 0
m  = input() # the number of different days the regulator visits

cows = [] # [1,1,1,1,1]

for i in range(n):
    cow = input()
    cows.append(cow)

days = [] # [0,1,2,3,4]

for i in range(m):
    day = input()
    days.append(day)

def solve(c,cows,days):

    output = []
    output.append(len(cows))
    
