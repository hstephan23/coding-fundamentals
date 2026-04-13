# Week 09 - Code Quality & Architecture

## Learning Goals 

- Separation of concerns 
- Header vs source files 

### Mental Model 

Good code is organized code.

#### Prompts 

- Who depends on whom?

    main.c depends upon math_utils.h. math_utils.c depends upon math_utils.h
    Meaning that the contract is established through math_utils.h
    This is important as dependencies flow in one direction

- Why is this split into files? 
        
    Better readability, especially as the program grows.

- What would cause a circular dependency? 

    If B depends on A, and A depends upon B