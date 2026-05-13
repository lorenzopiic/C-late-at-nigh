# Introduction

This implementation is based on the one I studied in Deitel's textbook.
The book itself offers a remarkable conceptual introduction to linked lists, and its clarity is reflected in the simple yet effective code that implements the structure.
It was truly helpful for me, a programming novice, as it drastically reduces the pointer logic underlying the data structure.

## Personal Contributions to the Code

Since the implementation was perfect for teaching purposes, I didn't change a single line of code for the insert and delete functions.
However, I did try to work on the input handling because, when running the code myself, I noticed some unexpected behavior...

## Avoiding Non-Numeric Input
Initially, I didn't like the fact that it was possible to enter non-numeric values when choosing the type of operation to perform. The code wasn't designed to prevent this from happening, so I wrote a simple function that performs this check and returns an error if non-numeric input is provided, which I believe is consistent with what a user running the code might expect.
