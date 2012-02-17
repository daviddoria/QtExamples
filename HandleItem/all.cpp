#include "HandleItem.h"

#include <QPainter>
#include <QPointF>

#include <cmath>
#include <iostream>

// The handles will be drawn centered on the edges of the QGraphicsRectItem.

HandleItem::HandleItem( QGraphicsRectItem *item, QGraphicsScene *scene, QColor color, HandleItem::HandleRole role, QList<HandleItem*> handles ) : QGraphicsItem( 0, scene )
{
  m_role = role;
  m_color = color;

  m_item = item;
  m_handles = handles;

  m_pressed = false;
  setZValue( 100 );

  setFlag( ItemIsMovable );

  HandleRadius = 5;
  MinSize = 5;

  std::cout << "right: " << m_item->rect().right() << std::endl;
  std::cout << "left: " << m_item->rect().left() << std::endl;
  std::cout << "top: " << m_item->rect().top() << std::endl;
  std::cout << "bottom: " << m_item->rect().bottom() << std::endl;
  std::cout << "width: " << m_item->rect().width() << std::endl;
  std::cout << "height: " << m_item->rect().height() << std::endl;
  std::cout << "x: " << m_item->rect().x() << std::endl;
  std::cout << "y: " << m_item->rect().y() << std::endl;
  switch( m_role )
  {
  case RightHandle:
    setX(m_item->rect().right() - HandleRadius);
    setY(m_item->rect().top() + m_item->rect().height() / 2 - HandleRadius);
    break;
//   case LeftHandle:
//     setX(m_item->rect().left() - HandleRadius);
//     setY(m_item->rect().top() + m_item->rect().height() / 2 - HandleRadius);
//     break;
//   case TopHandle:
//     setX(m_item->rect().left() + m_item->rect().width() / 2 - HandleRadius);
//     setY(m_item->rect().top() - HandleRadius);
//     break;
//   case BottomHandle:
//     setX(m_item->rect().left() + m_item->rect().width() / 2 - HandleRadius);
//     setY(m_item->rect().bottom() - HandleRadius);
//     break;
  }

  setFlag(ItemSendsGeometryChanges);

}

void HandleItem::paint( QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
  paint->setPen( m_color );
  paint->setBrush( m_color );

  QRectF rect = boundingRect();
  QVector<QPointF> points;
  // Note the coordinate system is X increasing to the right, Y increasing down

  /*
  |-------> x
  |
  |
  \/
  Y
  */
  switch( m_role )
  {
  case RightHandle:
    points << QPointF(HandleRadius,HandleRadius*2) << QPointF(2*HandleRadius,HandleRadius) << QPointF(HandleRadius,0);
    paint->drawConvexPolygon( QPolygonF(points) );
    break;
//   case LeftHandle:
//     points << QPointF(HandleRadius,HandleRadius*2) << QPointF(0,HandleRadius) << QPointF(HandleRadius,0);
//     paint->drawConvexPolygon( QPolygonF(points) );
//     break;
//   case TopHandle:
//     points << QPointF(0,HandleRadius) << QPointF(HandleRadius*2,HandleRadius) << QPointF(HandleRadius,0);
//     paint->drawConvexPolygon( QPolygonF(points) );
//     break;
//   case BottomHandle:
//     points << QPointF(0,HandleRadius) << QPointF(HandleRadius,2*HandleRadius) << QPointF(HandleRadius*2,HandleRadius);
//     paint->drawConvexPolygon( QPolygonF(points) );
//     break;
  }
}


QRectF HandleItem::boundingRect() const
{
  return QRectF(QPointF(0, 0), QSize( HandleRadius*2, HandleRadius*2));
}

QVariant HandleItem::itemChange( GraphicsItemChange change, const QVariant &data )
{
  if( change == ItemPositionChange && m_pressed )
  {

    QPointF movement;
    QPointF newData = data.toPointF();
    QRectF newRect = m_item->rect();
    // (x,y) is (top, left)
    switch( m_role )
    {
//     case LeftHandle:
//       {
//       // Prevent the rectangle from collapsing.
//       if ( newRect.width() + movement.x() <= MinSize )
//       {
//           newRect.setWidth(MinSize);
//           m_item->setRect(newRect);
//           newData.setX(m_item->boundingRect().x());
//           newData.setY(pos().y());
//           return QGraphicsItem::itemChange( change, newData );
//       }
//
//       // Snap the movement to the X direction
//       newData.setY(0);
//
//       movement = newData - pos();
//       // Resize the rectangle
//       newRect.setLeft(m_item->rect().left() + movement.x());
//
//       m_item->setRect(newRect);
//
//       break;
//       }
    case RightHandle:
      {
      // Prevent the rectangle from collapsing.
//       if ( newRect.width() + movement.x() <= MinSize )
//       {
//           newRect.setWidth(MinSize);
//           m_item->setRect(newRect);
//           newData.setX(m_item->boundingRect().x());
//           newData.setY(pos().y());
//           return QGraphicsItem::itemChange( change, newData );
//       }
      std::cout << "Moving rect right." << std::endl;
      // Snap the movement to the X direction
//       newData.setY(m_item->rect().y() + m_item->rect().height() / 2 - HandleRadius);
//       //newData.setY(pos().y() - HandleRadius);
//
//       // Resize the rectangle
//       newRect.setRight(m_item->rect().right() + movement.x());
//       m_item->setRect(newRect);

                  newData.setY(m_item->rect().y() + m_item->rect().height() / 2 - 5);

            // Resize the rectangle
            newRect.setRight(m_item->rect().right() + movement.x());
            m_item->setRect(newRect);

      break;
      }
//     case TopHandle:
//       {
//       // Prevent the rectangle from collapsing.
//       if ( newRect.width() + movement.x() <= MinSize )
//       {
//           newRect.setWidth(MinSize);
//           m_item->setRect(newRect);
//           newData.setX(m_item->boundingRect().x());
//           newData.setY(pos().y());
//           return QGraphicsItem::itemChange( change, newData );
//       }
//
//       // Snap the movement to the Y direction
//       newData.setX(0);
//
//       movement = newData - pos();
//       // Resize the rectangle
//       newRect.setTop(m_item->rect().top() + movement.y());
//
//       m_item->setRect(newRect);
//
//       break;
//       }
//     case BottomHandle:
//       {
//       // Prevent the rectangle from collapsing.
//       if ( newRect.width() + movement.x() <= MinSize )
//       {
//           newRect.setWidth(MinSize);
//           m_item->setRect(newRect);
//           newData.setX(m_item->boundingRect().x());
//           newData.setY(pos().y());
//           return QGraphicsItem::itemChange( change, newData );
//       }
//
//       // Snap the movement to the Y direction
//       newData.setX(0);
//
//       movement = newData - pos();
//       // Resize the rectangle
//       newRect.setBottom(m_item->rect().bottom() + movement.y());
//
//       m_item->setRect(newRect);
//
//       break;
//       }
    } // end switch

    return QGraphicsItem::itemChange( change, newData);
  } // end if pressed

  return QGraphicsItem::itemChange( change, data );
}

void HandleItem::mousePressEvent( QGraphicsSceneMouseEvent *event )
{
  m_pressed = true;
  QGraphicsItem::mousePressEvent( event );
}

void HandleItem::mouseReleaseEvent( QGraphicsSceneMouseEvent *event )
{
  m_pressed = false;
  QGraphicsItem::mouseReleaseEvent( event );
}
