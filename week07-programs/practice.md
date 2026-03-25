Absolutely—I love this direction. Structs are where things start to feel like “real programs,” especially for your game work.

We’ll do this the same way as before:
👉 **predict first**, then verify
👉 mix of **memory understanding + real usage**

---

# 🧠 Struct Practice Problems

---

## ✅ Problem 1 — Basic Access

What prints?

```c
#include <stdio.h>

struct Player {
    int x;
    int y;
};

int main() {
    struct Player p = {3, 7};

    printf("%d\n", p.x);

    return 0;
}
```

**Questions:**

* What prints? 3
* Why? It prints 3, because when you define a struct like that, it is in the order that you declared the struct

---

## ✅ Problem 2 — Modify Through Struct

```c
#include <stdio.h>

struct Player {
    int health;
};

int main() {
    struct Player p = {10};

    p.health -= 3;

    printf("%d\n", p.health);

    return 0;
}
```

**Questions:**

* What prints? 7
* What happened to the value? It was decremented by 3

---

## ✅ Problem 3 — Copy vs Reference (IMPORTANT ⚠️)

```c
#include <stdio.h>

struct Player {
    int health;
};

int main() {
    struct Player p1 = {10};
    struct Player p2 = p1;

    p2.health = 20;

    printf("%d %d\n", p1.health, p2.health);

    return 0;
}
```

**Questions:**

* What prints? 10 20
* Why doesn’t changing `p2` affect `p1`? because it is a copy of it, not a reference for it

---

## ✅ Problem 4 — Pointer to Struct

```c
#include <stdio.h>

struct Player {
    int health;
};

int main() {
    struct Player p = {10};
    struct Player *ptr = &p;

    ptr->health += 5;

    printf("%d\n", p.health);

    return 0;
}
```

**Questions:**

* What prints? 15
* What does `->` mean? It is the arrow operator, it dereferences and accesses the member

---

## ✅ Problem 5 — Struct in Function (Copy!)

```c
#include <stdio.h>

struct Player {
    int health;
};

void damage(struct Player p) {
    p.health -= 5;
}

int main() {
    struct Player p = {20};

    damage(p);

    printf("%d\n", p.health);

    return 0;
}
```

**Questions:**

* What prints? 20
* Why didn’t the original change? It is a copy, not a reference of the thing (we need a pointer)

---

## ✅ Problem 6 — Struct Pointer in Function (REAL WORLD)

```c
#include <stdio.h>

struct Player {
    int health;
};

void damage(struct Player *p) {
    p->health -= 5;
}

int main() {
    struct Player p = {20};

    damage(&p);

    printf("%d\n", p.health);

    return 0;
}
```

**Questions:**

* What prints? 15
* Why does this one work? the pointer is a reference, meaning it can access and update the data. It accesses the data 
stored at a specific memory location not just the copy 

---

## ✅ Problem 7 — Nested Structs (Game-style)

```c
#include <stdio.h>

struct Position {
    int x;
    int y;
};

struct Player {
    struct Position pos;
    int health;
};

int main() {
    struct Player p = {{2, 3}, 10};

    p.pos.x += 5;

    printf("%d %d\n", p.pos.x, p.pos.y);

    return 0;
}
```

**Questions:**

* What prints? 7 3
* How is the memory structured? a single, contiguous block of memory 

---

## ✅ Problem 8 — Array of Structs

```c
#include <stdio.h>

struct Player {
    int health;
};

int main() {
    struct Player players[2] = {{10}, {20}};

    players[0].health += 5;

    printf("%d %d\n", players[0].health, players[1].health);

    return 0;
}
```

**Questions:**

* What prints? 15 20 
* Why only one changed? we only accessed one of the values the value in the first position

---

## ✅ Problem 9 — Pointer Arithmetic with Structs ⚠️

```c
#include <stdio.h>

struct Player {
    int health;
};

int main() {
    struct Player players[2] = {{10}, {20}};
    struct Player *p = players;

    (p + 1)->health = 50;

    printf("%d %d\n", players[0].health, players[1].health);

    return 0;
}
```

**Questions:**

* What prints? 10 50
* What does `(p + 1)` mean? it takes the first position and increases it by one

---

## ✅ Problem 10 — Struct Memory Thinking (Advanced)

```c
#include <stdio.h>

struct Data {
    int a;
    int b;
};

int main() {
    struct Data d = {1, 2};

    int *ptr = (int*)&d;

    printf("%d %d\n", ptr[0], ptr[1]);

    return 0;
}
```

**Questions:**

* What prints? 1 2
* Why does this work? through casting and forcing it to be an int
* When could this be dangerous? casting is always risky if you aren't entirely certain of the data that you are dealing with 

---

# 🚀 How to use these (important)

Don’t just run them.

For each one:

1. Predict output
2. Explain *why*
3. Then run it

---

# 👍 If you want next step

We can level this up into:

👉 **Game-style struct exercises**

* moving entities
* collision systems
* modifying GameState through functions

That would map *directly* to your current project.

Just say:

> “next level”

and I’ll build those for you 🔥
