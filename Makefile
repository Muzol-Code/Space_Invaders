PROJECT_NAME := Space_Invaders.exe
CXX := clang++
CXX_FLAGS := -Wall
LIB_FLAGS := -lSDL2main -lSDL2 -lSDL2_ttf
LIB := -L./dep/SDL2/lib/x64 -L./dep/SDL2_ttf/lib/x64
INCLUDE := -I./dep/SDL2/include -I./dep/SDL2_ttf/include
SRC := ./src/main.cpp ./src/entity/entity.cpp ./src/widget/button.cpp ./src/widget/text.cpp ./src/widget/widget.cpp 
OBJ := obj/main.o obj/entity.o obj/button.o obj/text.o obj/widget.o 

bin/$(PROJECT_NAME): $(OBJ) 
	$(CXX) $^ -o $@ $(CXX_FLAGS) $(LIB) $(LIB_FLAGS)

obj/main.o: ./src/main.cpp 
	$(CXX) -c $< -o $@ $(CXX_FLAGS) $(INCLUDE)
obj/entity.o: ./src/entity/entity.cpp ./src/entity/entity.hpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS) $(INCLUDE)
obj/button.o: ./src/widget/button.cpp ./src/widget/button.hpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS) $(INCLUDE)
obj/text.o: ./src/widget/text.cpp ./src/widget/text.hpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS) $(INCLUDE)
obj/widget.o: ./src/widget/widget.cpp ./src/widget/widget.hpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS) $(INCLUDE)


run:
	bin/$(PROJECT_NAME)
