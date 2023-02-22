# Działa poprawnie z 01
OPTYMALIZACJA=-O1
# Blędne wyniki z optymalizacja 02
# OPTYMALIZACJA=-O2

COMPFLAGS = ${OPTYMALIZACJA} -std=c++17 -g3 -Wall -pedantic

# a list of all the programs in your package
PROGS = DMapProblem

# a list of all your units to be linked with your programs
OTHERS = factrial\
         Multiindex\
         DagIndexer\
         NodeType\
         Parser

CAPDFLAGS = -I./include
CAPDLIBS =

OBJDIR = .obj/

#============
OTHERS_OBJ = ${OTHERS:%=${OBJDIR}%.o}
OBJ_FILES = ${OTHERS_OBJ} ${PROGS:%=${OBJDIR}%.o}

# settings for speed test

# settings for profiler
#COMPFLAGS = -pg -O3 -std=c++14 -Wall -pedantic

CXXFLAGS += ${CAPDFLAGS} ${COMPFLAGS}
CXXLINK = ${CAPDLIBS} ${COMPFLAGS}

.PHONY: all
all: ${PROGS}

FILES=capd/capdAlg/src/capd/basicalg/factrial.cpp capd/capdAlg/src/capd/vectalg/Multiindex.cpp\
      capd/capdDynSys4/src/capd/autodiff/DagIndexer.cpp capd/capdDynSys4/src/capd/autodiff/NodeType.cpp \
      capd/capdDynSys4/src/capd/map/Parser.cpp

main: DMapProblem.cpp
	g++ -O2 -I./capd/capdExt/include/ -I./capd/capdAlg/include/ -I./capd/capdDynSys4/include/ -I./capd/capdAux/include/ DMapProblem_simple_one.cpp ${FILES} -o main

${PROGS}: % : ${OBJDIR}%.o ${OTHERS_OBJ}
	${CXX} -o $@ $< ${OTHERS_OBJ} ${CXXLINK}

-include ${OBJ_FILES:%=%.d}

${OBJ_FILES}: ${OBJDIR}%.o : %.cpp
	@mkdir -p ${OBJDIR}
	$(CXX) ${CXXFLAGS} -MT $@ -MD -MP -MF ${@:%=%.d} -c -o $@ $<

.PHONY: clean
clean:
	rm -f ${OBJDIR}*.o ${OBJDIR}*.o.d ${PROGS}  

