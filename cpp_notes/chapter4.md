## C++ Primer C4.4
The left-hand operand of an assignment operator must be a

1. ```modifiable```,

2. ```lvalue ```. 

Every C++ expression is either an ```lvalue``` or an ```rvalue```. An ```lvalue refers to an object that persists beyond a single expression```. You can think of an lvalue as an object that has a name. All variables, including nonmodifiable (const) variables, are lvalues. An ```rvalue is a temporary value that does not persist beyond the expression that uses it```. To better understand the difference between lvalues and rvalues.

an rvalue is when the expression result will not survive past the end of said expression. An lvalue will. This basic principle is what enables move semantics and rvalue references- that you can modify them without issue, because you know that object's life is over.

For example, given
```cpp
int i = 0, j = 0, k = 0; // initializations, not assignment
const int ci = i;        // initialization, not assignment
```
Each of these assignments is illegal:
```cpp
1024 = k;      // error: literals are rvalues
i + j = k;     // error: arithmetic expressions are rvalues
ci = k;        // error: ci is a const (nonmodifiable) lvalue
```



## C++ Primer C4.5 C4.6




## C++ Primer C4.7



## C++ Primer C4.9~C4.11
