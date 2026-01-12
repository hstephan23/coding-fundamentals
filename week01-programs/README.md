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