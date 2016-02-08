# Chapter 3. Strings, Vectors, and Arrays
## 3.4 Iterators
Like pointers, iterator gives us indirect access to the data. Unlike pointers, iterator do not use the address-of operator. Types that support iterator have members return iterator.

```cpp
// the compiler determines the type of b and e; see § 2.5.2 (p. 68)
// b denotes the first element and e denotes one past the last element in v
auto b = v.begin(), e = v.end(); // b and e have the same type
```

If the container is not empty, 

* ```begin``` returns the iterator to the first element;
* ```end``` returns the iterator "one past the end" of the container. *Off-the-end iterator*.

**Operations**

Operation  | Meaning
------------- | -------------
```*iter```  | Return a reference to the element denoted by the iterator ```iter```.
```iter->men```  | Dereferences ```iter``` and fetch its member named ```mem```. Equivalent to ```(*iter).mem```.
```++iter``` | Increments ```iter``` to refer to the next element in the container.
```--iter``` | Decrements ```iter``` to refer to the previous element in the container.
```iter1==iter2``` | Compares two iterators for equality (inequality).
```iter1!=iter2``` | Two iterators are equal if they denote the same element or if they are the off-the-end iterator for the same container.

Iterators use the increment ```++``` operator  to move from one element to the next. 

```cpp
// process characters in s until we run out of characters or we hit a whitespace
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    *it = toupper(*it); // capitalize the current character
```

**Iterator type**
We do not need to know the precise type of the iterator.
```cpp
vector<int>::iterator it; // it can read and write vector<int> elements
string::iterator it2;     // it2 can read and write characters in a string
vector<int>::const_iterator it3; // it3 can read but not write elements
string::const_iterator it4;      // it4 can read but not write characters
```

**Combining dereference and member access**

```cpp
(*it).empty() // dereferences it and calls the member empty on the resulting object
*it.empty()   // error: attempts to fetch the member named empty from it
              //     but it is an iterator and has no member named empty
it->empty(); // the -> operator
```

**Iterator Arithmetics** 

## 3.5 Arrays

## 3.6 Multidimensional Arrays 