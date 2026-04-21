#ifndef LEDGER_H
#define LEDGER_H

#define MAX_TRANSACTIONS 100
#define MAX_NOTE_LEN 32

// Amounts are stored in cents to avoid floating-point surprises.
// Positive = deposit, negative = withdrawal.
struct Transaction {
  int amount_cents;
  char category[MAX_NOTE_LEN];
  char note[MAX_NOTE_LEN];
};

struct Ledger {
  struct Transaction transactions[MAX_TRANSACTIONS];
  int count;
};

// Lifecycle
void ledger_init(struct Ledger *ledger);
int  ledger_add(struct Ledger *ledger, int amount_cents,
                const char *category, const char *note);

// Queries
int  ledger_balance_cents(const struct Ledger *ledger);
void ledger_print(const struct Ledger *ledger);
void ledger_summary(const struct Ledger *ledger);  // totals per category

#endif
