#include "gearwidget.h"
#include "ui_gearwidget.h"

const int GearWidget::HOLLOW_CIRCLE_WIDTH = 10;
const int GearWidget::TRIANGLE_HEIGHT = 5;
const int GearWidget::TRIANGLE_EDGE = 10;
const int GearWidget::GEARS_NUMBERS = 144;
const double GearWidget::ROOT_SIGN_THREE = 8.66025;
GearWidget::GearWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GearWidget)
{
    ui->setupUi(this);
}

GearWidget::~GearWidget()
{
    delete ui;
}
void GearWidget::paintEvent(QPaintEvent *) {
    painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);

    drawHollowCircle();

}

void GearWidget::drawHollowCircle()
{
    painter->setBrush(Qt::NoBrush);
    painter->setPen(QPen(Qt::green, HOLLOW_CIRCLE_WIDTH));

    int centerX = width() / 2;
    int centerY = height() / 2;
    int radius = qMin(centerX, centerY) - HOLLOW_CIRCLE_WIDTH;

    painter->drawEllipse(QPointF(centerX, centerY), radius, radius);
    for (int i = 0; i < GEARS_NUMBERS; ++i) {
        painter->save();

        painter->setBrush(Qt::green);
        painter->setPen(Qt::green);

        painter->translate(centerX, centerY);
        painter->rotate(i * (360.0 / GEARS_NUMBERS));
        int vertex = radius - HOLLOW_CIRCLE_WIDTH - TRIANGLE_HEIGHT;
        QPolygon polygon;
        painter->translate(0, vertex);
        polygon << QPoint(0, 0) << QPoint(-ROOT_SIGN_THREE, TRIANGLE_EDGE) << QPoint(ROOT_SIGN_THREE, TRIANGLE_EDGE);
        painter->drawPolygon(polygon);

        painter->restore();
    }
}
