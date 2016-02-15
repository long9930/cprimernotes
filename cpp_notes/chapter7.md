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
