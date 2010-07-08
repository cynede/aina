#ifndef SUBCOMPONENTEDITORTOOL_H
#define SUBCOMPONENTEDITORTOOL_H

#include "abstractformeditortool.h"
#include <QStack>

QT_FORWARD_DECLARE_CLASS(QGraphicsObject)
QT_FORWARD_DECLARE_CLASS(QPoint)
QT_FORWARD_DECLARE_CLASS(QTimer)

namespace QmlViewer {

class SubcomponentMaskLayerItem;

class SubcomponentEditorTool : public AbstractFormEditorTool
{
    Q_OBJECT

public:
    SubcomponentEditorTool(QDeclarativeDesignView *view);
    ~SubcomponentEditorTool();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

    void hoverMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *keyEvent);
    void itemsAboutToRemoved(const QList<QGraphicsItem*> &itemList);

    void clear();
    void graphicsObjectsChanged(const QList<QGraphicsObject*> &itemList);

    bool containsCursor(const QPoint &mousePos) const;
    bool itemIsChildOfQmlSubComponent(QGraphicsItem *item) const;
    bool isDirectChildOfContext(QGraphicsItem *item) const;

    void setCurrentItem(QGraphicsItem *contextObject);

    void pushContext(QGraphicsObject *contextItem);
    QGraphicsObject *popContext();
    QGraphicsObject *currentRootItem() const;

signals:
    void exitContextRequested();

protected:
    void selectedItemsChanged(const QList<QGraphicsItem*> &itemList);

private slots:
    void animate();

private:
    void aboutToPopContext();

private:
    QStack<QGraphicsObject *> m_currentContext;

    qreal m_animIncrement;
    SubcomponentMaskLayerItem *m_mask;
    QTimer *m_animTimer;

};

} // namespace QmlViewer

#endif // SUBCOMPONENTEDITORTOOL_H
