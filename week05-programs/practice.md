Great idea. Since you're strengthening your **C fundamentals**, these problems focus on things that actually show up in real C codebases: memory layout, pointer behavior, and iteration.

Try to **predict the answer before running the code**. That’s where the learning really happens.

---

# Problem 1 — Basic Array Access

What does this print? - 30 (the 3rd element)

```c
#include <stdio.h>

int main()
{
    int arr[4] = {10, 20, 30, 40};

    printf("%d\n", arr[2]);

    return 0;
}
```

Questions:

* What value prints? 30
* Why? [2] references the 3rd element. First element starts at [0]

---

# Problem 2 — Pointer Arithmetic

What does this print? 15 the third address

```c
#include <stdio.h>

int main()
{
    int arr[3] = {5, 10, 15};

    int *ptr = arr;

    printf("%d\n", *(ptr + 2));

    return 0;
}
```

Questions:

* What does `ptr` point to? the address of the first element [0]
* What does `*(ptr + 2)` access? the value at the third address

---

# Problem 3 — Array Name vs Address

What does this print? the address of element [0] both times

```c
#include <stdio.h>

int main()
{
    int arr[3] = {1,2,3};

    printf("%p\n", arr);
    printf("%p\n", &arr[0]);

    return 0;
}
```

Questions:

* Are the two addresses the same? yes 
* Why or why not? Because they are the same thing. We are looking at the starting point or the first element

---

# Problem 4 — Array Size Trick

What does this print? 5 - the size of the array 

```c
#include <stdio.h>

int main()
{
    int arr[5] = {1,2,3,4,5};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", size);

    return 0;
}
```

Questions:

* What number prints? 5
* Why does this trick work? because arrays are all the same type, so we can do sizeof math to determine the length

---

# Problem 5 — Array Passed to Function

What does this print? the size of an array if it were a fully saved array and then the size of the address of an array. 

```c
#include <stdio.h>

void printSize(int arr[])
{
    printf("%lu\n", sizeof(arr));
}

int main()
{
    int arr[10];

    printf("%lu\n", sizeof(arr));

    printSize(arr);

    return 0;
}
```

Questions:

* What prints on line 1? 40
* What prints on line 2? 8
* Why are they different? One is an int[] and the other is int* (warning is produced on compiling)

---

# Problem 6 — Off-by-One Bug

Is this correct code? No 

```c
#include <stdio.h>

int main()
{
    int arr[5] = {0};

    for(int i = 0; i <= 5; i++)
    {
        arr[i] = i;
    }

    return 0;
}
```

Questions:

* Is this safe? No, it can overwrite existing elements
* What bug is present? 2 reasons <= 5 AND we don't use sizeof() 

This is one of the **most common bugs in C systems code**.

---

# Problem 7 — Memory Layout

What prints?

```c
#include <stdio.h>

int main()
{
    int arr[3] = {10,20,30};

    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr[2]);

    return 0;
}
```

Question:

* How far apart are the addresses? the sizeof an int value on your system

Hint:

```
sizeof(int)
```

---

# Problem 8 — Pointer vs Array Indexing

What prints?

```c
#include <stdio.h>

int main()
{
    int arr[4] = {1,2,3,4};

    printf("%d\n", *(arr + 3));
    printf("%d\n", arr[3]);

    return 0;
}
```

Question:

* Are these equivalent? Yes BECAUSE one is the pointer arithmetic to get that value while teh other is the version we generally expect to see

---

# Problem 9 — Modify Array in Function

What prints? 99 - this allows you to modify the original array

```c
#include <stdio.h>

void change(int arr[])
{
    arr[1] = 99;
}

int main()
{
    int arr[3] = {1,2,3};

    change(arr);

    printf("%d\n", arr[1]);

    return 0;
}
```

Question:

* Why does the value change? Because it is an int* so we can access based on address, so they are pointing at the same memory 

---

# Problem 10 — String as Array

What prints?

```c
#include <stdio.h>

int main()
{
    char name[] = "Hi";

    printf("%c\n", name[1]);
    printf("%d\n", name[2]);

    return 0;
}
```

Questions:

* What character prints first? "i"
* What number prints secondA? null terminator '\0'
* Why? because all "strings" or char arrays need a null terminator at the end 

Hint:

```
\0
```

---

# If you want a **real C mastery challenge**, try this one:

What does this print?

```c
#include <stdio.h>

int main()
{
    int arr[5] = {10,20,30,40,50};

    int *p = arr;

    p++;

    printf("%d\n", *p);

    return 0;
}
```

This would print: 

20 pointer and array arithmetic 

---

If you'd like, I can also show you **5 harder array/pointer puzzles** that senior C developers often struggle with (they make pointer arithmetic *really* click).
