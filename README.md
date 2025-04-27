# BlueBlur

BlueBlur is a modding API designed for the Steam version of Sonic Generations. You can use it to interface with the original C++ types of the game when creating your own DLL mods.

## Setup

1. Ensure your project targets C++17 or newer.
2. Add BlueBlur directory to following properties in your project settings:
    * C/C++ -> General -> Additional Include Directories
    * Linker -> General -> Additional Library Directories
3. Include BlueBlur.h in a source file in your project. You should preferably do this in a precompiled header.

Your IDE might show errors when browsing BlueBlur code. However, these are usually false positives, so you should be able to compile without issue.

## Samples

There currently aren't any samples associated with this project. However, you can check these DLL mods for reference:

* [ActualMandM/HedgeDllMods](https://github.com/ActualMandM/HedgeDllMods)
* [blueskythlikesclouds/DllMods](https://github.com/blueskythlikesclouds/DllMods)
* [brianuuu/DllMods](https://github.com/brianuuu/DllMods)
* [GenerationsSM64/GenerationsSM64](https://github.com/GenerationsSM64/GenerationsSM64)
* [HyperBE32/App-Extension-Mods](https://github.com/HyperBE32/App-Extension-Mods)
* [LadyLunanova/DllMods](https://github.com/LadyLunanova/DllMods)
* [PTKay/ModUpdates](https://github.com/PTKay/ModUpdates)

## Singletons

Refer to these singletons included in the game for a head-start:

* [`Sonic::CApplicationDocument::GetInstance()`](https://github.com/blueskythlikesclouds/BlueBlur/blob/master/Sonic/System/ApplicationDocument.h)
* [`Sonic::CGameDocument::GetInstance()`](https://github.com/blueskythlikesclouds/BlueBlur/blob/master/Sonic/System/GameDocument.h)
* [`Sonic::CInputState::GetInstance()`](https://github.com/blueskythlikesclouds/BlueBlur/blob/master/Sonic/System/InputState.h)
* [`Sonic::Player::CPlayerSpeedContext::GetInstance()`](https://github.com/blueskythlikesclouds/BlueBlur/blob/master/Sonic/Player/Character/Speed/PlayerSpeedContext.h)
* [`Sonic::Player::CSonicClassicContext::GetInstance()`](https://github.com/blueskythlikesclouds/BlueBlur/blob/master/Sonic/Player/Character/SonicClassic/SonicClassicContext.h)
* [`Sonic::Player::CSonicContext::GetInstance()`](https://github.com/blueskythlikesclouds/BlueBlur/blob/master/Sonic/Player/Character/Sonic/SonicContext.h)
* [`Sonic::Player::CSonicSpContext::GetInstance()`](https://github.com/blueskythlikesclouds/BlueBlur/blob/master/Sonic/Player/Character/SonicSp/SonicSpContext.h)

You should use [`Sonic::Player::CPlayerSpeedContext`](https://github.com/blueskythlikesclouds/BlueBlur/blob/master/Sonic/Player/Character/Speed/PlayerSpeedContext.h) if you want to handle every player regardless of their type. Use type specific singletons for specific players. 

## Contribution Guide

### Naming Conventions

- Use `camelCase` for local variables, `SNAKE_CASE` for preprocessor macros, and `PascalCase` for everything else. BlueBlur-specific types that don't exist in the game should use `snake_case` for better differentiation.
- Class names should be prefixed with `C`, e.g., `CSonicContext`.
- Struct names should be prefixed with `S`, e.g., `SUpdateInfo`.
- Class members should be prefixed with `m_`, e.g., `m_Time`. Do not use this prefix for struct members.
- Enum names should be prefixed with `E`, e.g., `ELightType`.
- Enum members should start with `e`, followed by the enum name and an underscore, e.g., `eLightType_Point`.
- For enum members indicating the count of elements, prefix with `n`, followed by the name, e.g., `nLightType`.
- Pointers should be prefixed with `p`, e.g., `pSonicContext`.
- Shared pointers should be prefixed with `sp`, e.g., `spDatabase`.
- References should be prefixed with `r`, e.g., `rMessage`.
- Input function arguments should be prefixed with `in_`, e.g., `in_Name`.
- Output function arguments should be prefixed with `out_`, e.g., `out_Value`.
- Static class members should be prefixed with `ms_`, e.g., `ms_Instance`.
- Static members outside a class should be prefixed with `g_`, e.g., `g_AllocationTracker`.
- BlueBlur-specific preprocessor macros should start with `BB_`, e.g., `BB_INSERT_PADDING`.
- Hedgehog namespace-specific preprocessor macros should start with `HH_` along with the library's shorthand, e.g., `HH_FND_MSG_MAKE_TYPE`.
- Function pointers should be prefixed with `fp`, e.g., `fpCGameObjectConstructor`.

Combine prefixes as necessary, e.g., `m_sp` for a shared pointer as a class member or `in_r` for a const reference as a function argument.

### Coding Style

- Always place curly brackets on a new line.
- Prefer forward declaring types over including their respective headers.
- Use <> includes relative to the project's root directory path.
- Use C++17's nested namespace feature instead of defining multiple namespaces on separate lines.
- Enum classes are prohibited as they were not available when the game was developed.
- Avoid placing function definitions in .h files, instead, implement functions in the header's respective .inl file, similar to a .cpp file.
- Ensure that all class members are declared as public. Even if you suspect that a class member was private in the original code, having it public is more convenient in a modding API.
- Avoid placing multiple class definitions in a single header file unless you have a good reason to do so.
- Keep function pointers or addresses outside functions, define them as global variables in the corresponding .inl file. Mark these global variables as `inline` and never nest them within class definitions. You do not need to use the `g_` prefix for function pointers, `fp` is sufficient.
- Use primitive types defined in `cstdint` instead of using types that come with the language, e.g., use `uint32_t` instead of `unsigned int`. Using `float`, `double` and `bool` is okay.

### Mapping Rules

- Always include the corresponding `offsetof`/`sizeof` assertions for mapped classes/structs. If you are uncertain about the type's size, you can omit the `sizeof` assertion.
- Use the exact type name from the game if it's available through RTTI, otherwise, you can look for shared pointers that may reveal the original type name.
- If you are unsure about the name of a class/struct member, use `Field` followed by the hexadecimal byte offset (e.g., `m_Field194`). Avoid names like `m_StoresThisThingMaybe`, you can write comments next to the definition for speculations.
- If a portion of the byte range is irrelevant to your research or not mapped yet, use the `BB_INSERT_PADDING` macro to align class/struct members correctly.
- When the class has a virtual function table, if you don't want to map every function in it, you can map only the virtual destructor.
- The original file locations are likely available in the executable file as assertion file paths. If you cannot find the file path, use your intuition to place the file in a sensible place.