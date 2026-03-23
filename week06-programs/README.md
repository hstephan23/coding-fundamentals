# Week 06 - Memory (Conceptual)

## Learning Goals 

- Addresses vs values 
- Why pointers exist

### Mental Model 

Memory is real. Pointers point to it.

#### Prompts

- What is the difference between a value and an address?

    A value is the thing we want to represent, while an address points to the memory that holds that representation. 
    The what (value) vs the where (pointer) 

- Why can two variables refer to the same data? 

    You can have the value and then the pointer to that value. It doesn't matter because it is looking at different things. 
    One stores the data and the other stores the address of that data (pointer). 

- What does this pointer NOT own? 

    It does not own the data that it points to, just "points" to the memory address. 
