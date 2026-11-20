# directory of this makefile
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))/..

.PHONY: test0
test0:
	mkdir ${ROOT_DIR}/build || true
	mv ${ROOT_DIR}/build/test0.out ${ROOT_DIR}/build/test0.out.old || true
	g++ -O0 -o ${ROOT_DIR}/build/test0.out ${ROOT_DIR}/test.cpp

.PHONY: test1
test1:
	mkdir ${ROOT_DIR}/build || true
	mv ${ROOT_DIR}/build/test1.out ${ROOT_DIR}/build/test1.out.old || true
	g++ -O1 -o ${ROOT_DIR}/build/test1.out ${ROOT_DIR}/test.cpp

.PHONY: test2
test2:
	mkdir ${ROOT_DIR}/build || true
	mv ${ROOT_DIR}/build/test2.out ${ROOT_DIR}/build/test2.out.old || true
	g++ -O2 -o ${ROOT_DIR}/build/test2.out ${ROOT_DIR}/test.cpp

.PHONY: test3
test3:
	mkdir ${ROOT_DIR}/build || true
	mv ${ROOT_DIR}/build/test3.out ${ROOT_DIR}/build/test3.out.old || true
	g++ -O3 -o ${ROOT_DIR}/build/test3.out ${ROOT_DIR}/test.cpp

.PHONY: testfast
testfast:
	mkdir ${ROOT_DIR}/build || true
	mv ${ROOT_DIR}/build/testfast.out ${ROOT_DIR}/build/testfast.out.old || true
	g++ -Ofast -o ${ROOT_DIR}/build/testfast.out ${ROOT_DIR}/test.cpp
