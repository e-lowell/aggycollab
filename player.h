class Player {
 public:
  //Initializes the variables
  Player();

  //Takes key presses
  void handleEvent(SDL_Event& e);

  //Moves the player
  void move(Tile *tiles[]);
	
  //Centers the camera over the player
  void setCamera(SDL_Rect& camera);

  SDL_Rect getBox();

  //Renders the player
  LTexture* gTexture;
  SDL_Rect gTextureClips[5];
  SDL_Rect* currentClip;
  int spriteWidth, spriteHeight;
  SDL_RendererFlip flipType = SDL_FLIP_NONE;
  void render(SDL_Rect& camera);

  float speedX, speedY;
 private:
  //Collision box of the player
  SDL_Rect mBox;

  //X-Y coordinates
  float posX, posY;
  
  //The velocity of the dot
  float mVelX, mVelY;
};

Player player;
