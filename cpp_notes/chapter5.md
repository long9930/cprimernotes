## C++ Primer C5.4

###Iterative Statements###
Iterative statements, commonly called loops, provide for repeated execution until a condition is true. 
* while and for statements test the condition before executing the body. 
* do while executes the body and then tests its condition.


###The while Statement###
A while statement repeatedly executes a target statement as long as a condition is true. Its syntactic form is
```cpp
while (condition)
      statement
```

* condition may not be empty. 
* If the first evaluation of condition yields false, statement is not executed.
* The condition can be an expression or an initialized variable declaration. 
* Variables defined in a while condition or while body are created and destroyed on each iteration.
* the condition itself or the loop body must change the value of the expression. Otherwise, the loop might never terminate.


* A while loop is generally used when we want to iterate indefinitely, such as when we read input. 
* A while is also useful when we want access to the value of the loop control variable after the loop finishes.

```cpp
vector<int> v;
int i;
// read until end-of-file or other input failure
while (cin >> i)
    v.push_back(i);
// find the first negative element
auto beg = v.begin();
while (beg != v.end() && *beg >= 0)
    ++beg;
if (beg == v.end())
    // we know that all elements in v are greater than or equal to zero
```
* The first loop reads data from the standard input. We have no idea how many times this loop will execute. The condition fails when cin reads invalid data, encounters some other input failure, or hits end-of-file. 
* The second loop continues until we find a negative value. When the loop terminates, beg is either equal to v.end(), or it denotes an element in v whose value is less than zero. 
* We can use the state of beg outside the while to determine further processing.

###Traditional for Statement###
The syntactic form of the for statement is:
```cpp
for (init-statement condition; expression)
    statement
```
* The for and the part inside the parentheses is often referred to as the for header.
* init-statement must be a declaration statement, an expression statement, or a null statement. Each of these statements ends with a semicolon

```cpp
for (initializer; condition; expression)
      statement
```

* init-statement is used to initialize or assign a starting value that is modified over the course of the loop. 
* condition serves as the loop control. As long as condition evaluates as true, statement is executed. If the first evaluation of condition yields false, statement is not executed. 
* expression usually modifies the variable(s) initialized in init-statement and tested in condition. expression is evaluated after each iteration of the loop. As usual, statement can be either a single or a compound statement.


```cpp
// process characters in s until we run out of characters or we hit a whitespace
for (decltype(s.size()) index = 0;
     index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]); // capitalize the current character
```
the order of evaluation is as follows:
* 1. init-statement is executed once at the start of the loop. In this example, index is defined and initialized to zero.
* 2. Next, condition is evaluated. If index is not equal to s.size() and the character at s[index] is not whitespace, the for body is executed. Otherwise, the loop terminates. If the condition is false on the first iteration, then the for body is not executed at all.
* 3. If the condition is true, the for body executes. In this case, the for body makes the character at s[index] uppercase.
* 4. Finally, expression is evaluated. In this example, index is incremented by 1.

These four steps represent the first iteration of the for loop. Step 1 is executed only once on entry to the loop. Steps 2, 3, and 4 are repeated until the condition evaluates as false—that is, when we encounter a whitespace character in s, or index is greater than s.size().

* It is worth remembering that the visibility of any object defined within the for header is limited to the body of the for loop. Thus, in this example, index is inaccessible after the for completes.

Multiple Definitions in the for Header
* init-statement can define several objects. 
* init-statement may be only a single declaration statement. 
* Thus, all the variables must have the same base type. 
```cpp
// remember the size of v and stop when we get to the original last element
for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
    v.push_back(v[i]);
```

Omitting Parts of the for Header
* We can use a null statement for init-statement when an initialization is unnecessary. 
* semicolon is necessary to indicate the absence of init-statement
* for body can be empty because all the work of the loop can be done inside the for condition and expression

```cpp
auto beg = v.begin();
for ( /* null */; beg != v.end() && *beg >= 0; ++beg)
    ; // no work to do
```

* Omitting condition is equivalent to writing true as the condition.
* the for body must contain a statement that exits the loop. Otherwise the loop will execute indefinitely
```cpp
for (int i = 0; /* no condition */ ; ++i) {
    // process i; code inside the loop must stop the iteration!
}
```

* We can also omit expression from the for header.
* either the condition or the body must do something to advance the iteration

```cpp
vector<int> v;
for (int i; cin >> i; /* no expression */ )
   v.push_back(i);
```

###Range for Statement### 
```cpp
for (declaration : expression)
    statement
```
expression must be
* a sequence, such as a braced initializer list, an array
* object of a type such as vector or string that has begin and end members that return iterators

declaration defines a variable. 
* It must be possible to convert each element of the sequence to the variable’s type
* The easiest way is to use the auto type specifier
* On each iteration, the control variable is defined and initialized by the next value in the sequence, after which statement is executed. 
* Execution ends once all the elements have been processed.

```cpp
vector<int> v = {0,1,2,3,4,5,6,7,8,9};
// range variable must be a reference so we can write to the elements
for (auto &r : v)   // for each element in v
    r *= 2;         // double the value of each element in v
```
* Because we want to change the value of the elements in v, we declare r as a reference.
* we cannot use a range for to add elements to a vector
* In a range for, the value of end() is cached.
* If we add elements to (or remove them from) the sequence, the value of end might be invalidated


###The do while Statement###
A do while statement is like a while but the condition is tested after the statement body completes. Regardless of the value of the condition, we execute the loop at least once. 

```cpp
do
        statement
while (condition);
```
* In a do, statement is executed before condition is evaluated
* condition cannot be empty
* If condition evaluates as false, then the loop terminates; otherwise, the loop is repeated. 
* Variables used in condition must be defined outside the body of the do while statement Because the condition is not evaluated until after the statement or block is executed.
```cpp
do {
    // . . .
    mumble(foo);
} while (int foo = get_foo()); // error: declaration in a do condition
```

```cpp
// repeatedly ask the user for a pair of numbers to sum
string rsp;  // used in the condition; can't be defined inside the do
do {
    cout << "please enter two values: ";
    int val1 = 0, val2 = 0;
    cin  >> val1 >> val2;
    cout << "The sum of " << val1 << " and " << val2
         << " = " << val1 + val2 << "\n\n"
         << "More? Enter yes or no: ";
    cin  >> rsp;
} while (!rsp.empty() && rsp[0] != 'n');
```
* The loop starts by prompting the user for two numbers. 
* It then prints their sum and asks whether the user wishes to do another sum.
* The condition checks that the user gave a response. If not, or if the input starts with an n, the loop is exited. Otherwise the loop is repeated.

## C++ Primer C5.5


## C++ Primer C5.6
