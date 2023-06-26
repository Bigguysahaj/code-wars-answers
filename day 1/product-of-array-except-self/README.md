# Product Of Array Except Self

![image](https://github.com/Bigguysahaj/code-wars-answers/assets/70798888/0474ae38-b521-4472-b695-cca998d4e7f6)

Basically, jis position pei you have you have your current iterator i , usee hide kro aur naye array mei ussi index i pei value daaldo.
Don't overthink it.

# Topics to understand and know well

how to make a new array pointer
![image](https://github.com/Bigguysahaj/code-wars-answers/assets/70798888/61085b78-b186-46ad-a23a-4b558eadce2e)

Modulo 1e9+7 or 1000000007
[https://www.geeksforgeeks.org/modulo-operator-in-c-cpp-with-examples/](https://www.geeksforgeeks.org/modulo-1097-1000000007/)


# Best Approaches

Basic approach is 2 for loop approach, where you just compute the product of the whole array except for the index that you are currently on
Second better approach is to calculate first the product, and divide the product with the current element you are on. This is one for loop and O(n).

None of the both seems to give the all 6/6 test cases correct at least for me.
The approach below gives the right answers.


# Function Signature

```c++
int *getProductArrayExceptSelf(int *arr, int n)
```
The getProductArrayExceptSelf function takes an integer array arr and its length n as input and returns a new integer array as output.

# Variable Initialization
```c++
int *ans = new int[n];
```
The function begins by initializing a new integer array ans of size n dynamically using the new keyword. This array will store the product array except for the current element.

# Base Cases
```
if (!n) return ans;
```
If the length of the input array n is zero, indicating an empty array, the function returns the initialized ans array immediately.

```
if (n == 1) {
    ans[0] = 1;
    return ans;
}
```
If the length of the input array n is 1, meaning there is only one element in the array, the function sets the value of ans[0] to 1 and returns the ans array. This is because there are no other elements to multiply, so the result will be 1.

# Product Calculation - Forward Pass

```c++
int m = 1000000007;
long long int prod = 1;
int store = -1;
int count = 0;

for (int i = 0; i < n; i++) {
    ans[i] = prod;
    prod = (prod * arr[i]) % m;
}
```
This section calculates the product of all elements to the left of the current element in the input array. It initializes prod as 1 and then iterates over the array from left to right. For each element at index i, it updates ans[i] with the current value of prod, which represents the product of all elements to the left of i. Then, it updates prod by multiplying it with arr[i] and taking the modulo m to prevent overflow.

# Product Calculation - Backward Pass

```c++
prod = 1;
for (int i = n - 1; i >= 0; i--) {
    ans[i] = (ans[i] * prod) % m;
    prod = (prod * arr[i]) % m;
}
```
This section calculates the product of all elements to the right of the current element in the input array. It resets prod as 1 and then iterates over the array from right to left. For each element at index i, it multiplies ans[i] with the current value of prod, which represents the product of all elements to the right of i. Then, it updates prod by multiplying it with arr[i] and taking the modulo m.

# Return the Result

```c++
return ans;
```
After the forward and backward passes, the function returns the ans array, which contains the product array except for the current element at each index.

That's the complete explanation of the getProductArrayExceptSelf function. It calculates the product of all elements except the current element using a forward and backward pass approach, and returns the resulting array
