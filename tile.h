//Tile constants
const int TOTAL_TILES = 1376;

const int MAP_WIDTH = 1290;
const int MAP_HEIGHT = 960;

const int TILE_WIDTH = 30;
const int TILE_HEIGHT = 30;
const int TOTAL_TILE_SPRITES = 9;

//The different tile sprites
const int TILE_SNOW = 0;
const int TILE_GRASS = 1;
const int TILE_TREE[6] = {2,3,4,5,6,7};

int LAST_TILE = TILE_TREE[5];

SDL_Rect gTileClips[ TOTAL_TILE_SPRITES ];

std::string mapStr = "resources/floor_tiles/map0.map";

//The tile
class Tile
{
public:
  //Initializes position and type
  Tile( int x, int y, int tileType );

  //Shows the tile
  void render( SDL_Rect& camera, bool useSubstitute );

  //Get the tile type
  int getType();

  //Get the collision box
  SDL_Rect getBox();

  //Set to true if player can go behind tile
  bool renderOver;
  int substituteTileType;

private:
  //The attributes of the tile
  SDL_Rect mBox;

  //The tile type
  int mType;
};

Tile* tileSet[ TOTAL_TILES ];
