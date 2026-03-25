/*
 Week 07 – Structs
*/

#include <stdio.h>

struct Player {
    int x;
    int y;
    int health;
};

int main(void) {
    struct Player player = {0};

    player.x = 10;
    player.y = 10;
    player.health = 5;

    printf("Player data: \n"
           "-------------\n"
           "Player position: (%d, %d)\n"
           "Player health: %d\n\n", player.x, player.y, player.health);

    player.x--;
    player.y--;
    player.health--;

    printf("Player data: \n"
           "-------------\n"
           "Player position: (%d, %d)\n"
           "Player health: %d\n\n", player.x, player.y, player.health);
    // TODO:
    // 1. Initialize
    // 2. Modify
    // 3. Explain grouping

    // grouping is a way to allow you to control and scope variables together.
    // It allows you to be able to change things easier
    // It allows for better traccking and visibility too of variables

    return 0;
}
