/*
 Week 10 – Capstone (Bank Ledger)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ledger.h"

int main(void) {
    struct Ledger ledger;
    char* transaction = NULL;
    size_t transaction_size = 0;
    ssize_t n;

    ledger_init(&ledger);

    while (1)
    {
        fputs("Enter transaction (format: amount category description): ", stdout);

        fflush(stdout);

        n = getline(&transaction, &transaction_size, stdin);

        if (n == -1)
        {
            break;
        }

        if (strcmp(transaction, "quit\n") == 0)
        {
            free(transaction);
            return 0;
        }

        char* amount_str = strtok(transaction, " ");
        char* category_str = strtok(NULL, " ");
        char* description_str = strtok(NULL, "\n");

        if (!amount_str || !category_str || !description_str) {
            printf("Bad input — need: amount category description\n");
            continue;
        }

        int amount_cents = atoi(amount_str) * 100;


        ledger_add(&ledger, amount_cents, category_str, description_str);


        ledger_print(&ledger);
        int sum = ledger_balance_cents(&ledger);
        printf("Running balance: %d cents\n", sum);
        ledger_summary(&ledger);
    }
    free(transaction);
    free(ledger.transactions);
    return 0;
}
