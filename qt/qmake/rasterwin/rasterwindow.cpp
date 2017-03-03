#include "rasterwindow.h"

//-------------------------------------------------------------------
RasterWindow::RasterWindow(QWindow *parent)
    : QWindow(parent)
{
    create();
    m_backingStore = new QBackingStore(this);

    setGeometry(100, 100, 300, 200);

}

//-------------------------------------------------------------------
bool RasterWindow::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

//-------------------------------------------------------------------
void RasterWindow::renderLater()
{
    requestUpdate();
}

//-------------------------------------------------------------------
void RasterWindow::resizeEvent(QResizeEvent *resizeEvent)
{
    m_backingStore->resize(resizeEvent->size());
    if (isExposed())
        renderNow();
}

//-------------------------------------------------------------------
void RasterWindow::exposeEvent(QExposeEvent *)
{
    if (isExposed())
        renderNow();
}

//-------------------------------------------------------------------
void RasterWindow::renderNow()
{
    if (!isExposed())
        return;

    QRect rect(0, 0, width(), height());
    m_backingStore->beginPaint(rect);

    QPaintDevice *device = m_backingStore->paintDevice();
    QPainter painter(device);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    render(&painter);

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}

//-------------------------------------------------------------------
void RasterWindow::render(QPainter *painter)
{
    painter->drawText(QRectF(0, 0, width(), height()), Qt::AlignCenter, QStringLiteral("Muthanna A. Attyah"));
}
