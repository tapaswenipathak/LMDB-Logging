projectpath = ${CURDIR}
lmdb_path = ${projectpath}/lib/lmdb

ifeq ($(UNAME_S),Linux)
		OPERATING_SYSTEM = LINUX
		PLATFORM_TARGET = linux
        CCFLAGS += -D LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
		OPERATING_SYSTEM = OSX
		PLATFORM_TARGET = osx
        CCFLAGS += -D OSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif

clean:
	@rm -rf build

osx: deps
	if [ ! -d "build" ]; then mkdir -p build; fi
	if [ ! -d "build/Makefile" ]; then cd build;cmake -DCMAKE_OSX_ARCHITECTURES=x86_64 ..; fi

xcode: deps
	if [ ! -d "build" ]; then mkdir -p build; fi

linux: deps $(lockless_path)
	rm -rf build
	mkdir -p build
	cd build;cmake ..
	cd build;make VERBOSE=1

deps: $(lmdb_path)/libraries/liblmdb/liblmdb.a
