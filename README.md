# push_swap  (≈චᆽච≈)

`push_swap` is a sorting algorithm project in C that challenges you to sort data on a stack using only a limited set of operations.  
The goal is to **sort numbers efficiently** while using as few operations as possible..and trust me, it gets tricky when the stack is big!
my approach was sorting 5 and less elements hardcoded simply, and for >6 elements i used RADIX sort algorithm
---

## How it works

- You have **two stacks**, `A` and `B`.  
- You’re only allowed a **limited set of operations**:
  - `sa` / `sb` — swap the top two elements of a stack  
  - `pa` / `pb` — push the top element from one stack to another  
  - `ra` / `rb` — rotate a stack upwards  
  - `rra` / `rrb` — rotate a stack downwards  
- The challenge is to use these operations to **sort all numbers in ascending order** on stack `A`.  
- The program must handle **any number of integers**, from a tiny stack to hundreds of numbers, and do it **with the fewest moves possible**.

---

## Installation / Build

Clone the repo and build it with `make`:

```bash
git clone https://github.com/YOUR_USERNAME/push_swap.git
```
```bash
make
```
## checking output?
you can check if the number of operations used is as few as required by a program called **checker**
the checker checks 
cd push_swap
make
