# zlang
A compiled esoteric programming langauge designed to resemble popular Gen Z slang.

## Getting started
Requires `nasm` and `ld` on a Linux operation system. If you are on Windows or macOS, look at [Multipass](https://ubuntu.com/blog/how-to-create-a-vscode-linux-remote-environment) to create Ubuntu VMs.
```
git clone https://github.com/ehk123/zlang.git
cd zlang
mkdir build
cmake -S . -B build
cmake --build build
```
Executable will be `zlang` in the `build/` directory.
