#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button:public QObject, public QGraphicsRectItem{
  Q_OBJECT

public:
  Button(QString name, QGraphicsItem *parent=nullptr);

  void mousePressEvent(QGraphicsSceneMouseEvent *);
  void hoverEnterEvent(QGraphicsSceneHoverEvent *);
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *);

private:
  QGraphicsTextItem *text_;


signals:
  void clicked();
};

#endif // BUTTON_H
