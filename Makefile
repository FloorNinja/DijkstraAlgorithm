# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =   -std=c++11 -I.
CXXFLAGS =   -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS +=  -std=c++11 
CXXFLAGS +=  -g
CXXFLAGS +=  $(DEPFLAGS)
LDFLAGS =    -g
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = DijkstraAlgorithm test_graph_small test_nodeset test_dijkstra test_graph_nofile

all: $(PROGS)

run: DijkstraAlgorithm
	./DijkstraAlgorithm

test: test_graph_small test_nodeset test_dijkstra test_graph_nofile
	./test_graph_small
	./test_nodeset
	./test_dijkstra
	./test_graph_nofile

test_small: test_graph_small
	./test_graph_small

test_ns: test_nodeset
	./test_nodeset

test_dij: test_dijkstra
	./test_dijkstra

test_nf: test_graph_nofile
	./test_graph_nofile

# Targets rely on implicit rules for compiling and linking
DijkstraAlgorithm: DijkstraAlgorithm.o dijkstra.o graph.o nodeset.o node.o edge.o
test_graph_small: test_graph_small.o graph.o node.o edge.o
test_nodeset: test_nodeset.o nodeset.o node.o edge.o
test_dijkstra: test_dijkstra.o dijkstra.o nodeset.o node.o edge.o
test_graph_nofile: test_graph_nofile.o graph.o nodeset.o node.o edge.o

# Phony targets
.PHONY: all run test test_small test_ns test_dij test_nf clean distclean purge

# Standard clean
clean:
	rm -f *.o

distclean: clean
	rm *.d

purge: distclean
	rm $(PROGS)


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
