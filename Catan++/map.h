//Defines
#ifndef __MAP_H__
#define __MAP_H__

//Include
#include <stdio.h>
#include <stdlib.h>
#include "renderer.h"

//Class defines
class Edge;
class Vertex;

//Tile enums
enum eTile {
	TILE_HILL,
	TILE_FOREST,
	TILE_MOUNTAIN,
	TILE_FIELD,
	TILE_PASTURE,
	TILE_DESERT
};

//Sprite enums
enum eSprite {
	SPRITE_BACKSLASH = 13,
	SPRITE_FORWARDSLASH,
	SPRITE_PIPE,
	SPRITE_TOWN
};

//Tile
class Tile {
public:
	Tile(int _x, int _y, int _z, eTile _type, int _value, bool _robber);
	std::vector<Tile*> tiles;
	std::vector<Edge*> edges;
	std::vector<Vertex*> vertices;
	int x, y, z;
	eTile type;
	int value;
	bool robber;
};

//Edge
class Edge {
public:
	Edge();
	std::vector<Tile*> tiles;
	std::vector<Edge*> edges;
	std::vector<Vertex*> vertices;
	bool road;
};

//Vertex
class Vertex {
public:
	Vertex();
	std::vector<Tile*> tiles;
	std::vector<Edge*> edges;
	std::vector<Vertex*> vertices;
	bool town;
	bool city;
};

//Map
class Map {
public:
	Map();
	void render(Renderer& r);
	void addTile(int x, int y, int z, std::vector<eTile>& t, std::vector<int>& v);
	std::vector<Tile> tiles;
	std::vector<Edge> edges;
	std::vector<Vertex> vertices;
	std::vector<Sprite> sprites;
};

#endif