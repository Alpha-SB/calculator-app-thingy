# calculator-app-thingy

Simple console calculator that handles decimal numbers. Start with an initial value, chain additions, subtractions, multiplications, divisions, or modulo operations, and quit anytime by choosing `q`.

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -o calculator Calculator.cpp
./calculator
```

Follow the prompts: enter the first number, pick an operator, enter the next number, and the updated result prints immediately. Press `q` when choosing an operator to exit.
