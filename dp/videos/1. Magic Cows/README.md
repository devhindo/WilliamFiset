# 1. Magic Cows

[video](https://youtu.be/_tur2nPkIKo?si=c1GNSgShG1C6IJph)

 [full problem statement](https://open.kattis.com/problems/magicalcows), [sol](../../code/magicalcows.py)

## 1.1. Abstract statement

```text
    Baxter Scott owns several farms with magic cows. Every morning at midnight, the number of cows in each of his farms doubles! While he is ecstatic that he has so many cows and so much milk, the Dairy Regulator forces him to keep at most 𝐶 cows on any given farm, which greatly complicates his business.

    To stay within the Regulator’s rules, whenever a farm has strictly more than 𝐶 cows, Baxter selects half of the cows on that farm and moves them to an entirely new, empty farm.

    The Regulator needs to know how many farms she will be inspecting when she visits Baxter’s farm. Given the number of cows on each farm with at least one cow on Day 0, compute the number of farms that need inspecting on any given day.
```
