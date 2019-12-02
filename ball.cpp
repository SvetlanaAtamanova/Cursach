#include "ball.h"
#include "game.h"

#include <QBrush>
#include <QTimer>

extern ArcanoidGame *game;

Ball::Ball(QGraphicsItem *parent):
  QObject(), QGraphicsEllipseItem(parent),
  speedX_(0),
  speedY_(-3)
{
  setRect(0, 0, HEIGTH_BALL, WIDTH_BALL);
  setBrush(Qt::darkCyan);

  QTimer *timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));
  timer->start(10);
}


double Ball::getCenterX(){
  return x() + rect().width()/2;
}

void Ball::move(){
  collisionWithItems();
//  collisionWithBar();
  moveBy(speedX_, speedY_);
  if(!changeDirection()){
    game->destroyBall();
    game->deleteAllBars();
    game->gameOver("Game over");
  }
}


bool Ball::changeDirection(){
// лево или право
  if ((mapToScene(rect().topLeft()).x() <= 0) || (mapToScene(rect().topRight()).x() >= game->width()))
    speedX_ = -1 * speedX_;

// верх
  else if (mapToScene(rect().topLeft()).y() <= 0)
    speedY_ = -1 * speedY_;

// низ
  else if (mapToScene(rect().topLeft()).y() >= game->height())
    //speedY_ = -1 * speedY_;
    return false;

  return true;
}


void Ball::collisionWithItems(){
  QList<QGraphicsItem*> collidItems = collidingItems();
  for (int i = 0; i < collidItems.size(); ++i){
    Platform *platform = dynamic_cast<Platform*>(collidItems[i]);
    Bar *bar = dynamic_cast<Bar*>(collidItems[i]);

    if (platform){

      double ballX = getCenterX();
      double platformX = platform->getCenterX();

      speedY_ = -1 * speedY_;
      speedX_ = (speedX_ + (ballX - platformX))/15;
    }


    if (bar){
      int displasment = 4;

      //double ballX = pos().x();
      //double barX = bar->pos().x();
      double ballY = pos().y();
      double barY = bar->pos().y();

      // удар снизу или сверху
      if ((ballY > barY + displasment && speedY_ < 0) || (barY > ballY + displasment && speedY_ > 0 ))
        speedY_ = -1 * speedY_;

      // удар справа или слева
      //(ballX > barX + displasment && speedX_ < 0) || (barX > ballX + displasment && speedX_ > 0 )
      else
        speedX_ = -1 * speedX_;

      if(!bar->decreaseDegree()){
        game->deleteBar(bar);
        game->getScore()->increaseScore();
      }
    }
    return;
  }
}






/*void Ball::collisionWithBar(){
  QList<QGraphicsItem*> collidItems = collidingItems();
  for (size_t i = 0; i < collidItems.size(); ++i){
    Bar *bar = dynamic_cast<Bar*>(collidItems[i]);
    if (bar){
      int displasment = 4;

      double ballX = pos().x();
      double ballY = pos().y();

      double barX = bar->pos().x();
      double barY = bar->pos().y();

      // удар снизу или сверху
      if ((ballY > barY + displasment && speedY_ < 0) || (barY > ballY + displasment && speedY_ > 0 ))
        speedY_ = -1 * speedY_;

      // удар справа или слева
      else
        speedX_ = -1 * speedX_;

      if(!bar->decreaseDegree()){
        game->deleteBar(bar);
        game->getScore()->increaseScore();
      }
    }
  }
}*/


