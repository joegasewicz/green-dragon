//
// Created by Joe Geezer on TILE_STONE_FLOORTILE_SWAMP/TILE_BUSHESTILE_SEA/TILE_CLAYTILE_BUSHESTILE_CLAYTILE_CLAY.
//

#ifndef GREEN_DRAGON_LEVELS_H
#define GREEN_DRAGON_LEVELS_H

#define TILE_ARRAY_SIZE 144
#define TILE_BUSHES 0
#define TILE_STONE_FLOOR 1
#define TILE_CLAY 2
#define TILE_RIVER 3
#define TILE_GRASS 4
#define TILE_STONE_FLOOR_OLD 5
#define TILE_SWAMP 6
#define TILE_SEA 7



extern int level_one_tiles[TILE_ARRAY_SIZE];


void get_level_one_tiles(int level_one[TILE_ARRAY_SIZE], const int tiles[TILE_ARRAY_SIZE]);



#endif //GREEN_DRAGON_LEVELS_H
