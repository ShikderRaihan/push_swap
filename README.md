*This project has been created as part of the 42 curriculum by rshikder, cschwart.*

# Description
## Mandatory:
Automatically sorts the numbers in parametres. This list mustn't include either duplicates or non numerical characters. The function will sort all of them using a set of operations: `sa`, `sb`, `ss`; `pa`, `pb`; `ra`, `rb`, `rr`; `rra`, `rrb`, `rrr` for swapping, pushing to or (reverse) rotating the stacks A and B or both (`ss`, `rr`, `rrr`).

The program knows four ways to sort a list of numbers.

## Bonus:
Manually sorts numbers using the previous operations, or does so in conjunction with `./push_swap`.

# Instructions
## Mandatory:
```bash
make
./push_swap <flags> <list_of_numbers>
```
*<flags> are: `--simple`, `--medium`, `--complex`, `--adaptive` (without, it will be the last one by default); and `--bench` for the count of each commands (without, it will show a list of them each time they occur).*

## Bonus:
### Only the checker
```bash
make bonus
./checker <list_of_numbers>
# Each command one per one, separated by `Enter`.
`Ctrl + D`
```

### Both mandatory and checker parts
```bash
make bonus
./push_swap <list_of_numbers> | ./checker <list_of_numbers> # Just one <list_of_numbers> but twice, with the same numbers and without any change in their order.
```

# Resources
A.I. was used to shorten quicklier some too longs functions taking care with format conversions, or ditto for debugging when we merged our parts.