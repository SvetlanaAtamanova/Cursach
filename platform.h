#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "constants.h"

class Platform: public QGraphicsRectItem{

public:
  Platform(QGraphicsItem* parent=nullptr);
  void keyPressEvent(QKeyEvent *event);
  double getCenterX();
};

#endif // PLATFORM_H
