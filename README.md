# Evaluator
---
## Purpose
* Evaluate the execution time of sections

## Library
* `evaluator/evaluator.h` for **user-space** program
* `evaluator/kevaluator.h` for **kernel-space** program

## Usage
1. Put `eval_begin("section_title")` before the section
2. Put `eval_end("section_title")` after the section
3. Use `eval_dump()` to dump the execution time of all sections
