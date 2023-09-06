
# This makefile is for LLVM 14.0.0
# For the newer versions, follow the official document

VERSION=14.0.0

SHELL=/bin/bash -O extglob -c

BASE_DIR=$(shell pwd)
INSTALL_DIR=${BASE_DIR}/llvm-install

LLVM_TAR_FILE=llvm-${VERSION}.src.tar.xz
CLANG_TAR_FILE=llvm/tools/clang-${VERSION}.src.tar.xz

all: llvm clang build env

llvm: ${LLVM_TAR_FILE}

${LLVM_TAR_FILE}:
	$("- Download llvm")
	wget https://github.com/llvm/llvm-project/releases/download/llvmorg-${VERSION}/llvm-${VERSION}.src.tar.xz && \
	tar xf llvm-${VERSION}.src.tar.xz && \
	mv llvm-${VERSION}.src llvm
	
clang: llvm/tools/clang

llvm/tools/clang: ${CLANG_TAR_FILE} 

${CLANG_TAR_FILE}:
	$("- Download clang")
	cd llvm/tools && \
	wget https://github.com/llvm/llvm-project/releases/download/llvmorg-${VERSION}/clang-${VERSION}.src.tar.xz && \
	tar xf clang-${VERSION}.src.tar.xz && \
	mv clang-${VERSION}.src clang

build: 
	$("- Build llvm")
	mkdir -p llvm-objects && \
	cd llvm-objects && \
	cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_INCLUDE_BENCHMARKS=false ../llvm && \
	make -j8 && \
	cmake -DCMAKE_INSTALL_PREFIX=../llvm-install/ -P cmake_install.cmake

env: llvmEnv

llvmEnv: 
	echo '##########################' > llvmEnv &&\
	echo '#   LLVM ENV VARIABLES   # ' >> llvmEnv &&\
	echo '##########################' >> llvmEnv &&\
	echo 'export LLVM_DIR=${BASE_DIR}' >> llvmEnv &&\
	echo 'export LLVM_SRC=${BASE_DIR}/llvm' >> llvmEnv &&\
	echo 'export LLVM_SRC_ROOT=${BASE_DIR}/llvm' >> llvmEnv &&\
	echo 'export LLVM_ROOT=${BASE_DIR}/llvm' >> llvmEnv &&\
	echo 'export LLVM_OBJ=${BASE_DIR}/llvm-objects' >> llvmEnv &&\
	echo 'export LLVM_OBJ_DIR=${BASE_DIR}/llvm-objects' >> llvmEnv &&\
	echo 'export LLVM_OBJ_ROOT=${BASE_DIR}/llvm-objects' >> llvmEnv &&\
	echo 'export LLVM_INSTALL_DIR=${BASE_DIR}/llvm-install' >> llvmEnv &&\
	echo 'export PATH=${BASE_DIR}/llvm-install/bin:$$PATH' >> llvmEnv &&\
	echo "source ${BASE_DIR}/llvmEnv" >> ~/.bashrc

clean:
	@echo ""
	@echo "[Warning!!]"
	@echo "You are going to clean all llvm src files!!"
	@echo "It takes huge amount of time to rebuild the llvm. If it was intended, use"
	@echo "make cleanallllvmsrc"
	@echo ""

cleanallllvmsrc:
	rm -rf !("Makefile")

