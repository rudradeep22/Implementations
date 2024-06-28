# Array Notes
### Boyer-Moore Majority Voting Algorithm
[Link to the problem](https://leetcode.com/problems/majority-element/)
We have to do the problem in O(n) time complexity and constant extra space.  

**Algorithm :**  
Choose one of these `n` elements as a `candidate` and record its votes as `votes = 1`.


At this point there are `n-1` elements in our array, we take out one element each time (denoted as `current`), and repeat the following steps (a total of `n-1` times)

Compare it to our current `candidate`, if they have the same value, then `votes++`, which is an affirmative vote
If their values are different, `votes--`, that is, a dissenting vote. If we get `votes = 0` at this time, then `candidate <- current`, which means that we make current the new candidate, and reset `votes = 1`



The final value of the candidate is maybe the element that appears more than half of the times we want, at this point, we have to traverse the array again to check if it is

