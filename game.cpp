#include "game.h"


ArcanoidGame::ArcanoidGame(QWidget *parent):
  QGraphicsView(parent),
  maxScore_(0),
  gameScene_(new QGraphicsScene(0, 0, WIDTH_SCENE, HEIGTH_SCENE)),
  ball_(nullptr)
{
  setFixedSize(WIDTH_SCENE, HEIGTH_SCENE);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


void ArcanoidGame::showStartWindow(){
  setScene(gameScene_);
  gameScene_->addPixmap(QPixmap("C:/Users/soata/Projects/Cursach/ARCANOID/img/background3.jpg"));

  QGraphicsTextItem *titleText = new QGraphicsTextItem("Arcanoid");
  titleText->setFont(QFont("times",50));
  double txPos = this->width()/2 - titleText->boundingRect().width()/2;
  int tyPos = 150;
  titleText->setPos(txPos,tyPos);
  gameScene_->addItem(titleText);

  Button *playButton = new Button("New game", 275);
  connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
  gameScene_->addItem(playButton);

  Button *quitButton = new Button("Exit", 350);
  connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
  gameScene_->addItem(quitButton);
}

void ArcanoidGame::drawBars(){
  for (size_t i = 1; i < 21; ++i){
    drawColumn(i * 40);
    maxScore_ += 5;
  }
  this->score_->setScore(0);
}

void ArcanoidGame::drawColumn(double x){
  for (size_t i = 0; i < 5; ++i){
    Bar *block = new Bar();
    block->setPos(x, i * 50);

    switch (i) {
    case 0:
      block->setDegree(BarDegree::ULTRA_HARD);
      break;
    case 1:
      block->setDegree(BarDegree::HARD);
      break;
    case 2:
      block->setDegree(BarDegree::MEDIUM);
      break;
    default:
      block->setDegree(BarDegree::EASY);
    }

    gameScene_->addItem(block);
    bars_.push_back(block);
  }
}



void ArcanoidGame::start(){
  gameScene_->clear();
  gameScene_->addPixmap(QPixmap("C:/Users/soata/Projects/Cursach/ARCANOID/img/background2.jpg"));


  platform_ = new Platform();
  platform_->setPos(width()/2 - platform_->rect().width()/2, height() - platform_->rect().height());
  gameScene_->addItem(platform_);

  platform_->setFlag(QGraphicsItem::ItemIsFocusable, true);
  platform_->setFocus();


  score_ = new Score();
  score_->setPos(0, height()/2);
  gameScene_->addItem(score_);

  drawBars();
}


void ArcanoidGame::gameOver(QString message){
  Button *playAgain = new Button("Play again", 275);
  gameScene_->addItem(playAgain);
  connect(playAgain,SIGNAL(clicked()),this,SLOT(restart()));

  Button *quit = new Button("Exit", 350);
  gameScene_->addItem(quit);
  connect(quit,SIGNAL(clicked()),this,SLOT(close()));

  QGraphicsTextItem *overText = new QGraphicsTextItem(message);
  overText->setFont(QFont("times",50));
  overText->setDefaultTextColor(Qt::white);
  double txPos = this->width()/2 - overText->boundingRect().width()/2;
  int tyPos = 150;
  overText->setPos(txPos,tyPos);
  gameScene_->addItem(overText);
  platform_->setFlag(QGraphicsItem::ItemIsFocusable, false);

}

void ArcanoidGame::restart(){
  delete platform_;
  delete score_;
  delete ball_;
  gameScene_->clear();
  start();
}

Score *ArcanoidGame::getScore(){
  return score_;
}


void ArcanoidGame::drawBall(){
  ball_ = new Ball();
  ball_->setPos(width()/2 - 15, height()/2 + 15);
  gameScene_->addItem(ball_);
}

Ball *ArcanoidGame::getBall(){
  return ball_;
}

void ArcanoidGame::destroyBall(){
  gameScene_->removeItem(ball_);
  delete ball_;
  ball_ = nullptr;
}




void ArcanoidGame::deleteBar(Bar* block){
  gameScene_->removeItem(block);
  bars_.erase(std::find(bars_.begin(), bars_.end(), block));
  delete block;
}

void ArcanoidGame::deleteAllBars(){
  std::vector<Bar*>::iterator it;
  for(it = bars_.begin(); it != bars_.end(); ++it) {
    delete (*it);
  }
  bars_.clear();
}
