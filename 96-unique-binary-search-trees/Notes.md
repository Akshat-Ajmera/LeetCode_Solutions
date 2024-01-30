<h2>unique-binary-search-trees Notes</h2><hr>we can calculate total binary trees by making each node a root node
for some i, i-1 nodes will be on left and n-i will be on right
total combinations will be no of trees with i-1 nodes * no of trees with n-i nodes
use dp to store previously calculated ans
for i=0 and i=1 only 1 bst is possible