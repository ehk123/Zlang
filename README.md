# Ethan's Compiled Language (ECL)
A hobby compiled programming language.

## Getting started
Requires `nasm` and `ld` on a Linux operation system. If you are on Windows or macOS, look at [Multipass](https://ubuntu.com/blog/how-to-create-a-vscode-linux-remote-environment) to create Ubuntu VMs.
```
git clone https://github.com/ehk123/ecl.git
cd ecl
mkdir build
cmake -S . -B build
cmake --build build
```
Executable will be `ethan` in the `build/` directory.
