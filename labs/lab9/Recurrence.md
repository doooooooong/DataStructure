**Problem 1 - insertion sort**

Recurrence relation: The time to sort an array of N elements is equal to the time to sort an array of N-1
elements plus N-1 comparisons. Initial condition: the time to sort an array of 1 element is constant: 

T(1) = 1
T(N) = T(N-1) + N-1
Next we perform telescoping: re-writing the recurrence relation for N-1, N-2, ..., 2

T(N) = T(N-1) + N-1

T(N-1) = <span style="color:red"><u>T(N-2) + N-2</u> </span>

T(N-2) = <span style="color:red">  <u>T(N-3) + N-3</u> </span>
......

T(2) =<span style="color:red"> <u>T(1) + 1</u> </span>



Next we sum up the left and the right sides of the equations above:
T(N) + T(N-1) + T(N-2) + T(N-3) + .... T(3) + T(2) =
T(N-1) + T(N-2) + T(N-3) + .... T(3) + T(2) + T(1) +  <span style="color:red"> <u>1 + 2 + 3 + ... + N-2 + N-1</u> </span>

Finally, we cross the equal terms on the opposite sides and simplify the remaining sum on the right side: 

T(N) = T(1) + <span style="color:red"> <u>1 + 2 + 3 + ... + N-2 + N-1</u></span> (Open form)

T(N) =  1 + <span style="color:red"> $ \frac{N(N-1)}{2} $ </span> (Closed form)

Therefore, the running time of insertion sort is: 
T(N) = <span style="color:red"> <u>O($N^2$)</u> </span> (big O)





**Problem 2**

T(1) = 1

T(N) = T(N–1) + 2 		// 2 is a constant like c 

Telescoping:
T(N) = <span style="color:red"> <u>T(N-1) + 2</u></span>
T(N-1) =<span style="color:red"> <u>T(N-2) + 2</u></span>
T(N-2) = <span style="color:red"><u>T(N-3) + 2</u></span>
......
T(2) = <span style="color:red"><u>T(1) + 2</u></span>



Next we sum up the left and the right sides of the equations above:

T(N) + T(N-1) + <span style="color:red"> <u>T(N-2) + T(N-3) + ... + T(2)</u> </span>=
T(N-1) + <span style="color:red"> <u>T(N-2) + 2 + T(N-3) + 2 ... + T(1) + 2</u></span>



Finally, we cross the equal terms on the opposite sides and simplify the remaining sum on the right side:

T(N) = T(1) + <span style="color:red"> <u>2 + 2 + 2 + ... + 2</u></span> (open form) 

T(N) = 1 + <span style="color:red"> <u>2(N-1)</u> </span> (closed form) 

Therefore, the running time of reversing a queue is: 
T(N) = <u><span style="color:red">O(N)</span></u> (Big O)





**Problem 3 - Power()**

```c++
long power(long x, long n) {
  if (n == 0) return 1;
  else return x * power(x, n-1);
}
```

T(n) = Time required to solve a problem of size n
Recurrence relations are used to determine the running time of recursive programs–recurrence relations themselves are recursive

T(0) = time to solve problem of size 0 : Base Case
T(n) = time to solve problem of size n : Recursive Case



T(0) = 1

T(n)=T(n–1)+1    //  +1 is a constant

Solution by telescoping:
If we knew T(n−1), we could solve T(n).

T(n)=T(n–1) +1

T(n–1) = <span style="color:red"> <u>T(n-2) + 1</u> </span>

T(n–2) = <span style="color:red">T(n-3) + 1 </span>

....

T(2) = <span style="color:red"> <u>T(1) + 1</u> </span>

T(1) = <span style="color:red"> T(0) + 1 </span>



Next we sum up the left and the right sides of the equations above: 

T(n) + <span style="color:red"> <u>T(n-1) + T(n-2) + ... + T(1)</u> </span>

<u><span style="color:red">= T(n-1) + 1 + T(n-2) + 1 + ... T(0) + 1 </span></u>



Finally, we cross the equal terms on the opposite sides and simplify the remaining sum on the right side:

T(n) = <span style="color:red"><u>T(0) + 1 + 1 + 1 + ... + 1</u> </span>  (Open form) 

T(n) = <span style="color:red"> <u>T(0) + n-1</u> </span> (Closed form) 

T(n) = <span style="color:red"><u>O(n)</u></span> (Big O)





**Problem 4 - Power()**

```c++
long power(long x, long n) {
  if (n == 0) return 1;
  if (n == 1) return x;

  if ((n % 2) == 0) return power(x * x, n/2);
  else return power(x * x, n/2) * x;
}
```



T(0) = 1
T(1) = 1
T(n) = T(n / 2) + 1 // Assume n is power of 2, +1 is a constant 

Solution by unfolding:

T(0) = 1
T(1) = 1
T(n) = T(n/2) + 1
= <span style="color:red"> <u>T(n/4) + 1 + 1</u> </span>
= <span style="color:red"> <u>T(n/8) + 1 + 1 + 1</u> </span>
= <span style="color:red"> <u>T(n/16) + 1 +1 + 1 + 1</u> </span>
....
= <span style="color:red"> T($\frac{n}{2^k}$)  + k</span>



We want to get rid of T(n/2k).
We solve directly when we reach T(1) 

n/2<sup>k</sup>  = 1

log n = k



T(n) = ____________ (Open form) 

 = ____________  (Open form)

= ____________ (Closed form)

Therefore, T(n) = <span style="color:red"> $log\  n$ </span> (Big O)

