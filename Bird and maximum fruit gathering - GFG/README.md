# Bird and maximum fruit gathering
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">There are<strong> N</strong> trees in a circle. Each tree has a fruit value associated with it. A bird has to sit on a tree for 0.5 sec to gather all the fruits present on the tree and then the bird can move to a neighboring tree. It takes the bird 0.5 seconds to move from one tree to another. Once all the fruits are picked from a particular tree, she cant pick any more fruits from that tree. The maximum number of fruits she can gather is infinite.</span></p>

<p><span style="font-size:18px">Given <strong>N</strong> and <strong>M</strong> (the total number of seconds the bird has), and an array <strong>arr[]&nbsp;</strong>containing the fruit values of the trees. Maximize the total fruit value that the bird can gather. The bird can start from any tree.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=7 M=3
arr[] = { 2 ,1 ,3 ,5 ,0 ,1 ,4 }
<strong>Output:</strong> 9
<strong>Explanation</strong>: 
She can start from tree 1 and move
to tree2 and then to tree 3.
Hence, total number of gathered fruits
= 1 + 3 + 5 = 9.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=6 M=2
arr[] = { 1, 6, 2, 5, 3, 4 }
<strong>Output:</strong> 8
<strong>Explanation</strong>:&nbsp;
She can start from tree 1 and move 
to tree 2. In this case she will gather
6 + 2 = 8 fruits. She can also start 
from tree 3 and move to tree 4. In this
case, too, she will gather 5 + 3 = 8 
fruits.
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input, or print anything. You just need to complete the function <strong>maxFruits</strong>() that takes <strong>array arr, integer N&nbsp;and integer M </strong>as parameters and returns the maximum number of fruits she can gather.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N).<br>
<strong>Expected Auxiliary Space:</strong> O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ N ≤ 10<sup>6</sup></span></p>

<p>&nbsp;</p>
</div>