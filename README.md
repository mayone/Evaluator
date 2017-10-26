# Profiler
---
## Purpose
* Measure the execution time of sections

## Library
* `profiler/profiler.h` for **user-space** program
* `profiler/kprofiler.h` for **kernel-space** program

## Usage
1. Put `prof_begin("section_title")` before the section
2. Put `prof_end("section_title")` after the section
3. Use `prof_dump()` to dump the execution time of all sections
