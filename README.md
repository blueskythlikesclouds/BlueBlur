# BlueBlur

BlueBlur is a modding API designed for the Steam version of Sonic Generations. You can use it to interface with the original C++ types of the game when creating your own DLL mods.

## Setup

1. Ensure your project targets VS2019 build tools and C++17. You can keep using VS2022 as long as VS2019 build tools are installed.
2. Add BlueBlur directory to following properties in your project settings:
    * C/C++ -> General -> Additional Include Directories
    * Linker -> General -> Additional Library Directories
3. Include BlueBlur.h in a source file in your project before any other include directive. You should preferably do this in a precompiled header.

## Samples

There currently aren't any samples associated with this project. However, you can check these DLL mods for reference:

* [ActualMandM/HedgeDllMods](https://github.com/ActualMandM/HedgeDllMods)
* [blueskythlikesclouds/DllMods](https://github.com/blueskythlikesclouds/DllMods)
* [brianuuu/DllMods](https://github.com/brianuuu/DllMods)
* [GenerationsSM64/GenerationsSM64](https://github.com/GenerationsSM64/GenerationsSM64)
* [HyperBE32/App-Extension-Mods](https://github.com/HyperBE32/App-Extension-Mods)
* [LadyLunanova/DllMods](https://github.com/LadyLunanova/DllMods)
* [PTKickass/ModUpdates](https://github.com/PTKickass/ModUpdates)

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