#ifndef GEARWIDGET_H
#define GEARWIDGET_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class GearWidget;
}

class GearWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GearWidget(QWidget *parent = nullptr);
    ~GearWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::GearWidget *ui;
    const static int HOLLOW_CIRCLE_WIDTH;
    const static int TRIANGLE_HEIGHT;
    const static int TRIANGLE_EDGE;
    const static int GEARS_NUMBERS;
    const static double ROOT_SIGN_THREE;
    QPainter *painter;
    void drawHollowCircle();
};

#endif // GEARWIDGET_H
