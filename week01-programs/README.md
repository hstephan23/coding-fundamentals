# Week 01 - What is a Program? 

## Learning Goals 

- Understand what a program is
- Understand execution order
- Understand compile vs run 

### Mental Model 

A program is a list of instructions that the computer follows exactly

#### Prompts

- What is a program, really?

    A program is a set of instructions written for a computer to run and perform. 

- What happens between pressing ‘run’ and seeing output?

    If you try to press run, it won't do anything. You can configure that, but you need to compile it first locally (gcc main.c -o program) then you can run it. Compiling is essential for C. Once it has been compiled (turned into machine language), then you can run it (./program). The operating system then takes over and manages the interactions with CPU, I/O and memory. I found this good [article](https://medium.com/@karthikjeevann/what-actually-happens-when-you-run-a-program-caf8dbfdadf7) about what happens.

- Why does main exist?

   We need it for the entry of a C program. I once tried running a program without it. It wouldn't run and gave an error about needing one. C has particular syntax in place. 

   I think another reason is it lets us see the waterfall of files (once there is a bigger file tree). We can start with main where functions are called and then trickle down into other ones from there. 

#### Comments

    **Look at how malloc and calloc work** 
    -> what knows about memory??
        Malloc -> initializes garbage (use when immediately filling the memory with data)
        calloc -> initializes to 0 (slower, but not as much as it used to be)
        Allocated to the heap (dynamic memory) and stack (automatic memory), which stores the memory 
        Handled by the Operating System (specifically the memory manager)

    Look at PR's and understand what is being done, don't just look for typos 

    Just in time compiled -> what does that mean? 
        It means that the code isn't compiled until it is used. 

    Look at build times of asan (debug) vs release
        It can be faster, but I am confused. It mentions it being more optimized during release builds and less optimized during debugging. So I think my understanding of it being faster is wrong. I think it just depends on the project! 