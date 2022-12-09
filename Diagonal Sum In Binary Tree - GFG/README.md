# Diagonal Sum In Binary Tree
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Consider Red lines of slope -1 passing between nodes (in following&nbsp;diagram). The diagonal sum in a binary tree is the sum of all node’s data lying between these lines.&nbsp;Given a Binary Tree of size <strong>N</strong>, print all diagonal sums.</span></p>

<p><span style="font-size:18px">For the following input tree, output should be 9, 19, 42.<br>
9 is sum of 1, 3 and 5.<br>
19 is sum of 2, 6, 4 and 7.<br>
42 is sum of 9, 10, 11 and 12.</span></p>

<p><a href="https://media.geeksforgeeks.org/wp-content/uploads/diagonal-sum-in-a-tree.jpg"><img alt="DiagonalSum" src="https://media.geeksforgeeks.org/wp-content/uploads/diagonal-sum-in-a-tree.jpg" style="height:403px; width:600px"></a></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:</span></strong>
<span style="font-size:18px">&nbsp;        4
&nbsp;      /   \
&nbsp;     1     3
&nbsp;          /
&nbsp;         3</span><strong><span style="font-size:18px">
Output: </span></strong><span style="font-size:18px">7 4&nbsp;</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:</span></strong>
<span style="font-size:18px">&nbsp;          10
&nbsp;        /    \
&nbsp;       8      2
&nbsp;      / \    /
&nbsp;     3   5  2</span><strong><span style="font-size:18px">
Output: </span></strong><span style="font-size:18px">12 15 3&nbsp;</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to take input. Just complete the function<strong>&nbsp;diagonalSum()&nbsp;</strong>that takes root <strong>node</strong> of the tree&nbsp;as parameter and returns an array containing the diagonal sums for every diagonal present in the tree with slope -1.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity</strong>: O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=Number of nodes&lt;=10<sup>5</sup></span><br>
<br>
<span style="font-size:14px"><strong>Note:&nbsp;</strong>The <strong>Input/Ouput</strong> format and <strong>Example</strong> given are used for system's internal purpose, and should be used by a user for <strong>Expected Output</strong> only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</span></p>
</div>