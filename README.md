*This project has been created as part of the 42 curriculum by mmolotko, msotnych.*

# push_swap

## Description

push_swap is a project about sorting. The program receives a list of integers and must output the shortest list of operations it can find to sort them. The catch is that the numbers are in two groups, `a` and
`b`, and the only way to move them is with a small set of 11 operations (swap,
push, rotate, reverse).

The goal of the project is to learn how different sorting algorithms behave, the subject asks for four strategies:

| Flag | Strategy | Complexity class | Algorithm used |
|---|---|---|---|
| `--simple` | Simple | O(n²) | selection sort |
| `--medium` | Medium | O(n√n) | chunk (bucket) sort |
| `--complex` | Complex | O(n log n) | binary radix sort (LSD) |
| `--adaptive` | Adaptive (default) | depends on the disorder | chooses one of the above |

The program also has a `--bench` mode, which prints sorting statistics (order, strategy, and count of each operation) to standard error.

The project complies with the 42 standard, does not use global variables, and is compiled with the `-Wall -Wextra -Werror` option. It is written in C and uses our own `libft` library and the `ft_printf` function.
## Instructions

### Compilation

Run these commands at the root of the repository:

```sh
make          # builds libft, ft_printf and the push_swap program
make clean    # removes object files
make fclean   # removes object files, the libraries and push_swap
make re       # fclean + all
```

### Usage

```sh
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <numbers>
```

- The first number is the **top** of stack `a`.
- Numbers can be given as separate arguments or inside one string: `./push_swap 3 2 1` and `./push_swap "3 2 1"` do the same.
- If no strategy flag is given, `--adaptive` is used.
- With no arguments the program prints nothing.
- If the numbers are already sorted, the program prints nothing.

Example:

```sh
$> ./push_swap 2 1 3
sa
```

### Errors

The program prints `Error` followed by a newline on the **standard error** when:

- an argument is not an integer (`1 2 a`, `1 2+`, `""`),
- a number is bigger than `INT_MAX` or smaller than `INT_MIN`,
- a number appears twice (`1 2 1`),
- a flag is unknown.

### Benchmark mode

With `--bench`, after sorting, the program prints on the standard error:

```
$> ./push_swap --bench 4 67 3 87 23 2> bench.txt | ./checker_linux 4 67 3 87 23
OK
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: adaptive / O(n)
[bench] total_ops: 11
[bench] sa: 0 sb: 0 ss: 0 pa: 3 pb: 3
[bench] ra: 4 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

The operations still go to the standard output, so the checker keeps working.

## The operations

A few basics:

- The **top** of a stack is the first element, the **bottom** is the last one.
- Every operation that really changes something is printed and counted. An operation that cannot do anything (for example `sa` with fewer than 2 elements) is not printed.

| Operation | What it does |
|---|---|
| `sa` / `sb` | swap the first two elements of `a` / `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | take the top of `b` and put it on top of `a` |
| `pb` | take the top of `a` and put it on top of `b` |
| `ra` / `rb` | rotate `a` / `b` up: the first element becomes the last |
| `rr` | `ra` and `rb` at the same time |
| `rra` / `rrb` | reverse rotate `a` / `b`: the last element becomes the first |
| `rrr` | `rra` and `rrb` at the same time |

## Technical choices

### Stacks as doubly linked lists

Each group is a **doubly linked list**: every node knows the next node
(`next`) and the previous one (`prew`). The stack itself keeps a pointer to the
`top`, a pointer to the `bottom` and its `size`.

```c
typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prew;
}	t_node;
```

Because we always know both ends of the list, every operation is **O(1)**:
rotating only moves the top node to the bottom (or back), and pushing only
moves one node from one list to the other. No array has to be shifted.

### One context structure

All the data of the program is kept in one structure, `t_data`: both stacks,
the disorder, the chosen strategy, the `--bench` flag and the 11 operation
counters. Every function gets a pointer to it, so there are no global variables
and the functions stay short (the Norm allows 4 parameters per function).

### The 4 primitives and the 11 operations

The actual work is performed by four small functions on a single stack: `swap`, `rotate`,
`rotate`, and `push_to_other`. The 11 operations (`sa`, `ra`, `pb`, ...) only
call these primitives, print their names, and increment their counters. Thus,
the list logic is written once, and the counters for `--bench` are always
correct.

### Indexing

Before sorting, each number is assigned an **index**: its position in the sorted order (the smallest number is assigned 0, the next is assigned 1, and so on). The index is determined by counting the number of numbers that are smaller than the specified one.

```
data:   42   -7  1000   3
index:   2    0     3   1
```

All the algorithms work on the indexes, not on the real values. This makes
them simpler: the numbers are always `0 ... n-1`, with no negative numbers and
no gaps. Radix sort especially needs this, because it reads the bits of the
index.

### Parsing

- Every argument is split on spaces (`ft_split`), so `"3 2 1"` works.
- Each word is converted with our own function that accepts one optional `+` or `-` and then only digits. The value is built in a `long` and checked against `INT_MAX` / `INT_MIN` after every digit, so an overflow is caught before it happens.
- Flags are compared with `ft_strncmp` using the length of the flag + 1, so that `--simplex` is not accepted as `--simple`.
- After all numbers are added, the list is checked for duplicates.
- On any error, all memory is freed and `Error` is printed on the standard error.

## Disorder

The disorder tells how far the input is from being sorted. We count every
**pair** of numbers (`i` before `j`) and check if the pair is in the wrong
order (an *inversion*):

```
disorder = number of pairs in the wrong order / number of all pairs
```

- `0.0` means the stack is already sorted.
- `1.0` means the stack is sorted in reverse.
- A random list gives a value close to `0.5`.

Example with `4 67 3 87 23`: there are 10 pairs and 4 of them are in the wrong
order (`4>3`, `67>3`, `67>23`, `87>23`), so the disorder is `4 / 10 = 40.00%`.

The disorder is computed **once, before sorting**, by comparing every pair:
O(n²) time and O(1) extra memory. This happens before any operation, so it does
not change the number of operations.

## Algorithms

In the formulas below, `n` is the number of elements. Complexity is counted in
**operations** printed by the program (the Push_swap model).

### Small inputs (2 to 5 numbers)

For small inputs, custom fast sorting algorithms are used, implemented by the adaptive strategy:

- **2 numbers:** one `sa` if necessary.

- **3 numbers (`sort_three`):** the largest number is moved down (`ra` or `rra`), then one `sa` if the first two numbers are in the wrong order. Maximum of 2 operations.

- **4 or 5 numbers (`sort_four_five`):** the smallest numbers are placed in `b` one by one (each of them is moved up by the shorter path, `ra` or `rra`), the remaining 3 numbers are sorted using `sort_three`, and then everything is moved back down using `pa`. Maximum of 12 operations for 5 numbers.

Since `n` here never exceeds 5, the number of operations is limited by a constantigger than 5 here, the number of operations is bounded by
a constant.

### Simple: selection sort, O(n²)

1. Look for the number with index `0`. Rotate `a` (`ra`) until it is on top, then `pb`.
2. Do the same for index `1`, `2`, ... until `a` is empty.
3. `b` now holds the numbers from biggest (top) to smallest, so `pa` until `b` is empty gives a sorted `a`.

**Complexity:** to find each number we rotate at most the whole stack `a`, so
at most `n + (n-1) + ... + 1 = n(n+1)/2` rotations, plus `n` `pb` and `n` `pa`.
This is **O(n²)** operations. Memory: only the nodes themselves, **O(n)**, and
O(1) extra.

### Medium: chunk (bucket) sort, O(n√n)

The indexes are divided into **chunks** of `k` numbers: `0 ... k-1`,
`k ... 2k-1`, and so on. We use `k = 10` for up to 100 numbers and `k = 50` for
more.

1. **Push chunks to `b`.** Go through `a`: if the top belongs to the current chunk, `pb` it, otherwise `ra`. If the number is in the **lower half** of the chunk, it is also sent to the bottom of `b` with `rb`. When the whole chunk is in `b`, move on to the next chunk.
2. **Push back to `a`.** Find the biggest index in `b`, rotate it to the top by the shorter way (`rb` if it is in the upper half of `b`, `rrb` otherwise) and `pa`. Repeat until `b` is empty. Because we always push the biggest first, `a` ends up sorted.

Why the lower half goes to the bottom: the bigger half of each chunk stays near
the top of `b` and the smaller half near the bottom. So the biggest number left
in `b` is always close to one of the two ends, and step 2 needs only a few
rotations.

**Complexity:**

- Step 1: there are `n / k` chunks. To collect one chunk we turn `a` at most once, so at most `n` `ra` per chunk: **n² / k** rotations, plus `n` `pb` and at most `n` `rb`.
- Step 2: the biggest number is always in the last chunk, close to the top or the bottom of `b`, so it needs at most about `k` rotations: **n · k** rotations, plus `n` `pa`.
- Total: `n²/k + n·k`. This is the smallest when `k` grows like `√n`, and then both parts are `n√n`, so the algorithm is **O(n√n)**.

Our values follow `√n` (10 = √100, 50 ≈ 2.2·√500). The constant was tuned by
measuring: on 500 numbers, `k = 50` gave about 5 760 operations and `k = 22`
about 7 580, because in practice step 1 rarely needs a full turn of `a`.

Memory: **O(n)**, no extra arrays.

### Complex: binary radix sort, O(n log n)

Radix sort looks at the **bits** of the index, starting from the lowest bit.

For every bit (bit 0, bit 1, bit 2, ...):

1. Go through all the numbers of `a` once. If the current bit of the index is `1`, `ra` (the number stays in `a`). If it is `0`, `pb`.
2. Push everything back from `b` with `pa`.

After each pass, the numbers are sorted by all the bits checked so far, and the
order from the previous passes is kept. After the last bit, `a` is sorted.

Example of one pass on bit 0, indexes `3 0 2 1` (binary `11 00 10 01`):
`3` has bit `1` → `ra`, `0` has bit `0` → `pb`, `2` → `pb`, `1` → `ra`. Then `pa`, `pa`. All the even indexes are now above the odd ones.

**Complexity:** the indexes are `0 ... n-1`, so they need `⌈log₂ n⌉` bits. Each
pass uses exactly `n` operations (`ra` or `pb`) plus one `pa` for every `pb`,
so at most `2n` operations per pass. Total: at most **2n · ⌈log₂ n⌉**, which
is **O(n log n)**. The number of operations depends only on `n` and the number
of zero bits, not on the order of the input, so it is very predictable:

| n | bits | operations |
|---|---|---|
| 100 | 7 | 1 084 |
| 500 | 9 | 6 784 |


### Adaptive (default)

The adaptive strategy first looks at the size and the disorder, then chooses a
method:

| Condition | Method | Complexity |
|---|---|---|
| already sorted | nothing is printed | O(1) |
| 2 to 5 numbers | small-input sorts | constant |
| disorder < 0.2 | selection sort | O(n²) |
| 0.2 ≤ disorder < 0.5 | chunk sort | O(n√n) |
| disorder ≥ 0.5 | radix sort | O(n log n) |

#### Why these thresholds

- **0.5** is the disorder of a random list. Above it, the input is random or close to reversed, so we can not use the existing order. Radix sort is the safest choice there: its number of operations is fixed by `n` and does not get worse for any input.
- **Between 0.2 and 0.5** the input is partly sorted. Chunk sort gets cheaper on such input: numbers of the same chunk are already close to each other in `a`, so step 1 needs fewer rotations.
- **Below 0.2** only a few pairs are in the wrong order. For this regime the subject says O(n) in its text; following the clarification we received from the peers, the required class for this regime is O(n²), so the simple strategy is used.

#### Complexity

The adaptive strategy adds only a check for disorder before sorting (no operations). Each mode then inherits the upper bound for the method used, shown in the table above.
## Results

Average number of operations on random inputs:

| Strategy | 3 numbers | 5 numbers | 100 numbers | 500 numbers |
|---|---|---|---|---|
| `--simple` | 6 | 13 | 2 745 | 63 558 |
| `--medium` | 8 | 18 | 770 | 5 762 |
| `--complex` | 8 | 23 | 1 084 | 6 784 |
| `--adaptive` | 1 | 9 | 979 | 6 255 |

## Files

- `push_swap.h`: structures and prototypes.
- `main.c`: the main function.
- `pars.c`: parsing of numbers and flags, error checks.
- `push_swap_utils_1.c`: creating nodes, adding to a stack, freeing, `swap`.
- `push_swap_utils_2.c`: `rotate`, `rrotate`, `push_to_other`, `sorted`, indexing.
- `operations1.c`, `operations2.c`, `operations3.c`: the 11 operations with their counters.
- `better_disorder.c`: computing the disorder.
- `super_simple_sort.c`: sorts for 3, 4 and 5 numbers.
- `simple_sort.c`: selection sort.
- `medium_sort.c`: chunk sort.
- `complex_sort.c`: radix sort.
- `push_swap.c`: choosing the strategy and the adaptive logic.
- `bench.c`: the `--bench` output.

## Contributions

| Login | Work |
|---|---|
| mmolotko | the operations, the disorder function, the sorting algorithms|
| msotnych | project structure, header, parsing, indexing, `--bench`, Makefile, adaptive strategy|

## Resources

- [The push_swap subject](https://projects.intra.42.fr/)
- [Sorting algorithm — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Inversion (discrete mathematics) — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))
- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Google](https://www.google.com/) search engine such sites as: [Stack Overflow](https://stackoverflow.com/questions), [GeeksforGeeks](https://www.geeksforgeeks.org/), [GitHub](https://github.com)
- [Peer discussions with other 42 students](https://www.42network.org/)

### Use of AI

AI ([Claude](https://claude.com/)) was used:

- **Explanations:** to explain linked lists, the disorder, bit operations and how radix sort and chunk sort work, and to show an animation of radix sort.
- **README:** a draft of this file was generated with AI and edited by us.
- **Measuring:** measure the number of operations, to understand if it's fits for conditions.