#ifndef BAR_H
#define BAR_H

#include <QGraphicsRectItem>
#include "constants.h"

class Bar: public QGraphicsRectItem{

public:
  Bar(QGraphicsItem* parent=nullptr);
  void setDegree(BarDegree degree_);
  bool decreaseDegree();

private:
  BarDegree degree_;

};

#endif // BAR_H
