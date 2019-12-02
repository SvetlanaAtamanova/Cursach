#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "platform.h"
#include "ball.h"
#include "bar.h"
#include "score.h"
#include "constants.h"
#include "button.h"
#include <vector>
#include <algorithm>

class ArcanoidGame: public QGraphicsView{
  Q_OBJECT

public:
  ArcanoidGame(QWidget *parent=nullptr);
  void showStartWindow();
  void gameOver(QString textToDisplay);

  Score *getScore();
  int maxScore;

  void drawBall();
  Ball *getBall();
  void destroyBall();

  std::vector<Bar*> bars_;
  void deleteBar(Bar *bar);
  void deleteAllBars();

public slots:
  void start();
  void restart();

private:
  Platform *platform_;
  Score *score_;
  QGraphicsScene *gameScene_;
  Ball *ball_;

  void drawBars();
  void drawColumn(double x);
};

#endif // GAME_H