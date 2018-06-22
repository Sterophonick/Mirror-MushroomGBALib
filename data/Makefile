
#- Directories ---------------------------------------------------------------#

DATA_DIR = .
GFX_DIR  = $(DATA_DIR)/gfx
SRC_DIR  = $(DATA_DIR)/temp
O_DIR    = $(DATA_DIR)
GCC_DIR  = /home/molasses/Code/gba/tools/devkitadv

#- Executables ---------------------------------------------------------------#

CC		= $(GCC_DIR)/bin/arm-agb-elf-gcc
LD		= $(GCC_DIR)/bin/arm-agb-elf-ld
OBJCOPY	= $(GCC_DIR)/bin/arm-agb-elf-objcopy
AR		= $(GCC_DIR)/bin/arm-agb-elf-ar
RM		= rm
GFX2GBA = /home/molasses/Code/gba/tools/gfx2gba/gfx2gba

#- Flags ---------------------------------------------------------------------#

CFLAGS = -mthumb -mthumb-interwork

#- Files ---------------------------------------------------------------------#

O_FILES_DATA = font_milkbottle.raw.o fontmap_milkbottle.o
O_FILES_DATA_FULLPATH = $(addprefix $(O_DIR)/, $(O_FILES_DATA))
O_FILES = $(O_FILES_DATA_FULLPATH)

#- Main Target ---------------------------------------------------------------#

all : $(O_FILES)

$(O_FILES) : $(O_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@ -w

temp/font_milkbottle.raw.c : gfx/font_milkbottle.bmp
	@$(GFX2GBA) -fsrc -otemp -q -t8 -c16 -P $<

gfx/font_milkbottle.bmp :

temp/fontmap_milkbottle.c :
	@cp gfx/fontmap_milkbottle.c temp/

#- Other Targets -------------------------------------------------------------#

.PHONY : clean

clean :
	@-$(RM) $(O_FILES_DATA_FULLPATH)
#	@-$(RM) $(patsubst %.o, %.c, $(O_FILES_DATA_FULLPATH))
	@-$(RM) temp/font_milkbottle.raw.c temp/fontmap_milkbottle.c

