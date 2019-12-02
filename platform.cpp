#include "platform.h"
#include <QBrush>
#include <game.h>

extern ArcanoidGame *game;

Platform::Platform(QGraphicsItem *parent){
  setRect(0, 0, HEIGTH_PLATFORM, WIDTH_PLATFORM);
  setBrush(Qt::magenta);
}

void Platform::keyPressEvent(QKeyEvent *event){
  if(event->key() == Qt::Key_Left){
    if(pos().x() - 10 > 0){
      setPos(x() - MOVE_PLATFORM, y());
    }
  }
  else if(event->key() == Qt::Key_Right){
    if(pos().x() + HEIGTH_PLATFORM < HEIGTH_SCENE){
      setPos(x() + MOVE_PLATFORM, y());
    }
  }
  else if(event->key() == Qt::Key_Space){
    if(game->getBall() == nullptr){
      game->drawBall();
    }
  }

}

double Platform::getCenterX(){
  return x()+rect().width()/2;
}

