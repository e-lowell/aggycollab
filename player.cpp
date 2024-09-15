Player::Player() {
  posX = 500;
  posY = 450;
  mBox.x = posX;
  mBox.y = posY;
  spriteWidth = 36;
  spriteHeight = spriteWidth;
  mBox.w = spriteWidth;
  mBox.h = mBox.w;
  speedX = 3;
  speedY = 3;
  gTexture = &gPlayerTexture;
}

SDL_Rect Player::getBox() {
  return mBox;
}

void Player::handleEvent( SDL_Event& e )
{
  //If a key was pressed
  if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
      //Adjust the velocity
      switch( e.key.keysym.sym )
        {
	case SDLK_UP: mVelY -= speedY; break;
	case SDLK_DOWN: mVelY += speedY; break;
	case SDLK_LEFT: mVelX -= speedX; break;
	case SDLK_RIGHT: mVelX += speedX; break;

        }
    }
  //If a key was released
  else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
      //Adjust the velocity
      switch( e.key.keysym.sym )
        {
	case SDLK_UP: mVelY += speedY; break;
	case SDLK_DOWN: mVelY -= speedY; break;
	case SDLK_LEFT: mVelX += speedX; break;
	case SDLK_RIGHT: mVelX -= speedX; break;
        }
    }
}

void Player::move( Tile *tiles[] )
{
  //Move the dot left or right
  posX += mVelX;
  mBox.x = posX;
  //If the dot went too far to the left or right
  if( ( mBox.x < 0 ) || ( mBox.x + spriteWidth > MAP_WIDTH ) || touchesWall(mBox, tiles) )
    {
      //Move back
      posX -= mVelX;
      mBox.x = posX;
    }

  //Move the dot up or down
  posY += mVelY;
  mBox.y = posY;

  //If the dot went too far up or down
  if( ( mBox.y < 0 ) || ( mBox.y + spriteHeight > MAP_HEIGHT ) || touchesWall(mBox, tiles) )
    {
      //Move back
      posY -= mVelY;
      mBox.y = posY;
    }
}

void Player::setCamera( SDL_Rect& camera )
{
  //Center the camera over the dot
  camera.x = ( posX + spriteWidth / 2 ) - SCREEN_WIDTH / 2;
  camera.y = ( posY + spriteHeight / 2 ) - SCREEN_HEIGHT / 2;

  //Keep the camera in bounds
  if( camera.x < 0 )
    { 
      camera.x = 0;
    }
  if( camera.y < 0 )
    {
      camera.y = 0;
    }
  if( camera.x > MAP_WIDTH - camera.w )
    {
      camera.x = MAP_WIDTH - camera.w;
    }
  if( camera.y > MAP_HEIGHT - camera.h )
    {
      camera.y = MAP_HEIGHT - camera.h;
    }
}

void Player::render(SDL_Rect& camera) {
  gTexture->mWidth = spriteWidth;
  gTexture->mHeight = spriteHeight;
  if(mVelX > 0)
    flipType = SDL_FLIP_NONE;
  else if(mVelX < 0)
    flipType = SDL_FLIP_HORIZONTAL;
  gTexture->render(posX + spriteWidth/2 - mBox.w/2 - camera.x, posY + spriteHeight/2 - mBox.h/2 - camera.y, currentClip, 0, NULL, flipType);
  //SDL_RenderFillRect(gRenderer, &mBox);
}
