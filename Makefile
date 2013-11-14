################################################################################
# Make file for LipMiniAnalysis
################################################################################

SHELL = /bin/sh

DEFINES = -Dextname

CXX        = g++
LD         = g++

ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
#ROOTGLIBS  = $(shell root-config --glibs) -lMinuit -lHtml -lEG -lPhysics -lTreePlayer
ROOTGLIBS  = $(shell root-config --glibs) -lMinuit -lEG -lPhysics -lTreePlayer

#CXXFLAGS   = -Wall -Wextra -Wno-comment -Wno-deprecated-declarations -Wno-sign-compare -O3 $(ROOTCFLAGS)
CXXFLAGS   = -Wall -Wextra -Wno-comment -Wno-deprecated-declarations -Wno-sign-compare -ggdb3 $(ROOTCFLAGS)

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

build/neut.o: src/neut.cxx src/myvector.h src/neut.h
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c src/neut.cxx -o build/neut.o

bin/ttH_dilep: src/ttH_dilep.cxx src/ttH_dilep.h build/neut.o $(LipMiniAnalysis)/libLipMiniAnalysis.a
	$(CXX) $(CXXFLAGS) -o bin/ttH_dilep -I$(INCLUDES) src/ttH_dilep.cxx build/neut.o -L$(LipMiniAnalysis) -lLipMiniAnalysis $(LIBS) $(GLIBS) -lMinuit -lPhysics

clean:
	rm -rf build/*.o bin/*
