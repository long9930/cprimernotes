### Defining Abstract Data Types ###
* ```ADT``` have access to its interface,  have no access to the data members
* not ```ADT``` have access to data members,  have no access to the interface

### Designing the Sales_data Class ###
* An isbn member function to return the object’s ISBN
* A combine member function to add one Sales_data object into another
* A function named add to add two Sales_data objects
* A read function to read data from an istream into a Sales_data object
* A print function to print the value of a Sales_data object on an ostream

```cpp
Sales_data total;         // variable to hold the running sum
if (read(cin, total))  {  // read the first transaction
    Sales_data trans;     // variable to hold data for the next transaction
    while(read(cin, trans)) {      //  read the remaining transactions
        if (total.isbn() == trans.isbn())   // check the isbns
            total.combine(trans);  // update the running total
        else {
            print(cout, total) << endl;  // print the results
            total = trans;               // process the next book
        }
    }
    print(cout, total) << endl;          // print the last transaction
} else {                                 // there was no input
    cerr << "No data?!" << endl;         // notify the user
}
```


### Defining the Revised Sales_data Class ###
* Member functions must be declared inside the class. 
* Member functions may be defined inside the class itself or outside the class body. 
* Nonmember functions that are part of the interface, are declared and defined outside the class.

```cpp
struct Sales_data {
    // new members: operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // data members are unchanged from § 2.6.1 (p. 72)
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
```

* Member functions access the object on which they were called through an extra, implicit parameter named ```this```.
* When we call a member function, this is initialized with the address of the object on which the function was invoked.
```cpp
total.isbn()

// is equivalent to 

// pseudo-code illustration of how a call to a member function is translated
Sales_data::isbn(&total)
```
* Inside a member function, Any direct use of a member of the class is assumed to be an implicit reference through ```this```.
* when isbn uses bookNo, it is implicitly using the member to which this points. It is as if we had written ```this->bookNo```.
* it is illegal for us to define a parameter or variable named this
* Because ```this``` is intended to always refer to “this” object, ```this``` is a const pointer. We cannot change the address that ```this``` holds.

###Introducing ```const``` Member Functions###
* The purpose of that ```const``` is to modify the type of the implicit ```this``` pointer.
* the type of this is a const pointer to the nonconst version of the class type
* we cannot bind this to a const object
* we cannot call an ordinary member function on a const object
* we would declare ```this``` as ```const Sales_data *const```, so our function would be more flexible
* However, ```this``` is implicit and does not appear in the parameter list. There is no place to indicate that ```this``` should be a pointer to const.
* A ```const``` following the parameter list indicates that ```this``` is a pointer to ```const```. 
* Member functions that use ```const``` in this way are ```const``` member functions.

``` cpp
std::string isbn() const { return bookNo; }

// is equal to 

// pseudo-code illustration of how the implicit this pointer is used
// this code is illegal: we may not explicitly define the this pointer ourselves
// note that this is a pointer to const because isbn is a const member
std::string Sales_data::isbn(const Sales_data *const this)
{ return this->isbn; }
```
* ```const``` member functions cannot change the object on which they are called.
* Objects that are ```const```, and references or pointers to ```const``` objects, may call only ```const``` member functions.


### Class Scope and Member Functions ###
* the compiler processes classes in two steps—the member declarations are compiled first, after which the member function bodies, if any, are processed.
* Thus, member function bodies may use other members of their class regardless of where in the class those members appear.

### Defining a Member Function outside the Class ###
* when we define a member function outside the class body, the member’s definition must match its declaration. 
* If the member was declared as a ```const``` member function, then the definition must also specify ```const``` after the parameter list.
* The name of a member defined outside the class must include the name of the class of which it is a member
* 
### Defining a Function to Return “This” Object ###
* The object on which this function is called represents the left-hand operand of the assignment. 
* The right-hand operand is passed as an explicit argument

```cpp
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ''this'' object
    return *this; // return the object on which the function was called
}
```
* we do not need to use the implicit ```this``` pointer to access the members of the object on which a member function is executing
* we do need to use ```this``` to access the object as a whole
