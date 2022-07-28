# STANDARD TEMPLATE LIBRARY

`ios_base::sync_with_stdio(false);`  
`cin.tie(NULL);`  
[cin tie and sync - StackOverflow](https://stackoverflow.com/a/31165481)  
sync_with_stdio(false) will remove synchronisation between C and C++ standard streams. By default, std streams are synchronised, which allows you to mix C and C++ style I/O and get sensible and expected results. Disablng the sync b/w them will give UB when you try to mix C n C++ style I/O.

cin.tie(NULL) will untie cin from cout. Usually cin and cout are tied. Which means calling cin will first flush cout buffer, and then ask for input from the user. If you untie cin from cout, make sure to flush output stream everytime you want to display something before expecting input on cin.

**RANDOM NUMBER GENERATOR**  
[RNG Codeforces blog](https://codeforces.com/blog/entry/61587)  
use mt19937 instead of rand().Much faster, much less restriction on numbers. Better overall.

## VECTORS

[GFG Vectors](https://www.geeksforgeeks.org/vector-in-cpp-stl/)

```cpp
typedef vector<int> vi;
vi v1(n); //length of vector is n
vi v2(n, a); //length is n, all initialized to a 
vi v3{1, 2, 3, 4};
vi v4{v3.begin()+1, v3.end()-1};
```

now .`begin()` is iterator to first element to array, and .`end()` is iterator to one after the last element of array.  
`vi vec(iterator1, iterator2);` will copy everything from iterator1 to BEFORE iterator2.
So v4 contains `{2, 3}`.  
std functions `sort(__first, __last);`
will sort the elements in the range `[__first,__last)` in **ascending order, such that for each iterator i in the range `[__first,__last-1)`, `(i+1)<*i` is false. The relative ordering of equivalent elements is not preserved, use `stable_sort()` if this is needed.**

`reverse()` will reverse order of elements in the range `[__first,__last)`.  
`rbegin()` and `rend()` are like reverse iterators (begin and end iterators if you are traversing the vector from last to first)for beginning and end.  
`rbegin() = end()-1` and `rend()=begin()-1.`  
`cbegin()` etc is a constant iterator equivalent to `begin()` etc.

**Obscure functions related to space & memory**
`size()`==int,no.of elements;  
`max_size()`==int, max elements it can hold;  
`capacity()`, `resize(n)`==void,resizes container to contain n elements only;  
`shrink_to_fit()`==void, reduces capacity to first its size and destroys all elements beyond capacity;  
`empty()`==bool, whether_empty

**Functions related to modifying contents**
`assign(std::initializer_list<int> __l);`
`assign(__first, __last);`
`assign(n, val);` will assign n entries with value val to vector.

`insert(iterator, value);` will insert value at position iterator, and return pointer to newly inserted element.  
`insert(iterator, std::initializer_list<int> __l);`
`insert(iterator, __first, __last);`

`erase(std::vector<int>::const_iterator __position)` will remove element at that pos.  
`erase(__first, __last);`
`clear()` will empty the vector

`std::fill(__first, __last, __val)` will assign value __val to range [first, last).

## STRINGS

[GFG String](https://www.geeksforgeeks.org/stdstring-class-in-c/)  
`getline()` can be used to get user input from cin into a string.
`copy(char *__s, std::size_t __n, std::size_t __pos)` *will copy substring to* `char array __s`.  
__n is the no of characters to copy, and__pos is index of first element to be copied.  
`swap()` will swap 2 strings.

### STACK, DEQUE, QUEUE, PRIORITY_QUEUE  

*LIFO (Last in, first out)*  
means that the last arriving unit in the inventory is sold first.  
*FIFO (First in, first out)*  
means that the first arriving unit in an inventory is sold first.  
**Stack is LIFO, queue is FIFO.**  

## STACK

[GFG Stack](https://www.geeksforgeeks.org/stack-in-cpp-stl/)  
In stack, *topmost element = 'first' element*
`empty()`==bool, whether_empty;  
`size()`==int, size of stack;  
`top()` returns a *read/write reference to the topmost element of the stack.*  
`pop()`==void, removes the first element of the stack;  
`push(value)`==void, *adds data to top of stack.*  
`swap()` will swap one stack with another.  

## QUEUE

[GFG Queue](https://www.geeksforgeeks.org/queue-cpp-stl/)  
[GFG Containers](https://www.geeksforgeeks.org/containers-cpp-stl/`)  

Queue is a container adaptor, operates in FIFO manner.  
`push()` adds element to end of queue.  
`front()` returns a read/write reference to the first element of the queue.  
`pop()` removes first element of queue.  
`empty()`==bool, whether_empty;  
`back()` returns a read/write reference to the last element of the queue.

## DEQUE

[GFG Deque](https://www.geeksforgeeks.org/deque-cpp-stl/)  
**Double ended queues, they are sequence containers with feature of expansion and contraction at both ends.**  
This makes them faster and more efficient than vectors or queues.  
*DEQUE IS VERY SIMILAR TO VECTOR, with added functionality of front and back both.*

`push_back()` will add data to the end of deque.  
`push_front()` adds data to the front.  
`front()` and `back()` are usual.  
`pop_back()` wil remove last element of deque.  
`pop_front()` analogous.  
`insert()`, `assign()`, `erase()`, `empty()`, `size()` work same as in vector.  
`at(int __n)` *returns reference to element present index __n.*

`std::find(iterator __first, iterator __last, const _CharT & _val)` *will find if the _val occurs in range [__first, __last) and returns an iterator to the first occrence. If no occurence is found, then __last is returned.*

## PRIORITY QUEUE

[GFG Priority Queue](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/)  
It is a type of container adaptor, designed such that the **first element of the queue is the greatest of all and subsequent elements are in non increasing order (priority of elements is fixed, so to speak)**.  
`push()` will add data to the queue.  
`top()` returns read only reference to the first element of the queue.  

`<typename _Tp, typename _Sequence = vector < _Tp >, typename _Compare = less < typename _Sequence :: value_type >> priority_queue`  
**is a queue with elements of type _Tp, sequenced in fashion similar to _Sequence (defaulted to vector of that datatype), and a compare function _Compare to decide priority (defaulted to less). This by default creates a descending queue.**  
Compare function takes `(val1, val2)`.  
Define a custom struct, overload `()` operator to return true if `(val1, val2)` need to interchanged, otherwise false.

## Templates

`std::greater<int>` is an example of a template function.  
[GFG Templates](https://www.geeksforgeeks.org/templates-cpp/)  
Basically templates are like

```cpp
template <typename T> return_type func(T a, T b, ...){
    // some code 
}
```

this function works on variety of datatypes. eg `func<int>` will mean this is expanded at compiler time, and compiler checks type. (a bit diff from macros)  
Class templates, like function templates are useful to define classes of similar nature, differing only in typenames.

```cpp
template <typename T> class Array {
    private:
        T* ptr;
        int size;
    public:
        Array(T arr[], int s);
        void print();
};
```

```cpp
template <typename T> Array<T>::Array(T arr[], int s){
    ptr = new T [s];
    size = s;
    for (int i=0; i<s; i+=1){
        ptr[i] = arr[i];
    }
}
```

```cpp
template <typename T> Array<T>::print(){
    for (int i=0; i<s; i+=1){
        cout<<*(ptr+i)<<" ";
    }
    cout<<endl;
}
```

```cpp
template <class T, class U> class A{
    T x;
    U y;
public:
    A(){
        cout<<"Constructor called\n";
    }
};
```

typename and class can be used interchangeably in function definition parameter listing.  
Templates are used when multiple functions/classes do same.  
`empty()`, `size()`, `pop()` work the same.

## PAIR, MAP, SET

[CPP STL](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/)  
[Unordered Map GFG](https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/)  
Maps are associative containers that store elements in a mapped, ie key-value fashion.  
Keys are unique.

Constructor -  
`<typename _Key, typename _Tp, typename _Compare = std :: less < _Key >, typename _Alloc = std :: allocator < std :: pair < const _Key, _Tp > >> map`  
Arguments are type of key, type of value, a compare function (defaulted to less), an allocator.

## Allocator

Allocators are objects responsible for encapsulating memory management.   std::allocator is used when you want to do construction and allocation in 2 different steps.  
The default allocator specified below only uses new and delete to obtain and release memory.  

```cpp
template <class T> class allocator; 
allocator<int> myAlloc
int *arr = myAlloc.allocate(5); //allocates 5 ints worth of memory to arr.
myAlloc.deallocate(arr, 5); //5 ints worth of space freed.
```

Allocator can be used when allocation and deallcation of elements is desired to be separated from their construction and destruction.  
[GFG Allocator](https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/)  
Also see - [CPP Reference](https://en.cppreference.com)

Back to map  
`begin()`==iterator, points to first element  
`end()`==iterator, points to AFTER the last element  
`size()`, `empty()`, `erase(__iterator)`, `erase(const g)`==void, removes element with key g, `clear();`  
`insert()` parameters are

1. `__list`
2. `Pair &_p`
3. `std::Pair<int, int> &_p`
4. `iterator __it1, iterator __it2`
5. `iterator __position, Pair &_p`

`count(g)`==bool, checks if key with value g is present in map  
`find(g)`==iterator, to the element with key 'g', otherwise `end()`  
`map::operator[]` returns direct reference to element at key g.  
`std::pair<int, int>::first` and `pii::second` are copies of first and second objects.

## OPERATORS

[GFG Operators](https://www.geeksforgeeks.org/operators-c-c/)  
[GFG Bitwise Operators](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)  
Unary operators ++, -- opearate on single operand.

## Bitwise operators

Operands converted to bit-level and then operations performed on them.  

### Bitwise `AND, &`

performs AND on every bit of these operands, and returns 1 if both bits are 1, else 0.

### Bitwise `OR, |`

performs OR on every bit of the 2 numbers.

### Bitwise `XOR, ^`

performs XOR on each bit. returns 1 if different bits, else 0.  

### Bitwise `left shift, <<`  

shifts bits of operand1 to the left, operand2 decides no. of bits to shift.  
Similarly `right shift, >>` shifts bits of `__left` by `__right`.  

### Bitwise `NOT ~`

will invert bits of the number.  

> `XOR` is very important for questions. Do those on [here](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/) for practice.
