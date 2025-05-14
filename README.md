<p align="center">
	<img src="https://img.shields.io/github/last-commit/joseevilasio/push_swap_42?color=%2312bab9&style=flat-square"/>
</p>

# Push Swap

## About

Push swap is an algorithmic project developed in the C programming language, with the goal of sorting a list of integers using the smallest possible number of operations. It relies solely on two stacks (a and b) and a limited set of instructions. The challenge pushes the developer to implement efficient sorting algorithms under strict operational constraints, encouraging a deep understanding of algorithmic complexity, data structure manipulation, and optimization techniques.

The main application, push_swap, takes a sequence of integers as input and returns the shortest sequence of instructions needed to sort them. Optionally, a bonus program called checker can be developed to validate whether the generated sequence actually sorts the numbers correctly.

## Build

Clone the repository: 
```shell
git clone https://github.com/joseevilasio/push_swap_42.git
```
Enter the cloned directory:
```shell
cd push_swap_42
```
Run `make` to compile the program:
```shell
make
```
## Usage
Start the program:
```shell
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```
## Usage Bonus
Run `make bonus` to compile the program:

Start the program:
```shell
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>./checker "" 1
Error
$>
```

## The Norm

This project is written in accordance to the 42 School's "The Norm" (_Version 4_). To review the Norm, [click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).

## Contributions

If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

### Message to students

If you are searching resources to learn more about your own Push Swap, I encourage you to turn to your peers and the function manuals. Do not implement any code you do not understand and cannot code from scratch.
