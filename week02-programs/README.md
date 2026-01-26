# Week 02 - Variables & Data

## Learning Goals 

- Variables represent memory 
- Types exist for a reason 
- Data changes over time 

### Mental Model 

Variables are labeled boxes in memory

#### Prompts

- Where does this value live?
    Automatic → Stack (so I am assuming non-dynamically allocated memory?)
    Allocated (dynamic) → Heap (So Variables that rely upon malloc/calloc)
- What happens if I change this value twice?
    It depends on the type of variable, but it would just cause the memory to be overwritten? Right? Let me look at that. 
    Update→ it depends on the language! C would just overwrite the language, but other languages just allocate new memory to it (like javascript)
    Frequent changes can lower performance, but when accessing the value, you would get the latest version of it. 

- Why does type matter
    Type matters because of the amount of data stored (bytes and bits) for each type of variable. This means that int, double, and float all should be used at the correct times or else you are wasting space. 

#### Comments

- How many bits/bytes is an int variable type (what is the standard)?

    Two bytes is the minimum, while four bytes is more common with modern systems. Compiler dependent.

    Not really a standard :( https://www.tutorialspoint.com/cprogramming/c_data_types.htm 

- What does your machine know about compiling (the idea of what determines the sizes)?

    https://www.tutorialspoint.com/cprogramming/c_data_types.htm – Interesting Topic 

    https://en.wikipedia.org/wiki/Sizeof – I didn't realize why we use sizeof(int) (or something like that) 

    Compiler is dependent upon the operating system AND the language standard requirements. 
    Compilers have a built-in mapping for basic types. Compiler is used when doing sizeof() operations.
    This is because it results in consistent data sizes. It depends also on the processor's ability to access that type.

    https://stackoverflow.com/questions/56156513/what-defines-the-size-of-a-type

- If you have something on the stack in a function, does it just disappear?

    "Stack unwinding" → It marks it as "free," which allows it to be used for something else. However, the value doesn't
    disappear. It can be overwritten when the function is over.

    Something interesting here is the idea that if we aren't careful with it, we _may_ see a valid attempt, but it would
    be unpredictable. Is that what happens when you have unexpected behavior? 

    "It is considered a good practice to set a pointer to NULL after freeing memory so that you cannot accidentally   continue using it.
    If you continue using memory after it has been freed you may corrupt data from other programs or even another part of your own program."

    https://www.w3schools.com/c/c_memory_deallocate.php

- If something went on the stack and the function is over, does it persist? (STACK SPECIFIC)
    
    Same as above ^^^ These were really the same questions. 

- Stack vs heap (dig deeper)? Is the stack contiguous?

    Stack is contiguous, but the heap does not need to be. 

    Stack is automatically allocated and cleaned, but the heap is done manually or through a garbage collector. 

    Stack is faster since it is contiguous.

    Stack has a limit, while heap can expand or shrink.

  https://andresantarosa.medium.com/heap-stack-e-garbage-collector-a-practical-guide-to-net-memory-management-system-7e60bbadf199

- Is this true "Frequent changes can lower performance, but when accessing the value, you would get the latest version of it."???

    This is a NO, not generally found in modern computing languages. 