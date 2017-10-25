# Evaluator
## Purpose
- Evaluate the performance of sections
## Usage
- evaluator/evaluator.h for user-space program
- evaluator/kevaluator.h for kernel-space program
1. Put eval_start("section_title") before the section
2. Put eval_end("section_title") after the section
3. Use eval_dump() to dump the execution time of all sections
