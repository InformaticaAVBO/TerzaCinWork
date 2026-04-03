#
# --- makefile ---
#

# Compilatore
cxx = g++

#Flag di compilazione
cxxflags = -g -std=c++17 -Wall -Wextra

# Nome dell'eseguibile
target = SlotMachine.exe

# File sorgente
sources = $(wildcard *.cpp)

# File oggetto
objs = $(sources:.cpp=.o)

# Pulizia dei file oggetto e dell'eseguibile
clean:
	rm -f $(objs) $(target)

# Regola di compilazione
$(target): $(sources)
	$(cxx) $(cxxflags) -o $@ $^

# Regola per compilare i file oggetto
%.o: %.cpp
	$(cxx) $(cxxflags) -c $< -o $@

# Regola predefinita
all: $(target)

