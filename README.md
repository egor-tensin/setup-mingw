Set up MinGW-w64
================

[![Test](https://github.com/egor-tensin/setup-mingw/actions/workflows/test.yml/badge.svg)](https://github.com/egor-tensin/setup-mingw/actions/workflows/test.yml)

This GitHub action sets up MinGW-w64 in your workflow run.

Use it in your workflow like this:

    - name: Set up MinGW
      uses: egor-tensin/setup-mingw@v2
      with:
        platform: x64

* `x64` is the default value for the `platform` parameter and can be omitted.
Use `x86` if you want to build 32-bit binaries.
* `cc` and `c++` executables are set up, pointing to the `*-gcc` and `*-g++`
executables.
Disable this by setting the `cc` parameter to `0`.

API
---

| Input     | Value | Default | Description
| --------- | ----- | ------- | -----------
| platform  | x64   | ✓       | Install the x86_64 toolchain.
|           | *any* |         | Install the i686 toolchain.
| cc        | 1     | ✓       | Set up `cc`/`c++` executables.
|           | *any* |         | Don't set up `cc`/`c++`.
| version   |       | ✓       | Install the default (latest) version.
|           | *any* |         | Install the specified version, if possible.

| Output  | Example                  | Description
| ------- | ------------------------ | -----------
| prefix  | x86_64-w64-mingw32       | Cross-compilation toolchain prefix
| gcc     | x86_64-w64-mingw32-gcc   | `gcc` binary name
| gxx     | i686-w64-mingw32-g++     | `g++` binary name
| windres | i686-w64-mingw32-windres | `windres` binary name

License
-------

Distributed under the MIT License.
See [LICENSE.txt] for details.

[LICENSE.txt]: LICENSE.txt
