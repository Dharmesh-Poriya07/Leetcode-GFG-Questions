# Deletion in a Binary Tree
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a Binary Tree of size&nbsp;<strong>N</strong>, your task is to complete the function <strong>deletionBT()</strong>, that should&nbsp;delete a given&nbsp;node from the tree&nbsp;by making sure that tree shrinks from the bottom (the deleted node&nbsp;is replaced by bottommost and rightmost node).<br>
Example:</span></p>

<p><span style="font-size:18px"><input alt="Eample Deletion in Bt" src="http://contribute.geeksforgeeks.org/wp-content/uploads/deletion_new.png" style="height:368px; width:448px" type="image"></span></p>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't have to take input. Complete the function&nbsp;<strong>deletionBT()&nbsp;</strong>that takes <strong>root</strong>&nbsp;node of the tree and given node value (<strong>Key</strong>) as input parameter and return the root of the&nbsp;modified tree.<br>
<br>
<strong>Example 1:</strong></span><br>
&nbsp;</p>

<pre><span style="font-size:18px"><strong>Input:</strong>
Key=1</span>
<span style="font-size:18px">         1</span>
<span style="font-size:18px">       /   \</span>
<span style="font-size:18px">      4     7</span>
<span style="font-size:18px">     / \</span>
<span style="font-size:18px">    5   6 
<strong>Output:</strong>
5 4 6 7 </span>

<strong><span style="font-size:18px">Explanation:</span></strong>
<span style="font-size:18px">Modified Tree after deletion the 
node with key = 1
</span><span style="font-size:18px">     6</span> 
<span style="font-size:18px">    / </span> <span style="font-size:18px">\</span>
<span style="font-size:18px">   4 </span> <span style="font-size:18px">  7
  /  </span> 
<span style="font-size:18px"> 5     
The Inorder traversal of the modified 
tree is 5 4 6 7 </span>


</pre>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=10<sup>4</sup></span></p>
</div>