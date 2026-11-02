# CPPModTemplate

This repository is a single C++ mod template for UE4SS. The root CMake project
builds `CPPModTemplate.dll` from `src/` and links against the UE4SS dependency
in the `deps/RE-UE4SS` submodule.

This is a fork of [UE4SS-RE/UE4SSCPPTemplate](https://github.com/UE4SS-RE/UE4SSCPPTemplate),
edited for personal use by KJAyano. The original license and copyright notices
are retained.

## Project layout

- `include/CPPModTemplate.hpp` contains the mod class and lifecycle behavior.
- `src/dllmain.cpp` contains the loader exports.
- `assets/` is for optional mod runtime assets.
- `deps/CMakeLists.txt` adds the UE4SS submodule.
- `version.h` and `version.rc` define DLL version metadata.
- `build_scripts/` contains Windows project-generation and build helpers.

## Getting started

Initialize the UE4SS submodule, then generate and build the project:

```bat
git submodule update --init --recursive
cmake -B build -G "Visual Studio 17 2022"
cmake --build build --config Game__Shipping__Win64
```

Edit `include/CPPModTemplate.hpp` to customize the mod metadata and behavior.
Keep `version.h` in sync when changing the mod version or product name. Add
additional source files to the root `CMakeLists.txt` target as needed.

The build helpers are available as `build_scripts\generate_project_files.bat`
and `build_scripts\build_mods_shipping.bat`.

## Install

After building the `Game__Shipping__Win64` configuration, copy
`build\Game__Shipping__Win64\bin\CPPModTemplate.dll` into the active UE4SS
runtime's `Mods\CPPModTemplate\dlls\` directory and rename it to `main.dll`.
For example:

```text
<UE4SS runtime>\Mods\CPPModTemplate\dlls\main.dll
```