// first method
#### brute force approach
- 3 loop
- give TLE
​
#### better approach
- 2 loop
- using hash map
- fix a in first loop,  fix b in second loop and find target c = -(a+b)
- if it's exist add it in to answer
​
​
#### optimal approach
- using 2 loop and constant space
- fixed `a` and apply two sum problem
- a fixed
- b+c = -a
- find sum using two pointer