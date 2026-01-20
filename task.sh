#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
cd "$ROOT_DIR"

usage() {
  cat <<'EOF'
Usage: ./task.sh {build|lint|run|clean}
  build  Configure and build
  lint   Run clang-format target
  run    Build and run the binary
  clean  Remove all build outputs
EOF
}

cmd="${1-}"
if [[ -z "$cmd" || "$cmd" == "-h" || "$cmd" == "--help" ]]; then
  usage
  exit 1
fi

configure() {
  cmake -S . -B build
}

build() {
  cmake --build build
}

case "$cmd" in
  build)
    configure
    build
    ;;
  lint)
    configure
    cmake --build build --target clang-format
    ;;
  run)
    configure
    build
    ./build/1d1c
    ;;
  clean)
    rm -rf build
    ;;
  *)
    echo "Unknown command: $cmd" >&2
    usage
    exit 1
    ;;
esac
