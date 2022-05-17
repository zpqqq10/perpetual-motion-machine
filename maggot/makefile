LEX = lex
YACC = yacc -d

CXX = clang++
# CXX = g++
INCLUDEDIR = include/
CXXFLAGS = -Wall -fPIC -I $(INCLUDEDIR) `llvm-config --cxxflags` -fno-rtti -frtti
# CXXFLAGS = `llvm-config --cxxflags --ldflags --system-libs --libs core` -fno-rtti
LLVMFLAGS = `llvm-config --system-libs --ldflags --libs core`
OBJS=\
	src/main.o \
	src/utils.o \
	src/y.tab.o \
	src/lex.yy.o \
	src/codeGen.o \
	lib/libstd.o

maggot: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LLVMFLAGS) $(OBJS) -o $@ 
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
src/lex.yy.o: src/lex.yy.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
src/y.tab.o: src/y.tab.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
src/lex.yy.cpp: src/maggot.l
	$(LEX) --outfile=$@ $^ 
src/y.tab.cpp src/y.tab.h: src/maggot.ypp
	$(YACC) $^ -v -o src/y.tab.cpp



clean:
	rm -rf $(OBJS) src/y.tab.cpp src/y.tab.hpp src/lex.yy.cpp maggot src/y.output
