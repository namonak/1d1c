#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
cd "$ROOT_DIR"

usage() {
  cat <<'EOF'
Usage: ./task.sh {build|lint|run|clean|analysis}
  build     Configure and build
  lint      Run clang-format target
  analysis  Run static analysis (cppcheck & scan-build)
  run       Build and run the binary
  clean     Remove all build outputs
EOF
}

cmd="${1-}"
if [[ -z "$cmd" || "$cmd" == "-h" || "$cmd" == "--help" ]]; then
  usage
  exit 1
fi

configure() {
  # scan-build를 위해 compile_commands.json 생성이 필요할 수 있습니다.
  cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
}

build() {
  cmake --build build
}

run_analysis() {
  echo ">>> [1/2] Running Cppcheck (via CMake target)..."
  configure > /dev/null
  # CMake에 정의된 커스텀 타겟 실행
  cmake --build build --target cppcheck

  echo -e "\n>>> [2/2] Running Clang Static Analyzer (scan-build)..."
  if command -v scan-build &> /dev/null; then
    rm -rf build
    # scan-build는 빌드 과정을 감싸서 분석함
    scan-build -o report cmake -S . -B build
    scan-build -o report cmake --build build
    echo "Report generated in report/ directory"
  else
    echo "scan-build not found. Skipping."
  fi
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
    rm -rf build report
    ;;
  analysis)
    run_analysis
    ;;
  *)
    echo "Unknown command: $cmd" >&2
    usage
    exit 1
    ;;
esac
