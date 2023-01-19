# Remove Half Nodes
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given A binary Tree. Your task is to remove all the half nodes (which has only one child).</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
&nbsp;        7
&nbsp;      /   \
&nbsp;     7     8
&nbsp;    / 
&nbsp;   2<strong>
Output: </strong>2 7 8&nbsp;</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
&nbsp;        2
&nbsp;      /   \
&nbsp;     7     5
&nbsp;      \      \
&nbsp;       9      1
&nbsp;      /  \
&nbsp;     11   4<strong>
Output: </strong>11 9 4 2 1 </span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function</span><span style="font-size:18px">&nbsp;<strong>RemoveHalfNodes()</strong> which takes the&nbsp;root node of the tree as input&nbsp;and returns the root node of the modified tree after removing all the half nodes, ie the ones having just a single child node. (The inorder traversal of the returned tree is printed by the driver's code.)<br>
For example consider the below tree.<br>
<img alt="" src="https://www.cdn.geeksforgeeks.org/wp-content/uploads/maxMin.png" style="height:310px; width:311px"></span></p>

<p><span style="font-size:18px">Nodes 7, 5 and 9 are half nodes as one of their child is Null. We need to remove all such half nodes and return the root pointer of following new tree.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of the Binary Tree).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=Number of nodes&lt;=10<sup>4</sup></span></p>

<p><span style="font-size:14px"><strong>Note:</strong>The <strong>Input/Ouput</strong> format and <strong>Example</strong> given are used for system's internal purpose, and should be used by a user for <strong>Expected Output</strong> only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</span></p>
</div>