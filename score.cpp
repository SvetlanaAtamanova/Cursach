#include "score.h"
#include "game.h"

extern ArcanoidGame *game;

Score::Score(QGraphicsItem *parent):
  QGraphicsTextItem(parent),
  score_(0)
{
  setPlainText(QString("Score: ") + QString::number(score_));
  setDefaultTextColor(Qt::white);
  setFont(QFont("times", 16));
}

void Score::setScore(int score){
  this->score_ = score;
  setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increaseScore(){
  setPlainText(QString("Score: ") + QString::number(++score_));
}

bool Score::checkScore(){
  if (score_ == game->maxScore_){
    return true;
  }
  return false;
}

