COMPILER:=em++
OUTPUT_DIR:=build
INDEX_HTML:=${OUTPUT_DIR}/index.html
INCLUDE_DIR:=include

${OUTPUT_DIR}:
	@mkdir -p ${OUTPUT_DIR}

configure: ${OUTPUT_DIR}
	@emcmake cmake -S . -B ${OUTPUT_DIR}

${INDEX_HTML}: configure
	@cd ${OUTPUT_DIR} && emmake make

build_all: ${INDEX_HTML}

launch: build_all
	@python3 -m http.server -d ${OUTPUT_DIR}

clean:
	@rm -rf ${OUTPUT_DIR}