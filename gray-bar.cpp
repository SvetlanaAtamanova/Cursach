#include <QBrush>
#include "gray-bar.h"

GrayBar::GrayBar(int x, int y, int height, int width, QGraphicsItem *parent):
  QGraphicsRectItem(parent)
{
  setRect(x, y, height, width);
  setBrush(Qt::gray);
}
