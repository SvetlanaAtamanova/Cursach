#include "button.h"
#include "constants.h"

#include <QGraphicsTextItem>
#include <QBrush>


Button::Button(QString name, QGraphicsItem *parent):
  QGraphicsRectItem(parent),
  text_(new QGraphicsTextItem(name,this))
{
  setRect(0,0,WIDTH_BUTTON,HEIGTH_BUTTON);
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::darkCyan);
  setBrush(brush);

  text_->setDefaultTextColor(Qt::darkMagenta);
  int xPos = rect().width()/2 - text_->boundingRect().width()/2;
  int yPos = rect().height()/2 - text_->boundingRect().height()/2;
  text_->setPos(xPos,yPos);

  setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
  clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::cyan);
  setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::darkCyan);
  setBrush(brush);
}
