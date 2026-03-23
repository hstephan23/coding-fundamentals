Love this direction — this is exactly how you *really* internalize pointers.

**Instructions:**

* Try to predict the output *before* running
* Then check your reasoning
* Focus on **what lives where in memory**

---

# 🧠 Pointer Practice Set (10 Problems)

---

## ✅ Problem 1 — Basic Dereference

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int *p = &x;

    printf("%d\n", *p);

    return 0;
}
```

**Questions:**

* What prints? - 10
* What does `*p` represent? - the value stored at the address in `p`

---

## ✅ Problem 2 — Modify Through Pointer

```c
#include <stdio.h>

int main()
{
    int x = 5;
    int *p = &x;

    *p = 20;

    printf("%d\n", x);

    return 0;
}
```

**Questions:**

* What prints? - 20
* Why does `x` change? - `x` changes because the pointer can access the value of the memory and update it

---

## ✅ Problem 3 — Pointer Copy

```c
#include <stdio.h>

int main()
{
    int x = 7;
    int *p1 = &x;
    int *p2 = p1;

    *p2 = 15;

    printf("%d\n", x);

    return 0;
}
```

**Questions:**

* What prints? - 15
* Do `p1` and `p2` point to the same place? - Yes, `p1` points to `x` and `p2` points to `p1` which points to `x`

---

## ✅ Problem 4 — Address vs Value

```c
#include <stdio.h>

int main()
{
    int x = 42;
    int *p = &x;

    printf("%p\n", p);
    printf("%d\n", *p);

    return 0;
}
```

**Questions:**

* What does each line print conceptually? - the memory address of `x` and then 42
* Which is the address? Which is the value? - `p` is the memory address and `*p` is the value

---

## ✅ Problem 5 — Pointer Reassignment

```c
#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;

    int *p = &a;
    p = &b;

    *p = 10;

    printf("%d %d\n", a, b);

    return 0;
}
```

**Questions:**

* What prints? 1 and 10
* Which variable gets modified? the pointer value is updated from `a` memory address to `b` memory address AND the value for `b` is updated

---

## ✅ Problem 6 — Pointer to Pointer

```c
#include <stdio.h>

int main()
{
    int x = 3;
    int *p = &x;
    int **pp = &p;

    **pp = 9;

    printf("%d\n", x);

    return 0;
}
```

**Questions:**

* What prints? - 9
* What does `**pp` mean? a double dereferencing that allows us to get it to the value of another value 
this is really just a way to access the value pointed to by another pointer  

---

## ✅ Problem 7 — Array + Pointer

```c
#include <stdio.h>

int main()
{
    int arr[3] = {10, 20, 30};
    int *p = arr;

    printf("%d\n", *(p + 1));

    return 0;
}
```

**Questions:**

* What prints? 20
* Why is `p + 1` valid? it is pointer arithmetic. `*p` is really `arr[0]`

---

## ✅ Problem 8 — Increment Value vs Pointer

```c
#include <stdio.h>

int main()
{
    int x = 5;
    int *p = &x;

    (*p)++;
    p++;

    printf("%d\n", x);

    return 0;
}
```

**Questions:**

* What prints? 6
* What does `p++` do here (even if unsafe)? increases it by one `sizeof(int)` address (It depends on the system for the number of bytes)


---

## ✅ Problem 9 — Two Variables, One Memory

```c
#include <stdio.h>

int main()
{
    int x = 8;
    int *p = &x;

    int y = *p;
    y = 20;

    printf("%d %d\n", x, y);

    return 0;
}
```

**Questions:**

* What prints? 8 20
* Why doesn’t `x` change? `y` is not a pointer, so it doesn't access the value of `x`, it is just set equal to the value of `x`

---

## ✅ Problem 10 — Pointer Lifetime (Important ⚠️)

```c
#include <stdio.h>

int* getPtr()
{
    int x = 50;
    return &x;
}

int main()
{
    int *p = getPtr();

    printf("%d\n", *p);

    return 0;
}
```

**Questions:**

* What happens here? unexpected behavior can occur, but 50 was printed with a warning. 
* Is this valid or dangerous? DANGEROUS

---

# 🚀 How to Use These

I recommend:

1. Answer 3–4 at a time
2. Send me your answers
3. I’ll:

    * Correct them
    * Draw memory diagrams
    * Point out mistakes (this is where growth happens)

---

If you want next level after this:
👉 I can generate **“real-world style” pointer bugs** (the kind you’ll actually debug at work)
