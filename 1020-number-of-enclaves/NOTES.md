## Hints:
1. count total one's in grid and subtract set of one's which are connected to the boundry.
2. steps:
>> push all the one's in to queue, which are on boundry.
>> now apply BFS and push other1's which are adjacent of queued 1's and each time subtract 1 from total one's.
>> return remaining count.