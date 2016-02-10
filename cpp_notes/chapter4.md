## C++ Primer C4.4
The left-hand operand of an assignment operator must be a 
* ```modifiable``` 
* ```lvalue ```

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

* The result of an assignment is its left-hand operand, which is an lvalue. 
* The type of the result is the type of the left-hand operand. 
* If the types of the left and right operands differ, the right-hand operand is converted to the type of the left:
```cpp
k = 0;          //  result: type int, value 0
k = 3.14159;    //  result: type int, value 3
```

Under the new standard, we can use a braced initializer list on the right-hand side:
```cpp
k = {3.14};                 // error: narrowing conversion
vector<int> vi;             // initially empty
vi = {0,1,2,3,4,5,6,7,8,9}; // vi now has ten elements, values 0 through 9
```


## C++ Primer C4.5 C4.6




## C++ Primer C4.7



## C++ Primer C4.9~C4.11

