### Problem D: 

<!-- problem description -->
You have an array `arr` containing `N` integers, which are all initially `0`. You need to perform `N` actions, and in the $$i^{th}$$ action you do the following:

- Choose the subarray with maximum length having all zeroes, if multiple choose one which starts earlier
- Let it be $$[l, r]$$ if length is odd, set $$arr[\frac{l + r}{2}] = i$$ otherwise, $$arr[\frac{l + r - 1}{2}] = i$$

<!-- problem hint 1 -->
<details>
<summary>
Hint 1 
</summary>

- You just need to implement the algorithm as stated, but need to think how to get the interval on which we need to perform the action easily!

- As we will process an interval, we put a value in the middle of it, and the left and right intervals will have all zeroes. Next time, we need an interval with larger length, and if length is same, with smaller start index. **Can you think of some data structure that can query this quickly for you?**
</details>

<!-- hint 2 -->
<details>
<summary>
Hint 2 
</summary>

- What about a priority queue (pq)?
- Push the interval as `{length, {start, end}}` pair. Initially, pq will have `{n, {0, n - 1}}` as the first element.
- Now, while pq is not empty, pop the element at the front (that should be one with max length and if multiple, with smallest start) so you need to define a custom comparator.
- Once you pop this interval, update the value at middle, and push the left and right intervals. There are some minute implementation details you need to take care of.
- Also, note that the **maximum no. of intervals** in pq will not be more than `N`, think about it!
</details>

<!-- time complexity -->
<details>
<summary>
Time Complexity
</summary>
$$\mathcal{O}(N log N)$$
</details>

<details>
<summary>
Implementation Details
</summary>

- Read [priority_queue docs](https://en.cppreference.com/w/cpp/container/priority_queue) to know more about custom comparators.
- In short, you can define a struct or class and overrride the () operator inside it.
- This comparator works different from the custom comparators of sort function, you return exactly the opposite value of what is required.
- Do check for validity of an interval before pushing to the priority queue. (start must be <= end)
</details>

<!-- code -->
<details>
<summary>
Code
</summary>
{% highlight c++ %}

{% endhighlight %}
</details>

- - - 

