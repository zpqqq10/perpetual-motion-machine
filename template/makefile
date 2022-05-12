LEX = lex
YACC = yacc -d

CXX = clang++
# CXX = g++
INCLUDEDIR = include/
CXXFLAGS = -Wall -fPIC -I $(INCLUDEDIR) `llvm-config --cxxflags --ldflags --system-libs --libs core` -fno-rtti -frtti
# CXXFLAGS = `llvm-config --cxxflags --ldflags --system-libs --libs core` -fno-rtti

OBJS=\
	src/main.o \
	src/utils.o \
	src/y.tab.o \
	src/lex.yy.o
	

maggot: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
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
	rm -rf $(OBJS) src/y.tab.c src/y.tab.h src/lex.yy.c maggot src/y.output
