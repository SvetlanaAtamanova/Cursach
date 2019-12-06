#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsTextItem>

#include <vector>
#include "platform.h"
#include "ball.h"
#include "bar.h"
#include "score.h"
#include "constants.h"
#include "button.h"
#include "gray-bar.h"



class ArcanoidGame: public QGraphicsView{
  Q_OBJECT

public:
  ArcanoidGame(QWidget *parent=nullptr);
  void showStartWindow();
  void gameOver(QString message);

  Score *getScore();
  int maxScore_;

  void drawBall();
  Ball *getBall();
  void destroyBall();

  std::vector<Bar*> bars_;
  std::vector<GrayBar*> grayBars_;
  void deleteBar(Bar *bar);
  void deleteAllBars();
  int level_;
  void increaseLevel();

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
