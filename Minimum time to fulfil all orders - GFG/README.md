# Minimum time to fulfil all orders
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px"><strong>Geek</strong>&nbsp;is organizing a party at his house. For the party, he needs exactly&nbsp;<strong>N&nbsp;</strong>donuts for the guests.&nbsp;<strong>Geek</strong>&nbsp;decides to order the donuts from a nearby restaurant, which has&nbsp;<strong>L&nbsp;</strong>chefs and each chef has a rank <strong>R</strong>.&nbsp;<br>
A chef with rank&nbsp;<strong>R&nbsp;</strong>can make 1 donut in the first&nbsp;<strong>R</strong>&nbsp;minutes, 1 more donut in the next&nbsp;<strong>2R</strong>&nbsp;minutes, 1 more donut in&nbsp;<strong>3R</strong>&nbsp;minutes, and so on.<br>
For example. a chef with rank 2, can make one&nbsp;donut in 2 minutes, one more donut in the next 4 minutes, and one more in the next 6 minutes. So, it take 2 + 4 + 6 = 12 minutes to make 3 donuts. A chef can move on to making the next donut only after completing the previous one. All the chefs can work simultaneously.<br>
Since,&nbsp;it's time for the party,&nbsp;<strong>Geek&nbsp;</strong>wants to know the <strong>minimum</strong> time required in completing&nbsp;<strong>N</strong>&nbsp;donuts. Return an integer denoting the minimum time</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 10
L = 4
rank[] = {1, 2, 3, 4}
<strong>Output: </strong>12
<strong>Explanation:</strong> 
Chef with rank 1, can make 4 donuts in time 1 + 2 + 3 + 4 = 10 mins
Chef with rank 2, can make 3 donuts in time 2 + 4 + 6 = 12 mins
Chef with rank 3, can make 2 donuts in time 3 + 6 = 9 mins
Chef with rank 4, can make 1 donuts in time = 4 minutes
Total donuts = 4 + 3 + 2 + 1 = 10 and total time = 12 minutes.


</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 8
L = 8
rank[] = {1, 1, 1, 1, 1, 1, 1, 1}
<strong>Output: </strong>1
<strong>Explanation:</strong> 
As all chefs are ranked 1, so each chef can make 1 donuts 1 min.
Total donuts = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8 and total time = 8 minutes. 
</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>findMinTime</strong><strong>()</strong>&nbsp;which takes an integer&nbsp;<strong>N</strong>&nbsp;as input and an array A[] of length&nbsp;<strong>L</strong>&nbsp;denoting the ranks and return an integer denoting the minimum time.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*logN)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N&nbsp;&lt;= 10<sup>3</sup><br>
1 &lt;= L&nbsp;&lt;= 50<br>
1 &lt;= L[i]&nbsp;&lt;= 8</span></p>
</div>