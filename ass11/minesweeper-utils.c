#include <stdio.h>
#include <stdlib.h>
#include "minesweeper-utils.h"

typedef struct {
    char state;
    bool is_visible;
} Tile;

typedef Tile* Row;
typedef struct Map {
    unsigned short int width;
    unsigned short int height;
    Row* grid;
} Map;

Map* create_map(unsigned short int width, unsigned short int height) {
    Map* ptrMap = (Map*) malloc(sizeof(width * height));
    // ptrMap->width = width;
    // ptrMap->height = height;
    ptrMap->grid[width][height];
    return ptrMap;
}

void destroy_map(Map* map) {
    free(map);
}

void set_tile(Map* map, unsigned short int column, unsigned short int row, char state, bool is_visible) {
    printf("hello\n");
    
    // map->grid = 0;
    // map->grid
    return;
}

void initialize_map(Map* map, float probability) {

}

void print_map(const Map* map) {

}

void reveal_all_tiles(Map* map) {

}

bool all_empty_tiles_visible(const Map* map) {

}

bool is_bomb_tile(Map* map, unsigned short int column, unsigned short int row) {

}