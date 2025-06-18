# SquigRodeo
A Warhammer Age of Sigmar - Soulbound by Cubicle 7 companion extension for OwlbearRodeo

## Prerequisites
- Emscripten (https://emscripten.org/index.html)
- SDL (submodule, https://github.com/libsdl-org/SDL)
- imgui (submodule, https://github.com/ocornut/imgui)
### Optional
- http-server node package for `make launch` (https://www.npmjs.com/package/http-server)

## Make Commands
- `make configure`: Does the CMake configuration step
- `make build`: Builds the HTML/WASM/JS + copies files from public into the server directory
- `make launch`: Launches a simple server at http://0.0.0.0:5173/
- `make clean`: Cleans the build dir
