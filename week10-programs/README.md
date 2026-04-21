# Week 10 - Capstone (Bank Ledger)

## Learning Goals

- Combine all prior concepts into one program
- Separate responsibilities across files
- Design a small but complete system

### Mental Model

A ledger is a list of changes. The balance is just their sum.

#### Prompts

- What does the state change over time?

The struct ledger contains the state change

- Which parts should live behind the header?

All the helper functions that would come from refactoring and pulling things out. 

- What would I refactor first?

I think the ledger_summary, it is pretty nasty and big. I don't love the nested loops.....