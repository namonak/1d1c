# 1d1c

1 day 1 coding with C (BOJ solutions + Unity tests)

This repository is built and tested through Docker. Run `task.sh` from the host; it builds the dev image when needed and runs the requested task inside the container.

## Requirement

* Git (for submodules)
* Docker Desktop (Windows/macOS) or Docker Engine (Linux)

## Initialize

```bash
$ git submodule update --init --recursive
```

## Task Script

`task.sh` provides common actions. Run it from the repository root on the host.

```bash
$ ./task.sh build     # Build the project
$ ./task.sh format    # Format code using clang-format
$ ./task.sh lint      # Check code format using clang-format
$ ./task.sh analysis  # Run static analysis (cppcheck & scan-build)
$ ./task.sh run       # Run tests
$ ./task.sh clean     # Cleanup build files
```

## Docker

`task.sh` manages the Docker image automatically. To open a shell manually, use the same image and workspace settings.

```bash
$ ./task.sh build
$ docker run --rm -it \
  --user "$(id -u):$(id -g)" \
  -e HOME=/tmp \
  -v "${PWD}:/workspace" \
  -w /workspace \
  1d1c-dev:ubuntu-24.04 bash
```
