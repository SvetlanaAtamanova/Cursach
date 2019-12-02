#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include "constants.h"

class Ball: public QObject, public QGraphicsEllipseItem{
  Q_OBJECT

public:
  Ball(QGraphicsItem *parent=nullptr);
  double getCenterX();

public slots:
  void move();

private:
  double speedX_;
  double speedY_;
  bool changeDirection();
  void collisionWithItems();
//  void collisionWithBar();
};

#endif // BALL_H
