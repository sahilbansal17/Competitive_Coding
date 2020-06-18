### Problem D:

<!-- problem description -->

You have an array `arr` containing `N` integers.
You can perform the following operation as many time as required:

- Choose any two elements say `arr[i] = x` and `arr[j] = y`.
- Set `arr[i] = x | y` and `arr[j] = x & y`.

You need to maximize the sum of squares of the resulting array.

Constraints are:

- $$ 1 \leq N \leq 2 \times 10^5 $$
- $$ 0 \leq arr[i] \leq 2^{20} $$

<!-- problem hint 1 -->
<details>
<summary>
Hint 1 
</summary>

- Take some **small examples** and write numbers in binary representation and try to **observe** when you get the maximum sum of squares.
- To verify:

  - if the following binary numbers are input: `0001, 0011, 0101, 1000`.
  - They will get converted to: `0000, 0001, 0001, 1111`, to get the optimal answer.

</details>

<!-- hint 2 -->
<details>
<summary>
Hint 2 
</summary>

- Try to **sort** the numbers and perform operations on adjacent numbers, observe that this **does not** lead to optimal solution in some cases, for eg (numbers in binary):
  - **Input**: `00011, 00110, 01000, 10000, 10001, 11000`
  - **Output** array for optimal answer: `00000, 00000, 00000, 10000, 11011, 11111`
- Observe any pattern?
- Think in terms of **count of bits set at a particular position** in the input numbers!

</details>

<!-- Solution approach -->
<details>
<summary>
Solution approach
</summary>

- **OBSERVATION**: We can shift the bits set at a particular position to the maximum numbers (in the end, i.e. largest numbers), so as to maximize the square value.
- Find the count of set bits at a particular position in all the numbers, **these many numbers from the end** should have this bit set while calculating the answer, try some examples yourself.
- So, we can just maintain a **count array for 20 bits**, and at the end, **construct numbers** from the last number using the counts, and break when constructed no is zero, i.e. all counts are used up. See implementation below for details.

</details>

<!-- time complexity -->
<details>
<summary>
Time Complexity
</summary>
$$ \mathcal{O(N * 20)} $$
</details>

<!-- code -->
<details>
<summary>
Code
</summary>
{% highlight c++ %}

{% endhighlight %}

</details>

---
