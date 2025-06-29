if [ $# -ne 3 ]; then
    echo "Usage: build_obr_sdk.sh <CMAKE_SOURCE_DIR> <OBR_SDK_BUILD_DIR> <CMAKE_BINARY_DIR>"
    exit 1
fi

CMAKE_SOURCE_DIR=$1
OBR_SDK_BUILD_DIR=$2
CMAKE_BINARY_DIR=$3

cp ${CMAKE_SOURCE_DIR}/build_files/webpack.config.ts ${OBR_SDK_BUILD_DIR}
cd ${OBR_SDK_BUILD_DIR}
yarn add webpack typescript ts-loader webpack-cli ts-node --save-dev 
yarn install
./node_modules/.bin/webpack -c ./webpack.config.ts
cp -R ${OBR_SDK_BUILD_DIR}/src ${CMAKE_BINARY_DIR}/server
# ln -s ${OBR_SDK_BUILD_DIR}/lib ${CMAKE_BINARY_DIR}/server/obr_sdk