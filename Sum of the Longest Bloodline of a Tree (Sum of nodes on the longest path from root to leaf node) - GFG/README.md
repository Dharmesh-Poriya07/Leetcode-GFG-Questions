# Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:20px">Given a binary tree of size&nbsp;<strong>N.</strong>&nbsp;Your task is to complete the function&nbsp;<strong>sumOfLongRootToLeafPath(),</strong>&nbsp;that find the sum of all nodes on the longest path from root to leaf node.<br>
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.</span></p>

<p><strong><span style="font-size:20px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
<strong>Output:</strong> 13
<strong>Explanation:</strong>
        <strong>4</strong>        
       / \       
      <strong>2</strong>   5      
     / \ / \     
    7  <strong>1</strong> 2  3 
      /
     <strong>6</strong>

The highlighted nodes <strong>(4, 2, 1, 6)</strong> above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input: </span></strong><span style="font-size:18px">
&nbsp;         1
&nbsp;       /   \
&nbsp;      2     3
&nbsp;     / \   / \
&nbsp;    4   5 6   7</span>
<strong><span style="font-size:18px">Output: </span></strong><span style="font-size:18px">11</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong></span><br>
<span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>sumOfLongRootToLeafPath</strong></span><span style="font-size:18px"><strong>()&nbsp;</strong>which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= Number of nodes &lt;= 10</span><sup><span style="font-size:15px">4</span></sup><br>
<span style="font-size:18px">1 &lt;= Data of a node &lt;= 10<sup>4</sup></span></p>
</div>