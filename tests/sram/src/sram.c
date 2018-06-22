
#define MSH_DEBUG
#include <mushroom/mushroom.h>

struct options_st {
	char	saveid[3];
	bool	cheatmode;
	bool	goremode;
	u16		highscore;
	char	highname[3];
} PACKED;

struct savegame_st {
	char	saveid[4];
	u8		level;
	u8		lives;
	u16		score;
} PACKED;

typedef struct options_st options_t;
typedef struct savegame_st savegame_t;

#define OPTIONS_SIZE	(sizeof(options_t))
#define SAVEGAME_SIZE	(sizeof(savegame_t))

void AgbMain () {
	options_t options;
	savegame_t savegame;

	set_disp_frcblk(TRUE);
	set_disp_mode(0);
	set_disp_frcblk(FALSE);

	set_bgpal_color(0, RGB(25, 25, 25));
	dtext_init(31, 32, 0, 0);

	set_bg(0, BG_SIZE_256x256, BG_COLMOD_16, 0, 31);
	set_disp_bg(0, TRUE);

	if (sram_exists("OPT", 3, 0, 0, 0)) {
		dtext(1, 1, "Options Exist");

		load_from_sram((void *)&options, 0, OPTIONS_SIZE, 0);

		dtext(1, 4, "HI: %s %u", options.highname, options.highscore);
		dtext(1, 5, "CHEATER: %u", options.cheatmode);
		dtext(1, 6, "BLOODY: %u", options.goremode);
	} else {
		dtext(1, 1, "Options Not Found");

		options.saveid[0]   = 'O';
		options.saveid[1]   = 'P';
		options.saveid[2]   = 'T';
		options.cheatmode   = TRUE;
		options.goremode    = TRUE;
		options.highscore   = 31337;
		options.highname[0] = 'M';
		options.highname[1] = 'O';
		options.highname[2] = 'L';

		save_to_sram((void *)&options, 0, OPTIONS_SIZE, 0);
	}

	if (sram_exists("SAVE", 4, 0, SAVEGAME_SIZE, OPTIONS_SIZE)) {
		dtext(1, 2, "Save Game Exists");

		load_from_sram((void *)&savegame, 0, SAVEGAME_SIZE, OPTIONS_SIZE);

		dtext(1, 8, "Level: %u", savegame.level);
		dtext(1, 9, "Lives: %u", savegame.lives);
		dtext(1, 10, "Score: %u", savegame.score);
	} else {
		dtext(1, 2, "Save Game Not Found");

		savegame.saveid[0] = 'S';
		savegame.saveid[1] = 'A';
		savegame.saveid[2] = 'V';
		savegame.saveid[3] = 'E';
		savegame.level     = 2;
		savegame.lives     = 3;
		savegame.score     = 2600;

		save_to_sram((void *)&savegame, 0, SAVEGAME_SIZE, OPTIONS_SIZE);
	}

	hexdump((void *)MEM_SRAM, 256);

	while (1) {
		key_update();

		if (key_down(KEY_A)) {
			dtext(1, 12, "Options Deleted");
			erase_sram(3, 0, 0, 0);
			dprintf("\n");
			hexdump((void *)MEM_SRAM, 256);
		}

		if (key_down(KEY_B)) {
			dtext(1, 13, "Save Game Deleted");
			erase_sram(4, 0, SAVEGAME_SIZE, OPTIONS_SIZE);
			dprintf("\n");
			hexdump((void *)MEM_SRAM, 256);
		}
	}
}

