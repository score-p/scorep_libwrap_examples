# User Library Wrapping Examples

Collection of configurations to create wrappers for certain libraries via Score-P's User Library Wrapping feature

## Prerequisites

- Score-P version 4.0 (not yet released) or branch "\*libwrap" [(beta-download)](https://drive.google.com/file/d/1vWRGPhfNtCeE8Xk5w8EEpI38aLr7ilCx)
- libclang-dev 3.6+
- clang/llvm 3.6+

### Ubuntu 17.04 Zesty
    
    sudo apt install libclang-4.0-dev clang-4.0 llvm-4.0 llvm

## How to Use

- Every directory contains one wrapper
- The `README.txt` in each directory contains a complete console recording on the wrapper creation and usage
    - If you want to create a wrapper yourself, use this as inspiration/howto

- The `wrapper/` subdirectory contains the wrapper working directory

- `*/wrapper/README.md` is a help page explaining the workflow and possible warnings and errors.
