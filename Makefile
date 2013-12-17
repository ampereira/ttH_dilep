################################################################################
# Make file for LipMiniAnalysis
################################################################################

SHELL = /bin/sh

DEFINES = -Dextname

CXX        = g++
LD         = g++

ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS  = $(shell root-config --glibs) -lMinuit -lEG -lPhysics -lTreePlayer

CXXFLAGS   = -Wall -Wextra -Wno-comment -Wno-deprecated-declarations -Wno-sign-compare -O3 -fopenmp $(ROOTCFLAGS)
#CXXFLAGS   = -Wall -Wextra -Wno-comment -Wno-deprecated-declarations -Wno-sign-compare -ggdb3 -fopenmp $(ROOTCFLAGS)

LIBS       = $(ROOTLIBS)
GLIBS      = $(ROOTGLIBS)

INCLUDES = -I$(incdir) -I$(ROOTSYS)/include -I$(ROOTCOREDIR)/include

################################################################################
# analysis code
################################################################################

LipMiniAnalysis = ../LipMiniAnalysis/lib
COMMONANALYSISCODE = src/DefineSamples_Simulation.cxx src/DefineSamples_Data.cxx src/UserCommandLineOptions.cxx

################################################################################
# Rules
################################################################################

all: bin/ttH_dilep

cudatest: bin/ttH_dilep_cuda

build/old_neut.o: src/neut.cxx src/myvector.h src/neut.h
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c src/neut.cxx -o build/neut.o

build/dilep_input.o: src/dilep_input.cxx src/dilep_input.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/dilep_input.cxx -o build/dilep_input.o

build/neut.o: src/neut/neut.cxx src/myvector.h src/neut/neut.h
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c src/neut/neut.cxx -o build/neut.o

build/neut_cuda.o: src/neut_cuda/neut.cxx src/myvector.h src/neut_cuda/neut.h
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c src/neut_cuda/neut.cxx -o build/neut_cuda.o

bin/ttH_dilep: src/ttH_dilep.cxx src/ttH_dilep.h build/neut.o build/dilep_input.o $(LipMiniAnalysis)/libLipMiniAnalysis.a
	$(CXX) $(CXXFLAGS) -o bin/ttH_dilep -I$(INCLUDES) src/ttH_dilep.cxx build/neut.o build/dilep_input.o -L$(LipMiniAnalysis) -lLipMiniAnalysis $(LIBS) $(GLIBS) -lMinuit -lPhysics

bin/ttH_dilep_cuda: src/ttH_dilep.cxx src/ttH_dilep.h build/neut_cuda.o build/dilep_input.o $(LipMiniAnalysis)/libLipMiniAnalysis.a
	$(CXX) $(CXXFLAGS) -DCUDA -o bin/ttH_dilep_cuda -I$(INCLUDES) src/ttH_dilep.cxx build/neut_cuda.o build/dilep_input.o -L$(LipMiniAnalysis) -lLipMiniAnalysis $(LIBS) $(GLIBS) -lMinuit -lPhysics

clean:
	rm -rf build/*.o bin/*
