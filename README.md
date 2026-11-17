# bunny

A tiny, **deliberately vulnerable** demo used to test automated PoC generation.
Do not deploy it.

- `bunny.c` reads a name from `argv[1]` and greets it.
- The first commit copies that argument into a 16-byte stack buffer with
  `strcpy` and does no length check.
- The second commit rejects over-long names and copies with a bound.

Build with `make` and run `./bunny Alice`.
