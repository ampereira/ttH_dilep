################################################################################
# Make file for LipMiniAnalysis
################################################################################

SHELL = /bin/sh

DEFINES = -Dextname


CXX = g++
LD  = g++

ROOTCFLAGS = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS   = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS  = $(shell root-config --glibs) -lMinuit -lEG -lPhysics -lTreePlayer

CXXFLAGS = -Wall -Wextra -Wno-comment -Wno-deprecated-declarations -Wno-sign-compare -fopenmp $(ROOTCFLAGS)

ifeq ($(DEBUG),yes)
	CXXFLAGS += -ggdb3
else
	CXXFLAGS += -O3
endif

LIBS  = $(ROOTLIBS)
GLIBS = $(ROOTGLIBS)

INCLUDES = -I$(ROOTSYS)/include

################################################################################
# analysis code
################################################################################

LIPMINIANALYSIS_DIR = ../LipMiniAnalysis/lib

SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
SRC = $(wildcard $(SRC_DIR)/*.cxx)
OBJ = $(patsubst $(SRC_DIR)/%.cxx,$(BUILD_DIR)/%.o,$(SRC))
DEPS = $(patsubst $(BUILD_DIR)/%.o,$(BUILD_DIR)/%.d,$(OBJ))


################################################################################
# Rules
################################################################################

all: $(BIN_DIR)/ttH_dilep

cudatest: $(BIN_DIR)/ttH_dilep_cuda

dice: $(BIN_DIR)/ttH_dilep_dice

$(BUILD_DIR)/old_neut.o: $(SRC_DIR)/neut.cxx $(SRC_DIR)/myvector.h $(SRC_DIR)/neut.h
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $(SRC_DIR)/neut.cxx -o $(BUILD_DIR)/neut.o

$(BUILD_DIR)/dilep_input.o: $(SRC_DIR)/dilep_input.cxx $(SRC_DIR)/dilep_input.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRC_DIR)/dilep_input.cxx -o $(BUILD_DIR)/dilep_input.o

$(BUILD_DIR)/neut.o: $(SRC_DIR)/neut/neut.cxx $(SRC_DIR)/myvector.h $(SRC_DIR)/neut/neut.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRC_DIR)/neut/neut.cxx -o $(BUILD_DIR)/neut.o

$(BUILD_DIR)/dilep.o: $(SRC_DIR)/neut_dice/dilep.cxx $(SRC_DIR)/neut_dice/dilep.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRC_DIR)/neut_dice/dilep.cxx -o $(BUILD_DIR)/dilep.o

$(BUILD_DIR)/neut_dice.o: $(SRC_DIR)/neut_dice/neut.cxx $(SRC_DIR)/myvector.h $(SRC_DIR)/neut_dice/neut.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRC_DIR)/neut_dice/neut.cxx -o $(BUILD_DIR)/neut_dice.o

$(BUILD_DIR)/neut_cuda.o: $(SRC_DIR)/neut_cuda/neut.cxx $(SRC_DIR)/myvector.h $(SRC_DIR)/neut_cuda/neut.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRC_DIR)/neut_cuda/neut.cxx -o $(BUILD_DIR)/neut_cuda.o

$(BIN_DIR)/ttH_dilep: $(SRC_DIR)/ttH_dilep.cxx $(SRC_DIR)/ttH_dilep.h $(BUILD_DIR)/neut.o $(BUILD_DIR)/dilep_input.o $(LIPMINIANALYSIS_DIR)/libLipMiniAnalysis.a
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/ttH_dilep $(INCLUDES) $(SRC_DIR)/ttH_dilep.cxx $(BUILD_DIR)/neut.o $(BUILD_DIR)/dilep_input.o -L$(LIPMINIANALYSIS_DIR) -lLipMiniAnalysis $(LIBS) $(GLIBS) -lMinuit -lPhysics

$(BIN_DIR)/ttH_dilep_cuda: $(SRC_DIR)/ttH_dilep.cxx $(SRC_DIR)/ttH_dilep.h $(BUILD_DIR)/neut_cuda.o $(BUILD_DIR)/dilep_input.o $(LIPMINIANALYSIS_DIR)/libLipMiniAnalysis.a
	$(CXX) $(CXXFLAGS) -DD_CUDA -o $(BIN_DIR)/ttH_dilep_cuda $(INCLUDES) $(SRC_DIR)/ttH_dilep.cxx $(BUILD_DIR)/neut_cuda.o $(BUILD_DIR)/dilep_input.o -L$(LIPMINIANALYSIS_DIR) -lLipMiniAnalysis $(LIBS) $(GLIBS) -lMinuit -lPhysics

$(BIN_DIR)/ttH_dilep_dice: $(SRC_DIR)/ttH_dilep.cxx $(SRC_DIR)/ttH_dilep.h $(BUILD_DIR)/dilep.o $(BUILD_DIR)/neut_dice.o $(BUILD_DIR)/dilep_input.o $(LIPMINIANALYSIS_DIR)/libLipMiniAnalysis.a
	$(CXX) $(CXXFLAGS) -DD_DICE -o $(BIN_DIR)/ttH_dilep_dice $(INCLUDES) $(SRC_DIR)/ttH_dilep.cxx $(BUILD_DIR)/neut_dice.o $(BUILD_DIR)/dilep.o $(BUILD_DIR)/dilep_input.o -L$(LIPMINIANALYSIS_DIR) -lLipMiniAnalysis $(LIBS) $(GLIBS) -lMinuit -lPhysics

clean:
	rm -rf $(BUILD_DIR)/*.o $(BIN_DIR)/*
