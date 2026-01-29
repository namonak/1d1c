FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clang \
    clang-format \
    clang-tools \
    cppcheck \
    gdb \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

# Update the symbolic link
RUN update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100
RUN update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 100

# Set the default compiler
ENV CC=/usr/bin/clang
ENV CXX=/usr/bin/clang++
