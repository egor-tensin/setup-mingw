Set up MinGW-w64
================

[![Test](https://github.com/egor-tensin/setup-mingw/workflows/Test/badge.svg)](https://github.com/egor-tensin/setup-mingw/actions?query=workflow%3ATest)

This is a GitHub action that sets up MinGW-w64 in your workflow run.

1. Installs MinGW-w64 on either Ubuntu or Windows.
2. Fixes the infamous libwinpthread-1.dll [static linking issue].

[static linking issue]: https://stackoverflow.com/q/13768515/514684

Use it in your workflow like this:

    - name: Set up MinGW
      uses: egor-tensin/setup-mingw@v2
      with:
        platform: x64

* `x64` is the default value for the `platform` parameter and can be omitted.
Use `x86` if you want to build 32-bit binaries.
* Set the `cygwin` parameter to `1` to set up MinGW inside an existing Cygwin
installation (see [my other action] for setting up Cygwin itself).
* `cc` and `c++` executables are set up, pointing to the `*-gcc` and `*-g++`
executables.
Disable this by setting the `cc` parameter to `0`.

[my other action]: https://github.com/egor-tensin/setup-cygwin

API
---

| Input     | Value   | Default | Description
| --------- | ------- | ------- | -----------
| platform  | x64     | Yes     | Install the x86_64 toolchain.
|           | *Other* | No      | Install the i686 toolchain.
| cygwin    | *Other* | Yes     | Install native binaries.
|           | 1       | No      | Install Cygwin packages.
| static    | 1       | Yes     | Enable the static-linking workaround.
|           | *Other* | No      | Disable the static-linking workaround.
| cc        | 1       | Yes     | Set up `cc`/`c++` executables.
|           | *Other* | No      | Don't set up `cc`/`c++`.
| hardlinks | *Other* | Yes     | Cygwin: don't convert any symlinks.
|           | 1       | No      | Cygwin: convert symlinks in /usr/bin to hardlinks.

| Output  | Example                  | Description
| ------- | ------------------------ | -----------
| prefix  | x86_64-w64-mingw32       | Cross-compilation toolchain prefix
| gcc     | x86_64-w64-mingw32-gcc   | gcc binary name
| gxx     | i686-w64-mingw32-g++     | g++ binary name
| windres | i686-w64-mingw32-windres | windres binary name

License
-------

Distributed under the MIT License.
See [LICENSE.txt] for details.

[LICENSE.txt]: LICENSE.txt
