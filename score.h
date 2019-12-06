#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
  Score(QGraphicsItem *parent=nullptr);

  void setScore(int score_);
  void increaseScore();
  bool checkScore();

private:
  int score_;
};

#endif // SCORE_H
