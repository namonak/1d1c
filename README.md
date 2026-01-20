# 1d1c

1 day 1 coding with C (BOJ solutions + Unity tests)

This repository is intended to be built and tested only inside Docker.

## Requirement

* Git (for submodules)
* Docker Desktop (Windows/macOS) or Docker Engine (Linux)

## Initialize

```bash
$ git submodule update --init --recursive
```

## Build and Test (Docker only)

Option A: One-shot command

```bash
$ docker build -t 1d1c .
$ docker run --rm -v ${PWD}:/workspace 1d1c bash -lc "cmake -S . -B build && cmake --build build && ./build/1d1c"
```

Option B: Interactive shell

```bash
$ docker build -t 1d1c .
$ docker run --rm -it -v ${PWD}:/workspace 1d1c bash
# cmake -S . -B build
# cmake --build build
# ./build/1d1c
```

## Lint/Format (Docker only)

```bash
$ docker run --rm -v ${PWD}:/workspace 1d1c bash -lc "cmake -S . -B build && cmake --build build --target clang-format"
```
