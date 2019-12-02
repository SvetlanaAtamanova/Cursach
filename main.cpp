#include <QApplication>
#include "game.h"

ArcanoidGame *game;


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  game = new ArcanoidGame();
  game->show();
  game->showStartWindow();

  return app.exec();
}
