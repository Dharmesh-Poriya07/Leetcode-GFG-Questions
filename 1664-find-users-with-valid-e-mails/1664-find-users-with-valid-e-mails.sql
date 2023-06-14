select *
from users
where mail regexp '^[a-zA-Z]+[a-zA-Z0-9_.-]*@leetcode\\.com$';

# ^ : means start from initial
# [] : means charset
# a-z : - denotes range
# + : we want atleast one character at initial place
# * : means 0 or more character
# \\ : denotes we want . as it is, don't change it
# $ : means at the end of string