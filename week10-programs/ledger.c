#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ledger.h"

void ledger_init(struct Ledger *ledger) {
  ledger->count = 0;
}

int ledger_add(struct Ledger *ledger, int amount_cents,
               const char *category, const char *note) {
    if (ledger->count >= MAX_TRANSACTIONS) return 0;

    ledger->transactions[ledger->count].amount_cents = amount_cents;

    strncpy(ledger->transactions[ledger->count].category, category, MAX_NOTE_LEN - 1);
    ledger->transactions[ledger->count].category[MAX_NOTE_LEN - 1] = '\0';

    strncpy(ledger->transactions[ledger->count].note, note, MAX_NOTE_LEN - 1);
    ledger->transactions[ledger->count].note[MAX_NOTE_LEN - 1] = '\0';

    ledger->count++;

    return 1;
}

int ledger_balance_cents(const struct Ledger *ledger) {
    int balance = 0;
    for (int i = 0; i < ledger->count; i++)
    {
        balance += ledger->transactions[i].amount_cents;
    }

    return balance;
}

void ledger_print(const struct Ledger *ledger) {
    for (int i = 0; i < ledger->count; i++)
    {
      printf("%d %s %s\n", ledger->transactions[i].amount_cents, ledger->transactions[i].category, ledger->transactions[i].note);
    }
}

void ledger_summary(const struct Ledger *ledger) {
    for (int i = 0; i < ledger->count; i++)
    {
        int already_printed = 0;
        int j = 0;
        while (j < i)
        {
            if (strcmp(ledger->transactions[i].category, ledger->transactions[j].category) == 0)
            {
                already_printed = 1;
                break;
            }
            j++;
        }

        if (already_printed == 1) continue;

        int sum = 0;
        for (int k = 0; k < ledger->count; k++)
        {
            if (strcmp(ledger->transactions[i].category, ledger->transactions[k].category) == 0)
            {
                sum += ledger->transactions[k].amount_cents;
            }
        }
        printf("%s: %d\n", ledger->transactions[i].category, sum);

    }
}
