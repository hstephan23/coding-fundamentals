# Week 08 - Algorithms (Thinking First) 

## Learning Goals 

- Step-by-step problem solving 
- Correctness before speed

### Mental Model 

Algorithms are recipes

#### Prompts 

- What is the simplest correct solution? 
 
Claude said: "It is the solution"

ChatGPT said: "You have the simplest solution"

== SUCCESS 

- What steps does the computer take? 

lots...

Allocate in memory the array values

Set the value of size in memory

set the min value in memory 

loop iteration by iteration starting with the first two values of the array 

It compares the two values 

If it is lower, it updates. If not, continue onwards. 

Then finally, print it out and return 0

Here is the God Bolt piece: 

```GCC 
.LC0:
        .string "value: %d\n"
main:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $32, %rsp
        movl    $3, -32(%rbp)
        movl    $1, -28(%rbp)
        movl    $4, -24(%rbp)
        movl    $1, -20(%rbp)
        movl    $5, -16(%rbp)
        movl    $5, -12(%rbp)
        movl    -32(%rbp), %eax
        movl    %eax, -4(%rbp)
        movl    $1, -8(%rbp)
        jmp     .L2
.L4:
        movl    -8(%rbp), %eax
        cltq
        movl    -32(%rbp,%rax,4), %eax
        cmpl    %eax, -4(%rbp)
        jle     .L3
        movl    -8(%rbp), %eax
        cltq
        movl    -32(%rbp,%rax,4), %eax
        movl    %eax, -4(%rbp)
.L3:
        addl    $1, -8(%rbp)
.L2:
        movl    -8(%rbp), %eax
        cmpl    -12(%rbp), %eax
        jl      .L4
        movl    -4(%rbp), %eax
        movl    %eax, %esi
        movl    $.LC0, %edi
        movl    $0, %eax
        call    printf
        movl    $0, %eax
        leave
        ret
```

- How does runtime grow as input grows?

It is O(n) so linearly 