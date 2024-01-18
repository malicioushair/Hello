#include <iostream>

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QPushButton button("Click me");
  QObject::connect(&button, &QPushButton::clicked,
                   []() { qDebug("Hello, World!"); });

  button.resize(200, 60);
  button.show();

  return QApplication::exec();
}