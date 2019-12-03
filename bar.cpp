#include <QBrush>
#include "bar.h"


Bar::Bar(QGraphicsItem *parent):
  QGraphicsRectItem(parent)
{
  setRect(0,0, HEIGTH_BAR, WIDTH_BAR);
  setDegree(BarDegree::EASY);
}

void Bar::setDegree(BarDegree degree){
  this->degree_ = degree;
  switch(degree){
  case ULTRA_HARD:
    setBrush(Qt::green);
    break;
  case HARD:
    setBrush(Qt::blue);
    break;
  case MEDIUM:
    setBrush(Qt::yellow);
    break;
  case EASY:
    setBrush(Qt::cyan);
  }
}

bool Bar::decreaseDegree(){
  if((degree_) - 1 > 0){
    setDegree(BarDegree((degree_) - 1));
    return true;
  }
  else
    return false;
}

