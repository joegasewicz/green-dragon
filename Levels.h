//
// Created by Joe Geezer on TILE_STONE_FLOORTILE_SWAMP/TILE_BUSHESTILE_SEA/TILE_CLAYTILE_BUSHESTILE_CLAYTILE_CLAY.
//

#ifndef GREEN_DRAGON_LEVELS_H
#define GREEN_DRAGON_LEVELS_H

#include <iostream>
#include <string>
#include <array>

#define TILE_ARRAY_SIZE 144
#define WORLD_ROW_TOTAL 8
#define WORLD_COLUMN_TOTAL 16
// TILES
#define TILE_BUSHES 0
#define TILE_STONE_FLOOR 1
#define TILE_CLAY 2
#define TILE_RIVER 3
#define TILE_GRASS 4
#define TILE_STONE_FLOOR_OLD 5
#define TILE_SWAMP 6
#define TILE_SEA 7


extern std::array<std::array<int, 128>, 2> level_one_screens[];

extern int level_one_tiles[TILE_ARRAY_SIZE];

void get_level_tiles(int level_one[TILE_ARRAY_SIZE], const int tiles[TILE_ARRAY_SIZE]);

void merge_screen_into_level(int level[TILE_ARRAY_SIZE], std::array<std::array<int, 128>, 2> screens);

#endif //GREEN_DRAGON_LEVELS_H
