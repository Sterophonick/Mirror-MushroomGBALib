# -----------------------------------------------------------------------------
# Makefile for compiling libmushroom.a
# You will need to set GCC_DIR in the file: <mushroom>/build/Makefile_defines
# You shouldn't need to edit anything in this file
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Mushroom Directory
# -----------------------------------------------------------------------------

MUSHROOM_DIR = ..

# -----------------------------------------------------------------------------
# Project Settings
# -----------------------------------------------------------------------------

PROJECT_NAME    = mushroom
PROJECT_VERSION = 0.7
PROJECT_DIR     = ..

# -----------------------------------------------------------------------------
# Standard Defines
# -----------------------------------------------------------------------------

include $(MUSHROOM_DIR)/build/Makefile_defines

# -----------------------------------------------------------------------------
# Directory to create the lib in
# -----------------------------------------------------------------------------

OUTPUT_DIR = $(PROJECT_DIR)/lib

# -----------------------------------------------------------------------------
# Flags
# -----------------------------------------------------------------------------

CFLAGS = -O $(INC_DIRS) -I -mthumb -mthumb-interwork -std=c99 -Wall -pedantic

# -----------------------------------------------------------------------------
# Files
# -----------------------------------------------------------------------------

O_FILES_C    = mushroom.o
O_FILES_DATA = font_milkbottle.raw.o \
               fontmap_milkbottle.o

O_FILES_C_FULLPATH    = $(addprefix $(O_DIR)/, $(O_FILES_C))
O_FILES_DATA_FULLPATH = $(addprefix $(DATA_DIR)/, $(O_FILES_DATA))

O_FILES = $(O_FILES_C_FULLPATH) $(O_FILES_DATA_FULLPATH)

FINAL = $(OUTPUT_DIR)/lib$(PROJECT_NAME).a

# -----------------------------------------------------------------------------
# Main Target
# -----------------------------------------------------------------------------

all : $(FINAL)
	@echo ">>> Done (all)"

$(FINAL) : $(O_FILES)
	@echo ">>> Creating library ($(@F))"
	@$(AR) rcs $@ $(O_FILES)

$(O_FILES_C_FULLPATH) : $(O_DIR)/%.o : $(SRC_DIR)/%.c
	@echo ">>> Compiling ($(<F) -> $(@F))"
	@$(CC) -c $(CFLAGS) $< -o $@

$(O_FILES_DATA_FULLPATH) :
	@echo ">>> Compiling Data"
	@$(MAKE) --no-print-directory -C $(DATA_DIR)

# -----------------------------------------------------------------------------
# Dependencies
# -----------------------------------------------------------------------------

$(O_DIR)/mushroom.o : 	../src/mushroom.c					\
						../include/mushroom/mushroom.h		\
						../include/mushroom/msh_system.h	\
						../include/mushroom/msh_gba.h		\
						../include/mushroom/msh_data.h		\
						../include/mushroom/msh_debug.h		\
						../include/mushroom/msh_dma.h		\
						../include/mushroom/msh_irq.h		\
						../include/mushroom/msh_disp.h		\
						../include/mushroom/msh_key.h		\
						../include/mushroom/msh_bg.h		\
						../include/mushroom/msh_pal.h		\
						../include/mushroom/msh_obj.h		\
						../include/mushroom/msh_bitmap.h	\
						../include/mushroom/msh_timer.h		\
						../include/mushroom/msh_sound.h		\
						../include/mushroom/msh_comm.h		\
						../include/mushroom/msh_sram.h		\
						../include/mushroom/msh_math.h		\
						../include/mushroom/msh_hud.h		\
						../src/msh_debug.c					\
						../src/msh_dma.c					\
						../src/msh_irq.c					\
						../src/msh_key.c					\
						../src/msh_bg.c						\
						../src/msh_obj.c					\
						../src/msh_bitmap.c					\
						../src/msh_sram.c					\
						../src/msh_math.c					\
						../src/msh_hud.c					\
						../src/msh_data.c

# -----------------------------------------------------------------------------
# Other Rules
# -----------------------------------------------------------------------------

.PHONY : clean distclean doc depends dist tests runtests cleantests

#install :
#	$(CP) -R $(PROJECT_DIR)/include/* $(GCC_DIR)/include/
#	$(CP) $(PROJECT_DIR)/lib/libmushroom.a $(GCC_DIR)/lib/

clean :
	@echo ">>> Removing output and temporary files"
	@-$(RM) $(FINAL)
	@-$(RM) $(O_DIR)/*.o
	@-$(MAKE) --no-print-directory -C $(DATA_DIR) clean
	@echo ">>> Done (clean)"

distclean : clean cleantests
	@echo ">>> Removing all previously generated files"
	@-$(RM) $(PROJECT_DIR)/doc/*
	@echo ">>> Done (distclean)"

doc :
	@echo ">>> Generating documentation"
	@$(DOXYGEN) $(PROJECT_DIR)/build/doxygen/Doxyfile
	@echo ">>> Done (doc)"

depends :
	@echo ">>> Generating dependancy list (mushroom.d)"
	@$(CC) -MM $(SRC_DIR)/mushroom.c >> $(SRC_DIR)/mushroom.d
	@echo ">>> Done (depends)"

dist : distclean all doc
	@echo ">>> Creating distribution"
	@cd $(PROJECT_DIR)/..; tar -czf mushroom-$(PROJECT_VERSION).tar.gz mushroom/
	@echo ">>> Done (dist)"

tests :
	@echo ">>> Compiling test suite"
	@$(MAKE) -C$(PROJECT_DIR)/tests --no-print-directory
	@echo ">>> Done (tests)"

runtests :
	@echo ">>> Running test suite"
	@$(MAKE) -C$(PROJECT_DIR)/tests run --no-print-directory
	@echo ">>> Done (runtests)"

cleantests :
	@echo ">>> Cleaning test suite"
	@$(MAKE) -C$(PROJECT_DIR)/tests clean --no-print-directory
	@echo ">>> Done (cleantests)"

