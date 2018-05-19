#### Question 9

You will be implementing the following methods in the `BinaryTree` class:

- `int minHeight();`

Given a binary tree, write a function `minHeight()` to find the shortest distance from the root to a leaf node.

For example, if the binary tree is:

```
   20
 /    \
15    24
      / \
     22  26
           \
            30
```

then the minimum height is 1.

If the tree is empty your code should return -1.

**Write your solution in `binarytree_q9.cpp`.**


- - -

#### Question 10

You will be implementing the following methods in the `BinaryTree` class:

- `Node* findClosest(int value) const;`

Given a binary search tree and key, write a function `findClosest(int value)`
which returns a pointer to the node which has the closest value to the given
value.

The function should return `NULL` if the tree is empty.

For example, if the binary search tree is

```
    _20_
   /    \
  15    24
 / \    / \
12  18 22  26
```

then `findClosest(17)` should return the node object with value `18` and
`findClosest(22)` should return the node with value `22`.

**Write your solution in `binarytree_q10.cpp`.**
