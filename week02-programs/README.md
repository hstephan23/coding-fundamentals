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

- What does your machine know about compiling (the idea of what determines the sizes)?

- If you have something on the stack in a function, does it just disappear?

- If something went on the stack and the function is over, does it persist? (STACK SPECIFIC)

- Stack vs heap (dig deeper)? Is the stack contiguous?

- Is this true "Frequent changes can lower performance, but when accessing the value, you would get the latest version of it."???

- 