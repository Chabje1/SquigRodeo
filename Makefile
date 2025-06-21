BUILD_DIR:=build
OUTPUT_DIR:=${BUILD_DIR}/server
INDEX_HTML:=${OUTPUT_DIR}/index.html

ext/emsdk/upstream/emscripten:
	@cd ext/emsdk && ./emsdk install latest && ./emsdk activate latest

.PHONY: configure
configure: ext/emsdk/upstream/emscripten
	@. ./ext/emsdk/emsdk_env.sh && emcmake cmake -S . -B ${BUILD_DIR}

.PHONY: build
build: configure
	@. ./ext/emsdk/emsdk_env.sh && cd ${BUILD_DIR} && emmake make

.PHONY: launch
launch: build
	@cd ${OUTPUT_DIR} && http-server -c-1 -p 5173 --cors

.PHONY: clean
clean:
	@rm -rf ${BUILD_DIR}