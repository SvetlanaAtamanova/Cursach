#include <QGraphicsTextItem>
#include <QBrush>

#include "game.h"
#include "button.h"
#include "constants.h"


Button::Button(QString name, int posY, QGraphicsItem *parent):
  QGraphicsRectItem(parent),
  text_(new QGraphicsTextItem(name,this)),
  posX_(WIDTH_SCENE/2 - WIDTH_BUTTON/2),
  posY_(posY)
{
  setRect(0,0,WIDTH_BUTTON,HEIGTH_BUTTON);
  setPos(posX_,posY_);
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::darkCyan);
  setBrush(brush);

  text_->setDefaultTextColor(Qt::darkMagenta);
  double xPos = rect().width()/2 - text_->boundingRect().width()/2;
  double yPos = rect().height()/2 - text_->boundingRect().height()/2;
  text_->setPos(xPos,yPos);

  setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *){
  clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *){
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::cyan);
  setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *){
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::darkCyan);
  setBrush(brush);
}
