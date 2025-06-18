BUILD_DIR:=build
OUTPUT_DIR:=${BUILD_DIR}/server
INDEX_HTML:=${OUTPUT_DIR}/index.html

configure: 
	@emcmake cmake -S . -B ${BUILD_DIR}

build: configure
	@cd ${BUILD_DIR} && emmake make

launch: build
	@cd ${OUTPUT_DIR} && http-server -p 5173 --cors

clean:
	@rm -rf ${BUILD_DIR}