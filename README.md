# push_swap (≈චᆽච≈)

`push_swap` is a sorting algorithm project in C that challenges you to **sort data on a stack using only a limited set of operations**.  
The goal is to sort numbers efficiently while using as few operations as possible… and trust me, it gets tricky when the stack is big!  

**My approach:**  
- For **5 or fewer elements**, I used hardcoded sorting logic.  
- For **more than 5 elements**, I implemented the **Radix Sort** algorithm.  

---

## How it works

You have **two stacks, A and B**, and can only use the following operations:

- `sa` / `sb` — swap the top two elements of a stack  
- `pa` / `pb` — push the top element from one stack to another  
- `ra` / `rb` — rotate a stack upwards  
- `rra` / `rrb` — rotate a stack downwards  

The challenge is to use these operations to sort all numbers in **ascending order on stack A**.  
The program must handle any number of integers, from a tiny stack to hundreds, while using the **fewest moves possible**.  

---

## Installation / Build

Clone the repository and build it with `make`:

```bash
git clone https://github.com/yabuawad/push_swap.git
cd push_swap
make

## Usage
To sort a list of integers:
```bash
./push_swap 3 2 5 1 4

The program will output a sequence of operations to sort the stack in ascending order.
To verify the result, use the checker program:
```bash
./checker 3 2 5 1 4
You can also pipe the output of push_swap directly into checker:
```bash
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4

## Features
-Sorts numbers using a limited set of stack operations
-Handles small stacks (≤ 5 elements) with hardcoded logic
-Uses Radix Sort for larger stacks efficiently
-Works with any number of integers
-Written in C, focusing on memory management and system-level programming

## Notes / Tips
Test with large stacks to see how the number of operations scales!
Free memory properly after each operation to avoid leaks 
Optimizing for minimal moves is challenging… but so rewarding! 
License
This project is open-source and free to use.
Feel free to explore the code, learn from it, or contribute! 