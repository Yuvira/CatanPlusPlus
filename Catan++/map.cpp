//Include
#include "map.h"

//Tile constructor
Tile::Tile(int _x, int _y, int _z, eTile _type, int _value, bool _robber) {
	x = _x;
	y = _y;
	z = _z;
	type = _type;
	value = _value;
	robber = _robber;
}

//Edge constructor
Edge::Edge() {}

//Vertex constructor
Vertex::Vertex() {}

//Map constructor
Map::Map() {

	//Sprites
	for (int a = 0; a < 10; ++a) { sprites.push_back(Sprite(" " + std::to_string(a) + " ")); }
	sprites.push_back(Sprite("1 0"));
	sprites.push_back(Sprite("1 1"));
	sprites.push_back(Sprite("1 2"));
	sprites.push_back(Sprite("\\"));
	sprites.push_back(Sprite("/"));
	sprites.push_back(Sprite("|"));
	sprites.push_back(Sprite("ø"));

	//Tiles
	tiles.push_back(Tile(0, 0, 0, TILE_DESERT, 0, true));
	std::vector<eTile> t;
	for (int a = 0; a < 3; ++a) { t.push_back(TILE_HILL); }
	for (int a = 0; a < 4; ++a) { t.push_back(TILE_FOREST); }
	for (int a = 0; a < 3; ++a) { t.push_back(TILE_MOUNTAIN); }
	for (int a = 0; a < 4; ++a) { t.push_back(TILE_FIELD); }
	for (int a = 0; a < 4; ++a) { t.push_back(TILE_PASTURE); }
	std::vector<int> v = { 2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12 };
	std::vector<std::vector<int>> c = { { 0, 1, -1 }, { -1, 0, -1 }, { 1, 1, 0 }, { -1, -1, 0 }, { 1, 0, 1}, { 0, -1, 1 } };
	for (int a = -2; a < 3; ++a) {
		if (a != 0) {
			addTile(a, 0, 0, t, v);
			addTile(0, a, 0, t, v);
			addTile(0, 0, a, t, v);
		}
	}
	for (int a = 0; a < c.size(); ++a) { addTile(c[a][0], c[a][1], c[a][2], t, v); }

}

//Add tile to list
void Map::addTile(int x, int y, int z, std::vector<eTile>& t, std::vector<int>& v) {
	int r1 = rand() % t.size();
	int r2 = rand() % v.size();
	tiles.push_back(Tile(x, y, z, t[r1], v[r2], false));
	t.erase(t.begin() + r1);
	v.erase(v.begin() + r2);
}

//Render map
void Map::render(Renderer& r) {

	//Loop and draw tiles
	for (int a = 0; a < tiles.size(); ++a) {
		r.render(sprites[tiles[a].value], 24 + (tiles[a].x * 8) + (tiles[a].y * 4) + (tiles[a].z * 4), 25 - (tiles[a].y * 4) + (tiles[a].z * 4));
	}

}