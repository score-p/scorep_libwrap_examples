- Same basic structure as ../qimage/README.md

- Additionally we need `fix-type-scopes.sh`

    - It provides a mapping that tells for each type that is locally declared in which class scope it is. This works around a technical limitation of the library wrapper generator / libclang

    - Edit `wrapper_name` in `fix-type-scopes.sh`
    - Source `fix-type-scopes.sh` every time you generate the wrapper newly. I.e. after `make,` if it shows `GEN scorep_libwrap_\*.cc`.

    - If more errors turn up you might need to look up where these types come from, I.e. google "qt UndeclaredType", and add them to the list
