#include <QTimer>
#include "ball.h"
#include "game.h"

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

void Ball::deleteBall(){
  delete(game->getBall());
}

void Ball::move(){
  collisionWithItems();
  moveBy(speedX_, speedY_);
  if(!changeDirection()){
    deleteBall();
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
    GrayBar *grayBar = dynamic_cast<GrayBar*>(collidItems[i]);

    if (platform){
      double ballX = getCenterX();
      double platformX = platform->getCenterX();

      speedY_ = -1 * speedY_;
      speedX_ = (speedX_ + (ballX - platformX))/20;
    }

    if (grayBar){
      double ballY = pos().y();
      double barY = grayBar->pos().y();
      if ((ballY >= barY && speedY_ < 0) || (barY >= ballY && speedY_ > 0 ))
        speedY_ = -1 * speedY_;
      else
        speedX_ = -1 * speedX_;
    }

    if (bar){
      double ballY = pos().y();
      double barY = bar->pos().y();

      // удар снизу или сверху
      if ((ballY >= barY && speedY_ < 0) || (barY >= ballY && speedY_ > 0 ))
        speedY_ = -1 * speedY_;
      // удар справа или слева
      else
        speedX_ = -1 * speedX_;

      if(!bar->decreaseDegree()){
        game->deleteBar(bar);
        game->getScore()->increaseScore();
        if (game->getScore()->checkScore()){
          speedX_ = 0;
          speedY_ = 0;
          game->destroyBall();
          game->increaseLevel();
          game->gameOver("You win");
        }
      }
    }
    return;
  }
}


