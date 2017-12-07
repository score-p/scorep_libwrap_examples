# User Library Wrapping Examples

Collection of configurations to create wrappers for certain libraries via Score-P's User Library Wrapping feature

## Prerequisites

- Score-P version 4.0 (not yet released) or branch "\*libwrap" [(beta-download)](https://drive.google.com/file/d/1vWRGPhfNtCeE8Xk5w8EEpI38aLr7ilCx)
- libclang-dev 3.6+
- clang/llvm 3.6+

### Ubuntu 17.04 Zesty and 17.10 Artful

    sudo apt install libclang-4.0-dev clang-4.0 llvm-4.0 llvm

To use Clang/LLVM 5.0 you might need to add symlinks from clang-5.0, clang++-5.0 and llvm-config-5.0 to the respective non-suffixed binaries.
This ensures that Score-P's `configure` finds them.
Unfortunately all Clang/LLVM binaries other than version 4.0 are suffixed in 17.10 Artful,
and there is no package like `llvm` for 4.0 adding symlinks to remove the suffix automatically.

## How to Use

- Every directory contains one wrapper
- The `README.txt` in each directory contains a complete console recording on the wrapper creation and usage
    - If you want to create a wrapper yourself, use this as inspiration/howto

- The `wrapper/` subdirectory contains the wrapper working directory

- `*/wrapper/README.md` is a help page explaining the workflow and possible warnings and errors.
