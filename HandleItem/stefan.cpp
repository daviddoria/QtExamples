#include "HandleItem.h"

#include <QPainter>
#include <QPointF>

#include <cmath>
#include <iostream>

HandleItem::HandleItem( QGraphicsRectItem *item, QGraphicsScene *scene,
                        QColor color, HandleItem::HandleRole role) : QGraphicsItem( 0, scene )
{
    m_role = role;
    m_color = color;

    m_item = item;

    m_pressed = false;
    setZValue( 100 );

    setFlag( ItemIsMovable );

    HandleRadius = 5;
    MinSize = 10;
    
    switch( m_role )
    {
    case RightHandle:
      setX(m_item->rect().x() + m_item->rect().width() - HandleRadius);
      setY(m_item->rect().y() + m_item->rect().height() / 2 - HandleRadius);
      break;
    case TopHandle:
      setX(m_item->rect().left() + m_item->rect().width() / 2 - HandleRadius);
      setY(m_item->rect().top() - HandleRadius);
      break;
    case LeftHandle:
      setX(m_item->rect().x() - HandleRadius);
      setY(m_item->rect().y() + m_item->rect().height() / 2 - HandleRadius);
      break;
    }

    setFlag( ItemSendsGeometryChanges );
}

void HandleItem::SetDependentHandles(QList<HandleItem*> handles)
{
  m_handles = handles;
  for(unsigned int i = 0; i < m_handles.size(); ++i)
    {
    connect(this, SIGNAL(Changed()), m_handles[i], SLOT(Update()));
    }
}

void HandleItem::Update()
{
  switch( m_role )
  {
  case RightHandle:
    {
    QPointF position(this->m_item->rect().right() - HandleRadius, this->m_item->rect().top() + this->m_item->rect().height()/2 - HandleRadius);
    //this->translate(1,1);
    this->setPos(position);
    break;
    }
  case TopHandle:
    {
    QPointF position(this->m_item->rect().left() + this->m_item->rect().width()/2 - HandleRadius, this->m_item->rect().top() - HandleRadius);
    this->setPos(position);
    break;
    }
  case LeftHandle:
    {
    QPointF position(this->m_item->rect().left() - HandleRadius, this->m_item->rect().top() + this->m_item->rect().height()/2 - HandleRadius);
    this->setPos(position);
    break;
    }
  }
}

void HandleItem::paint( QPainter *paint, const QStyleOptionGraphicsItem *option,
                        QWidget *widget )
{
  paint->setPen( m_color );
  paint->setBrush( m_color );

  QVector<QPointF> points;
  
  // Draw the bounding box
//   paint->setPen( Qt::blue );
//   paint->drawRect( boundingRect() );

  switch( m_role )
  {
  case RightHandle:
    points << QPointF(2*HandleRadius,HandleRadius) << QPointF(HandleRadius,0) << QPointF(HandleRadius,2*HandleRadius);
    paint->drawConvexPolygon( QPolygonF(points) );
    break;
  case TopHandle:
    points << QPointF(0,HandleRadius) << QPointF(HandleRadius*2,HandleRadius) << QPointF(HandleRadius,0);
    paint->drawConvexPolygon( QPolygonF(points) );
    break;
  case LeftHandle:
    points << QPointF(HandleRadius,HandleRadius*2) << QPointF(0,HandleRadius) << QPointF(HandleRadius,0);
    paint->drawConvexPolygon( QPolygonF(points) );
    break;
  }

}

QRectF HandleItem::boundingRect() const
{
  return QRectF(QPointF(0, 0), QSize( 2*HandleRadius, 2*HandleRadius ));
}

QVariant HandleItem::itemChange( GraphicsItemChange change, const QVariant &data )
{
  if ( change == ItemPositionChange && m_pressed )
  {
    QPointF newData = data.toPointF();
    QRectF newRect = m_item->rect();
    QPointF movement = newData - pos();

    switch ( m_role )
    {
    case RightHandle:
      {
        // Prevent the rectangle from collapsing.
        if ( newRect.width() + movement.x() <= MinSize )
        {
            newRect.setWidth(MinSize);
            m_item->setRect(newRect);
            newData.setX(m_item->boundingRect().x() + m_item->boundingRect().width() / 2);
            newData.setY(pos().y());

            emit Changed();
            return QGraphicsItem::itemChange( change, newData );
        }

        // Snap the movement to the X direction
        newData.setY(m_item->rect().y() + m_item->rect().height() / 2 - HandleRadius);

        // Resize the rectangle
        newRect.setRight(m_item->rect().right() + movement.x());
        m_item->setRect(newRect);

        break;
      }
    case TopHandle:
      {
        // Prevent the rectangle from collapsing.
        if ( newRect.height() - movement.y() <= MinSize )
        {
            newRect.setHeight(MinSize);
            m_item->setRect(newRect);
            newData.setX(pos().x());
            newData.setY(m_item->boundingRect().y() - boundingRect().height() / 2); // + m_item->boundingRect().height());

            emit Changed();
            return QGraphicsItem::itemChange( change, newData );
        }

        // Snap the movement to the Y direction
        newData.setX(m_item->rect().x() + m_item->rect().width() / 2 - HandleRadius);

        // Resize the rectangle
        newRect.setTop(m_item->rect().top() + movement.y());

        m_item->setRect(newRect);

        break;
      }
    case LeftHandle:
      {
        std::cout << "Left: X movement: " << movement.x() << std::endl;
        // Prevent the rectangle from collapsing.
        if ( newRect.width() - movement.x() <= MinSize )
        {
          std::cout << "Left: Collapse!" << std::endl;
          newRect.setWidth(MinSize);
          m_item->setRect(newRect);
          newData.setX(m_item->boundingRect().x() - boundingRect().width() / 2);
          newData.setY(pos().y());

          emit Changed();
          return QGraphicsItem::itemChange( change, newData );
        }

        // Snap the movement to the X direction
        newData.setY(m_item->rect().y() + m_item->rect().height() / 2 - HandleRadius);

        // Resize the rectangle
        newRect.setLeft(m_item->rect().left() + movement.x());
        m_item->setRect(newRect);

        break;
      }
    } // end switch

    emit Changed();
    return QGraphicsItem::itemChange( change, newData );
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
