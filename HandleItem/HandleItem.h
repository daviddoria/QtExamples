#ifndef HANDLEITEM_H
#define HANDLEITEM_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class HandleItem;

class HandleItem : public QObject, public QGraphicsItem // QGraphicsItem does not inherit from QObject, so without this multiple inheritance we cannot use signals
{
Q_OBJECT
public:

  enum HandleRole
  {
    CenterHandle,
    RightHandle,
    TopHandle,
    LeftHandle,
    BottomHandle
  };

  HandleItem( QRect rect, QGraphicsScene *scene, const QColor color);
    
  void paint( QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget );
  QRectF boundingRect() const;

  void SetDependentHandles(QList<HandleItem*> handles);

  void SetRole(const HandleRole);
  void SetRectItem(QGraphicsRectItem*);
  
signals:
  void Changed();
  
protected:
  HandleItem( QGraphicsRectItem *item, const QColor color, const HandleItem::HandleRole, QGraphicsScene *scene);
  void SetDefauls();
  void mousePressEvent( QGraphicsSceneMouseEvent *event );
  void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );
  
  QVariant itemChange( GraphicsItemChange change, const QVariant &data );

public slots:
  void Update();
  
private:
  QGraphicsRectItem *m_item;
  
  HandleRole m_role;
  QColor m_color;
  
  QList<HandleItem*> m_handles;

  bool m_pressed;

  unsigned int HandleRadius;
  unsigned int MinSize;
};

#endif // HANDLEITEM_H
