// Caskade 
// Created on April 14, 2025
// By Chris Kelsey of Blue Vision Studios

V1 Information

The first version ran "unoptimized" boolean operations in Assembly, as in, operations that require time to calculate, 
rather than the traditional sense of boolean.

The tests I ran were around the seven second mark to run 340 quinvigintillion operations, but I wanted instant results,
which meant that the boolean operations I was running were not the correct ones meant for the Caskade programming language.

V2

The second version ran NOT R0, R1 (switchOn in Caskade) in C to see how it quickly it would run the operations. When I ran the
test one at a time, it was instant, but when I changed the C program to run 100 tests, it said the average per test was 30 nanoseconds
for completing 340 quinvigintillion operations.

Version two confirms that that NOT R0, R1 (switchOn in Caskade) is one of the boolean (true or false) operations that will play an
integral role in the Caskade programming language.


Notes:

Caskade's purpose is to use this low-level boolean logic as the foundational interpretation of binary, which can then be compiled
and used by other programming languages for near-instant to instant results.

This allows for any computer, no matter how old, to become a quantum computer.
