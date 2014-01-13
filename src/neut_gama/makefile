UNAME 	  := $(shell uname)
APPNAME			:= saxpy

ROOTSRC_DIR		:= src
CUDA_SUPPORT		:= yes
ifndef CUDA_INSTALL_PATH
ifeq ($(UNAME), Darwin)
CUDA_INSTALL_PATH 	:= /Developer/NVIDIA/CUDA-5.5/
else
CUDA_INSTALL_PATH 	:= /usr/local/cuda-5.5/
endif
endif

BOOST_INCLUDE_PATH	:= /home/cpd19828/boost/1.54.0-gcc4.7.2
BOOST_LIBRARY_PATH	:= /home/cpd19828/boost/1.54.0-gcc4.7.2/stage/lib


CFLAGS 		    	+= -w
NVFLAGS		    	:= 
LDFLAGS		    	:= 
LD_LIBS		    	:= gomp dl cublas pthread cudart cufft GLEW boost_system boost_thread
INCLUDE_DIR	    	:= /usr/local/include $(CUDA_INCLUDE_PATH) $(BOOST_INCLUDE_PATH)
LD_LIBS_DIR	    	:= /usr/local/lib64 $(CUDA_LIBRARY_PATH) $(CUDA_INSTALL_PATH)samples/common/lib $(BOOST_LIBRARY_PATH) /opt/local/lib $(CUDA_INSTALL_PATH)samples/common/lib/linux/x86_64
LAPACK_INCLUDE		:= /usr/local/include/lapackpp #/home/cpd19828/math_libs_gcc4.6.4/lapackpp-2.5.4/
LAPACK_LIBS_DIR		:= /usr/local/lib #/home/cpd19828/math_libs_gcc4.6.4/lapackpp-2.5.4/lib
CUDA_INCLUDE		:= include samples/common/inc
CUDA_LIBS_DIR		:= samples/common/lib
FRAMEWORK	    	:= OpenGL GLUT


ifeq ($(DEBUG),yes)
    OTHER_FLAGS	:= -G -Xcompiler -Wunused-result
    CFLAGS +=  -O3 -pg -g 
else
    OTHER_FLAGS := -Xcompiler -Wunused-result  
    CFLAGS +=  -O3
endif

ifeq ($(CUDA_SUPPORT),yes)
NVCC	  	:= nvcc -x cu
LD        	:= nvcc -link
else
NVCC	  	:= nvcc
LD        	:= gcc
endif


#
# Do not change
#
DEFINES2   := $(DEFINES)
ifdef (DEFINES)
ifeq ($(CUDA_SUPPORT),yes)
DEFINES   := -Xcompiler $(DEFINES)
endif
endif

GCCVERSION := $(shell expr `gcc -dumpversion | cut -f2 -d.` \>= 7)
ifeq "$(GCCVERSION)" "1"
    NVFLAGS += --pre-include /home/cpd19828/gamav2/undef_atomics_int128.h
endif


ARCH 	  := $(shell getconf LONG_BIT)
OMP	  := openmp

MODULES   := ${shell find ${ROOTSRC_DIR} -type d -print | sed 1d | cut -d'/' -f2,3 | sort -u} 
SRC_DIR   := $(ROOTSRC_DIR) $(addprefix src/,$(MODULES))
BUILD_DIR := $(addprefix build/,$(MODULES)) build

SRC_CPP   := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
SRC_C     += $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
SRC_CU    += $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cu))
SRC 	  := $(SRC_CU) $(SRC_CPP) $(SRC_C)
OBJ   	  := $(patsubst src/%.cpp,build/%.o,$(SRC_CPP))
OBJ   	  += $(patsubst src/%.c,build/%.o,$(SRC_C))
OBJ   	  += $(patsubst src/%.cu,build/%.o,$(SRC_CU))
DEPS   	  += $(patsubst build/%.o,build/%.d,$(OBJ))

CUDA_INCLUDE	:= $(addprefix $(CUDA_INSTALL_PATH),$(CUDA_INCLUDE))

RINC      := $(subst :, ,$(INCLUDE) )
INCLUDES  += $(addprefix -I,$(ROOTSRC_DIR)/)
INCLUDES  += $(addprefix -I,$(CUDA_INCLUDE)/)
INCLUDES  += $(addprefix -I,$(LAPACK_INCLUDE)/)
INCLUDES  += $(addprefix -I,$(INCLUDE_DIR)/)
INCLUDES  += $(addprefix -I,$(RINC)/)

CFLAGS	  := -m$(ARCH) $(CFLAGS)
LDFLAGS	  := -m$(ARCH) $(LDFLAGS)

LD_LIBS	     := $(addprefix -l,$(LD_LIBS))
LD_LIBS_DIR  := $(addprefix -L,$(LD_LIBS_DIR))
LD_LIBS_DIR  += $(addprefix -L$(CUDA_INSTALL_PATH),$(CUDA_LIBS_DIR))
LD_LIBS_DIR  += $(addprefix -L,$(LAPACK_LIBS_DIR))

ifeq ($(UNAME),Darwin)
FRAMEWORKS := $(addprefix -framework ,$(FRAMEWORK))
ifeq ($(CUDA_SUPPORT),yes)
FRAMEWORKS2 := $(FRAMEWORKS)
FRAMEWORKS := -Xcompiler "$(FRAMEWORKS)"
endif
else
LD_LIBS += -lglut -lGLU -lGL
FRAMEWORKS :=
endif

ifeq ($(CUDA_SUPPORT),yes)
OMP2 := $(addprefix -f,$(OMP))
OMP := $(addprefix -Xcompiler -f,$(OMP))
else
OMP := $(addprefix -f,$(OMP))
endif

ifeq ($(CUDA_SUPPORT),yes)
NVFLAGS	  := $(NVFLAGS) $(OTHER_FLAGS) --maxrregcount=24 -gencode arch=compute_20,code=sm_20 -gencode arch=compute_20,code=sm_21 -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=sm_35 
LDFLAGS	  := $(LDFLAGS) --relocatable-device-code=true -gencode arch=compute_20,code=sm_20 -gencode arch=compute_20,code=sm_21 -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=sm_35 

vpath %.cu $(SRC_DIR)
endif

vpath %.cpp $(SRC_DIR)
vpath %.c $(SRC_DIR)


define make-cuda
$1/%.d: %.cu 
	$(NVCC) -M $(CFLAGS) $(DEFINES) $(OMP) $(FRAMEWORKS) $(NVFLAGS) $(INCLUDES) $$< -o $$@

$1/%.d: %.cpp
	$(CXX) -M $(CFLAGS) $(DEFINES2) $(OMP2) $(FRAMEWORKS2) $(INCLUDES) $$< -o $$@

$1/%.d: %.c
	$(CC) -M $(CFLAGS) $(DEFINES2) $(OMP2) $(FRAMEWORKS2) $(INCLUDES) $$< -o $$@

$1/%.o: %.cu
	$(NVCC) -c $(CFLAGS) $(DEFINES) $(OMP) $(FRAMEWORKS) $(NVFLAGS) $(INCLUDES) --device-c $$< -o $$@

$1/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(DEFINES2) $(OMP2) $(FRAMEWORKS2) $(INCLUDES) $$< -o $$@

$1/%.o: %.c
	$(CC) -c $(CFLAGS) $(DEFINES2) $(OMP2) $(FRAMEWORKS2) $(INCLUDES) $$< -o $$@
endef


define make-ncuda
$1/%.d: %.cu 

$1/%.d: %.cpp

$1/%.d: %.c

$1/%.o: %.cu
	$(NVCC) -c $(CFLAGS) $(DEFINES) $(OMP) $(FRAMEWORKS) $(NVFLAGS) $(INCLUDES) --device-c $$< -o $$@

$1/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(DEFINES2) $(OMP2) $(FRAMEWORKS2) $(INCLUDES) $$< -o $$@

$1/%.o: %.c
	$(CC) -C $(CFLAGS) $(DEFINES2) $(OMP2) $(FRAMEWORKS2) $(INCLUDES) $$< -o $$@
endef

.PHONY: all checkdirs clean


all: checkdirs bin/$(APPNAME)

bin/$(APPNAME): $(DEPS) $(OBJ) 
	@mkdir -p bin
	@mkdir -p build
	$(LD) $(LDFLAGS) $(OMP) $(FRAMEWORKS) $(LD_LIBS_DIR) $(LD_LIBS) $(OBJ) $(LIB_UTIL) -o $@



checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf bin/$(APPNAME)


ifeq ($(CUDA_SUPPORT),yes)
$(foreach bdir,$(BUILD_DIR),$(eval $(call make-cuda,$(bdir))))
else
$(foreach bdir,$(BUILD_DIR),$(eval $(call make-ncuda,$(bdir))))
endif
