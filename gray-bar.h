#ifndef GRAYBAR_H
#define GRAYBAR_H

#include <QGraphicsRectItem>

class GrayBar: public QGraphicsRectItem{

public:
  GrayBar(int x, int y, int height, int width, QGraphicsItem *parent=nullptr);
};

#endif // GRAYBAR_H
