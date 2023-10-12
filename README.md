# std-vector


Project for for for std::vector, also for pedagogy purposes.

# CMake
```bash
cmake -S . -B  build && cmake --build build -j 4 && cd build && ctest --output-on-failure && cd ..
```


## Implementation checklist

~ means partial

0 means none implemented

x means done

Checklist


- (constructor) (~)
    - constructs the vector (public member function)

- (destructor) (0)
    - destructs the vector (public member function)

- operator= (0)
    - assigns values to the container (public member function)

- assign (0)
    - assigns values to the container (public member function)

- assign_range (0) (C++23)
    - assigns a range of values to the container (public member function)

- get_allocator (0)
    - returns the associated allocator (public member function)

- at (x)
    - access specified element with bounds checking (public member function)

- operator[] (x)
    - access specified element (public member function)

- front (x)
    - access the first element (public member function)

- back (x)
    - access the last element (public member function)

- data (0)
    - direct access to the underlying array (public member function)

- begin (0)
    - returns an iterator to the beginning (public member function)

- cbegin (C++11) (0)
    - returns a constant iterator to the beginning (public member function)

- end (0)
    - returns an iterator to the end (public member function)

- cend (C++11) (0)
    - returns a constant iterator to the end (public member function)

- rbegin (0)
    - returns a reverse iterator to the beginning (public member function)

- crbegin (C++11) (0)
    - returns a constant reverse iterator to the beginning (public member function)

- rend (0)
    - returns a reverse iterator to the end (public member function)

- crend (C++11) (0)
    - returns a constant reverse iterator to the end (public member function)

- empty (0)
    - checks whether the container is empty (public member function)

- size (x)
    - returns the number of elements (public member function)

- max_size (0)
    - returns the maximum possible number of elements (public member function)

- reserve (0)
    - reserves storage (public member function)

- capacity (x)
    - returns the number of elements that can be held in currently allocated storage (public member function)

- shrink_to_fit (DR*) (0)
    - reduces memory usage by freeing unused memory (public member function)

- clear (0)
    - clears the contents (public member function)

- insert (0)
    - inserts elements (public member function)

- insert_range (0) (C++23)
    - inserts a range of elements (public member function)

- emplace (0) (C++11)
    - constructs an element in-place (public member function)

- erase (0)
    - erases elements (public member function)

- push_back (~)
    - adds an element to the end (public member function)

- emplace_back (0) (C++11)
    - constructs an element in-place at the end (public member function)

- append_range (0) (C++23)
    - adds a range of elements to the end (public member function)

- pop_back (0)
    - removes the last element (public member function)

- resize (0)
    - changes the number of elements stored (public member function)

- swap (0)
    - swaps the contents (public member function)