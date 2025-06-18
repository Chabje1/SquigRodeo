# SquigRodeo
A Warhammer Age of Sigmar - Soulbound by Cubicle 7 companion extension for OwlbearRodeo

## Prerequisites
- Emscripten (https://emscripten.org/index.html)
- SDL (submodule, https://github.com/libsdl-org/SDL)
- imgui (submodule, https://github.com/ocornut/imgui)
### Optional
- Python3 for `make launch`

## Make Commands
- `make build_all`: Builds the HTML/WASM/JS
- `make launch`: Launches a simple server at http://0.0.0.0:8000/
- `make clean`: Cleans the build dir
