# The Standard Template Library
## Vectors and Memory `std::vector`
[Vector in C++ STL](https://www.geeksforgeeks.org/vector-in-cpp-stl/)

`size()` - Number of elements. **Resize** updates the vector size up or down

`capacity()` - Number of elements for which there is allocated memory. **Reserve** updates the vector capacity only up

**`vector` in Memory:**

The `vector` instance you have on the stack is a small object containing a pointer to a heap-allocated buffer, plus some extra variables to keep track of the size and and capacity of the vector. The heap-allocated buffer has a fixed capacity. When you reach the **end of the buffer, a new buffer will be allocated somewhere else on the heap** and all the previous elements will be moved into the new one. Their addresses will therefore change.

The storage is growing geometrically to ensure the requirement of the amortized O(1) `push_back()`. The growth factor is 2 (Capn+1 = Capn + Capn) in most implementations of the C++ Standard Library (GCC, Clang, STLPort) and 1.5 (Capn+1 = Capn + Capn / 2) in the MSVC variant.

## 2D Vectors `std::vector<std::vector<type>>`
[2D Vector In C++ With User Defined Size](https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/)

Like Matrixes.

---
## Lists `std::list`
[List in C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/list-cpp-stl/)

> Allow non-contiguous memory allocation

[Difference Between Vector and List](https://www.geeksforgeeks.org/difference-between-vector-and-list/)

---
## Maps `std::map`
[Map in C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/)
> Search mapped values through a key
> Use `std::pair` and `std::make_pair` to `insert()` elements.
## Custom Objects as map values `std::map<int,CObject>`
> Don't forget the Default Constructor, the Copy Constructor and the desired Constructor with input parameters 
## Custom Objects as map keys `std::map<CObject,int>`
> The same as above but now we need also an operator overload for `<` (`operator<`) because the map orders the elements by keys so we need to define how the map should order by the Object key.
> You can override the value but not the existing key.
## Multimap
[Multimap in C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/multimap-associative-containers-the-c-standard-template-library-stl/)

[Map vs Multimap in C++ STL](https://iq.opengenus.org/map-vs-multimap-cpp-stl/)

---
## Sets `std::sets`
[Set in C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/set-in-cpp-stl/)

Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it. The value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element. 
It does not create duplicates.

Expected Output:
```
5
10
40
50
Not Found.
Number Found
3: Joana
10: Joana
20: Miguel
50: Sara
```