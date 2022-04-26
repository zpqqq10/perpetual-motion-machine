LEX = lex
YACC = yacc -d

CXX = g++
INCLUDEDIR = include/
CXXFLAGS = -Wall -fPIC -I $(INCLUDEDIR)

OBJS=\
	src/main.o \
	src/y.tab.o \
	src/lex.yy.o 
	

maggot: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
src/lex.yy.o: src/lex.yy.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@
src/y.tab.o: src/y.tab.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@
src/lex.yy.c: src/maggot.l
	$(LEX) --outfile=$@ $^ 
src/y.tab.c src/y.tab.h: src/maggot.ypp
	$(YACC) $^ -o src/y.tab.c



clean:
	rm -rf $(OBJS) src/y.tab.c src/y.tab.h src/lex.yy.c maggot
