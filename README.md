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

## Task Script

`task.sh` provides common actions. Run it inside the Docker container.

```bash
$ ./task.sh build
$ ./task.sh lint
$ ./task.sh run
$ ./task.sh clean
```

## Docker (Required)

Build the image once, then enter the container.

```bash
$ docker build -t 1d1c .
$ docker run --rm -it -v ${PWD}:/workspace 1d1c bash
```
