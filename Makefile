EXE  =		WebScrap
DEBUG = 	yes
CXX =		g++

# dir
SRC_DIR =       src
INC_DIR =       inc
OBJ_DIR =       obj

# sources
PROJ_SRC_LIST = main.cpp \
				com.cpp

# objects
PROJ_OBJ_LIST = $(PROJ_SRC_LIST:.cpp=.o)

#paths
PROJ_SRC =		$(addprefix $(SRC_DIR)/, $(PROJ_SRC_LIST))
PROJ_OBJ =		$(addprefix $(OBJ_DIR)/, $(PROJ_OBJ_LIST))

ifeq ($(DEBUG),yes)
CXXFLAGS = -Wall -Wextra -ansi -pedantic -g -Weffc++
else
CXXFLAGS = -w -Wall -Werror -s -O2
endif

IFLAGS =		-I./inc -I./lib

#libs
LFLAGS =	


all :		 	$(EXE)

$(EXE) :        $(PROJ_OBJ)
	@$(CXX) $(CXXFLAGS) $(IFLAGS) -o $@ $(PROJ_OBJ) $(LFLAGS)
	@echo "Compiling "$(EXE)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp 
	@$(shell mkdir obj >/dev/null 2>&1)
	@$(CXX) $(CXXFLAGS) $(IFLAGS) -c -o $@ $<
	@echo "Compiling" $<

clean :
	@echo "Cleaning Object"
	@$(RM) $(PROJ_OBJ)
	@$(shell rmdir obj >/dev/null 2>&1)

fclean :	    clean
	@echo "Removing Binary"
	$(RM) $(EXE)

re :		    fclean all

.PHONY :	    all, clean, fclean, re

.SILENT :
