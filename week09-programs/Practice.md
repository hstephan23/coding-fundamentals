Love this direction — this is *exactly* the kind of practice that will level up your “understand the machine” goal.

I’ll give you **pure C-focused practice problems** around:

* code quality
* memory
* architecture (at a C level)
* structs & modular design
* maintainability

👉 **No answers included**, just like you asked.

---

# 🧠 C Code Quality & Architecture Practice

## 1. Refactor Responsibility

You’re given this:

```c++
void process_user(char *username, int age) {
    if (age < 18) {
        printf("User too young\n");
        return;
    }

    FILE *f = fopen("users.txt", "a");
    fprintf(f, "%s %d\n", username, age);
    fclose(f);

    printf("User saved!\n");
}
```

```c++ 
// refactored version

#include <stdio.h>

int check_age(int age);
void read_file(char* username, int age);

// doing this feels a little forced, but I think it is the third recommended piece
void print_message(void);

void process_user(char *username, int age) {
    if (!check_age(age)) return;

    read_file(username, age);

    print_message();
}

int check_age(int age)
{
    if (age < 18) return 0;

    return 1;
}

void read_file(char* username, int age)
{
    FILE *f = fopen("users.txt", "a");
    fprintf(f, "%s %d\n", username, age);
    fclose(f);
}
void print_message(void)
{
    printf("User saved!\n");
}
```

### Your task:

* Identify **at least 3 responsibilities**
* Refactor into separate functions
* Think: what should each function *own*? → check_age, read_file, print_message

---

## 2. Fix Memory Issues

```c++
char* create_message() {
    char msg[50];
    strcpy(msg, "Hello world");
    return msg;
}
```

```c++ 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void create_message(char* msg) {
    strcpy(msg, "Hello world");
}

int main(void)
{
    char* message = malloc(25 * sizeof(char));
    create_message(message);
    printf("%s \n", message);
    free(message);
    return 0;
}
```

### Your task:

* Explain what’s wrong → we are accessing memory through passing it. This causes failures becuase the memoryt could be overwritten by something else 
* Fix it **without leaking memory**
* Provide two different correct approaches

---

## 3. Improve Struct Design

```c++
typedef struct {
    char name[50];
    int health;
    int x;
    int y;
    int score;
    int level;
    int coins;
} Player;
```

```c++ 
typedef struct
{
    int score;
    int coins;
} Points;

typedef struct
{
    Player player;
    Points points;
    int level;
} Game;
```

### Your task:

* Break this into **better structured components**
* Improve cohesion
* Keep it practical (not over-engineered)

---

## 4. Reduce Coupling

```c++
void save_score(int score) {
    FILE *f = fopen("scores.txt", "a");
    fprintf(f, "%d\n", score);
    fclose(f);
}
```

```c++ 
void save_data(int data, char* file_name) {
    FILE *f = fopen(file_name, "a");
    fprintf(f, "%d\n", data);
    fclose(f);
}
```
### Your task:

* Refactor so this function is **less tightly coupled to file system details**
* Think: how could this be reused for other outputs?

---

## 5. Eliminate Repetition

```c++
void move_up(int *y) { *y = *y - 1; }
void move_down(int *y) { *y = *y + 1; }
void move_left(int *x) { *x = *x - 1; }
void move_right(int *x) { *x = *x + 1; }
```

```c++
void move(int* axis, int direction)
{
    *axis = *axis + direction;
}
```

### Your task:

* Replace with a more scalable design
* Support adding diagonals later
* Keep it clean and readable

---

## 6. Improve Error Handling

```c++
FILE *f = fopen("data.txt", "r");
char buffer[100];
fgets(buffer, 100, f);
printf("%s", buffer);
fclose(f);
```

```c++
#include <stdio.h>
int main(void)
{
    FILE *f = fopen("data.txt", "r");
    if (!f)
    {
        printf("Failure to fetch file");
        return 0;
    }
    char buffer[100];

    if (fgets(buffer, 100, f))
    {
        printf("Failure to read data");
        return 0;
    }
    printf("%s", buffer);
    if (!fclose(f))
    {
        printf("failure to close file");
        return 0;
    }

    return 0;
}
```

### Your task:

* Make this **robust**
* Handle all realistic failure cases
* Keep it clean (not just defensive spam)


## 7. Fix Hidden Bug (Pointer + Ownership)

```c++
char* get_username() {
    char *name = malloc(50);
    strcpy(name, "Harrison");
    return name;
}

void print_user() {
    char *user = get_username();
    printf("%s\n", user);
}
```

```c++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_username(char* username) {
    strcpy(username, "Harrison");
}

void print_user(char* username) {
    printf("%s\n", username);
}

int main(void)
{
    char *username = malloc(50 * sizeof(char));
    get_username(username);
    print_user(username);
    return 0;
}
```

### Your task:

* Identify the **design problem (not just memory leak)** Passing it that can result in undefined behavior
* Fix it in a way that makes ownership clear. defining the user and print user in a different function might look better. something like that ^^

---

## 8. Improve API Design

```c++
void update_player(int *x, int *y, int *health, int *score);
```

```c++
typedef struct
{
    int x;
    int y;
} Position;

typedef struct
{
    int health;
    int score;
} Player;

void update_player(Position* position, Player* player);
```

### Your task:

* Redesign this function signature
* Make it easier to use correctly
* Think about **readability + safety**

---

## 9. Replace Conditionals with Better Design

```c++
void handle_input(char input, int *x, int *y) {
    if (input == 'w') (*y)--;
    else if (input == 's') (*y)++;
    else if (input == 'a') (*x)--;
    else if (input == 'd') (*x)++;
}
```

```c++
typedef Struct {
    int dx;
    int dy;
} Direction;

Direction get_direction(char input)
{
    switch (input)
    {
        case 'w': return (Direction){0, -1};
        case 's': return (Direction){0, 1};
        case 'a': return (Direction){-1, 0};
        case 'd': return (Direction){1, 0};
        default: return (Direction){0, 0};
    }
}
```

### Your task:

* Refactor into a more extensible design
* Make adding new controls easier
* Avoid giant `if/else` chains

---

## 10-. Detect Buffer Risk

```c++
void copy_name(char *dest, char *src) {
    strcpy(dest, src);
}
```

```c++
#include <stddef.h>
#include <string.h>

int copy_name(char *dest, size_t dest_size, char *src) {
    if (dest == NULL || src == NULL || dest_size == 0)
    {
        return 0;
    }
    
    size_t src_len = strlen(src);
    if (src_len >= dest_size)
    {
        return 0;
    }
    
    // Need null terminatorrrrr
    memcpy(dest, src, src_len + 1);
    return 1; 
}
```

### Your task:

* Identify the risk → if src is longer than dest, buffer overflow....
* Redesign the function safely
* Keep performance in mind

---

## 11. Data vs Behavior

You have:

```c++
typedef struct {
    int x;
    int y;
} Position;
```

```c++
void move(Position *pos, int dx, int dy)
{
    if (pos == NULL)
    {
        return;   
    }
    pos->x += dx;
    pos->y += dy;
}

int position_equal(Position a, Position b)
{
    return a.x == b.x && a.y == b.y;
}
```

### Your task:

* Add **useful operations** around this struct
* Think like: what behavior *belongs* here?
* Avoid turning it into a “dumb data bag”

---

## 12. Testability in C

```c++
int get_random_damage() {
    return rand() % 10;
}
```

```c++
int get_damage(int damage)
{
    return damage % 10;
    
}

```

### Your task:

* Refactor so this is **testable**
* You should be able to control output in tests

---

## 13. Performance vs Readability

```c++
for (int i = 0; i < strlen(str); i++) {
    printf("%c\n", str[i]);
}
```

```c++ 
size_t length = strlen(str);

for (size_t i = 0; i < length; i++)
{
    printf("%c\n", str[i]);
}
```

### Your task:

* Identify the issue
* Improve it without hurting readability

---