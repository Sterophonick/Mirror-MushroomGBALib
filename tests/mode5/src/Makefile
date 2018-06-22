# -----------------------------------------------------------------------------
# Mushroom Makefile
# The main Makefile for your project
#
# You will need to modify this file as well as mushroom/build/Makefile_defines
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Set the directory where Mushroom exists
# You should enter the full path. eg. /home/molasses/gbadev/mushroom
# -----------------------------------------------------------------------------

MUSHROOM_DIR = ../../..

# -----------------------------------------------------------------------------
# Project Settings
# -----------------------------------------------------------------------------

PROJECT_NAME = mode5
PROJECT_DIR  = ..

# -----------------------------------------------------------------------------
# Set DATA to YES if you want compile your data directory and link it to
# your ROM. You will need to edit more data settings below
# -----------------------------------------------------------------------------

DATA = YES

# -----------------------------------------------------------------------------
# TITLE of GBA ROM
# Max. 12 characters (uppercase)
# -----------------------------------------------------------------------------

TITLE = "UNTITLED    "

# -----------------------------------------------------------------------------
# GAMECODE
# A??J : Japan/Asia
# A??E : USA
# A??P : Europe, Australia, Africa
# Middle 2 characters are generally an abbreviation of the title
# -----------------------------------------------------------------------------

GAMECODE = AXXE

# -----------------------------------------------------------------------------
# MAKERCODE
# 2 characters (uppercase). ID of game maker/company
# -----------------------------------------------------------------------------

MAKERCODE  = XX

UNITCODE   = 0x00
DEVICETYPE = 0x00
MASKROM    = 0x00
PADDING    = YES
#PADDATA    = "................"

# -----------------------------------------------------------------------------
# Project Files
# List the object files that will make up the project
# eg. O_FILES = $(PROJECT_NAME).o \
#               somefile.o \
#               someotherfile.o
# -----------------------------------------------------------------------------

O_FILES = $(PROJECT_NAME).o

# -----------------------------------------------------------------------------
# This includes the standard Makefile_defines
# -----------------------------------------------------------------------------

include $(MUSHROOM_DIR)/build/Makefile_defines

# -----------------------------------------------------------------------------
# Data Files
# Here is where you specify the files used in creating your data
# You need to write your data rules in the section below Makefile_rules
# -----------------------------------------------------------------------------

BALK_SRC_FILES =	$(DATA_DIR)/gfx/balkhalf_256.bmp
BALK_O_FILES   =	balkhalf_256.raw.o

BALK_C_FILES = $(patsubst %.o, %.c, $(BALK_O_FILES))

BALK_O_FILES_FULLPATH = $(addprefix $(O_DIR)/, $(BALK_O_FILES))
BALK_C_FILES_FULLPATH = $(addprefix $(O_DIR)/, $(BALK_C_FILES))

# -----------------------------------------------------------------------------
# List your data .o files here
# They will be compiled from .c to .o and then into the data.a file
# -----------------------------------------------------------------------------

DATA_O_FILES_FULLPATH = $(BALK_O_FILES_FULLPATH)

# -----------------------------------------------------------------------------
# Here you can list any generated data files that should be cleaned when
# the clean rule is executed
# -----------------------------------------------------------------------------

DATA_CLEAN_FILES_FULLPATH = $(BALK_C_FILES_FULLPATH)

# -----------------------------------------------------------------------------
# This includes the standard Makefile_rules
# -----------------------------------------------------------------------------

include $(MUSHROOM_DIR)/build/Makefile_rules

# -----------------------------------------------------------------------------
# Data rules
# Here is where you need write all your data rules
# -----------------------------------------------------------------------------

$(BALK_C_FILES_FULLPATH) : $(BALK_SRC_FILES)
	@$(GFX2GBA) $(GFX2GBAFLAGS) -c32k $<

# -----------------------------------------------------------------------------
# Dependencies
# List all the source files used in building each object file
# eg. $(O_DIR)/somefile.o : $(SRC_DIR)/somefile.c $(SRC_DIR)/somefile.h \
#                           $(SRC_DIR)/funcs.c $(SRC_DIR)/funcs.h
# -----------------------------------------------------------------------------

$(O_DIR)/$(PROJECT_NAME).o : $(SRC_DIR)/$(PROJECT_NAME).c

