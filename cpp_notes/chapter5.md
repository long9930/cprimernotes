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
(a) 
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++;
    case 'e': eCnt++;
    default: iouCnt++;
}
(b) 
unsigned index = some_value();
switch (index) {
    case 1:
        int ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
}
(c)
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}
(d) 
unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

## C++ Primer C5.5


## C++ Primer C5.6
