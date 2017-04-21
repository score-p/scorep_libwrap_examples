# Important Parts

- `make show-summary` shows the scorep-libwrap-init command used

- main.cc
- libwrap.h

- Makefile
    - Edit `QT_INCLUDE` to point to you QT include directory
    - CPPFLAGS
    - LDFLAGS
    - LIBS

- qimage.filter
    - Edit path's in line 3 and 4 according to where your Qt includes are

# How to Create a Wrapper Based on This

- Use `make show-summary` to get the configuration options, and use it to create a new working directory
- Change the above mentioned files to your needs
- Build & Install the wrapper
    ```
    make
    make check
    # Add the missing.filter entries to qimage.filter
    make
    make install
    make installcheck

    ./main_linktime_wrapped
    cube_info -m visits:excl scorep-*/profile.cubex

    ./main_runtime_wrapped
    cube_info -m visits:excl scorep-xyz/profile.cubex
    ```
