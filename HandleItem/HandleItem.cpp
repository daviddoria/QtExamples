#include "HandleItem.h"

#include <QPainter>
#include <QPointF>

#include <cmath>
#include <iostream>

HandleItem::HandleItem( QRect rect, QGraphicsScene *scene, const QColor color) : QGraphicsItem( 0, scene ),
                        m_role(HandleItem::CenterHandle),
                        m_color(color), m_item(new QGraphicsRectItem( rect, 0, scene ))
{
    // This constructor sets up the center handle, as well as creates the other handles and links everything together.
    // The center handle must know about all of the other handles so it can translate them with the object

    HandleItem *topHandle = new HandleItem( m_item, color, HandleItem::TopHandle, scene );
    topHandle->SetRectItem(m_item);
    
    HandleItem *rightHandle = new HandleItem(m_item, color, HandleItem::RightHandle, scene );
    rightHandle->SetRectItem(m_item);
    
    HandleItem *leftHandle = new HandleItem( m_item, color, HandleItem::LeftHandle, scene );
    leftHandle->SetRectItem(m_item);
    
    HandleItem *bottomHandle = new HandleItem(m_item, color, HandleItem::BottomHandle, scene );
    bottomHandle->SetRectItem(m_item);

    m_handles.push_back(topHandle);
    m_handles.push_back(rightHandle);
    m_handles.push_back(leftHandle);
    m_handles.push_back(bottomHandle);

    topHandle->SetDependentHandles(QList<HandleItem*>() << rightHandle << leftHandle << this);

    rightHandle->SetDependentHandles(QList<HandleItem*>() << topHandle << bottomHandle << this);

    leftHandle->SetDependentHandles(QList<HandleItem*>() << topHandle << bottomHandle << this);

    bottomHandle->SetDependentHandles(QList<HandleItem*>() << rightHandle << leftHandle << this);

    this->SetDependentHandles(QList<HandleItem*>() << rightHandle << leftHandle << topHandle << bottomHandle);

    SetDefauls();
    
    setX(m_item->rect().left() + m_item->rect().width() / 2 - HandleRadius);
    setY(m_item->rect().y() + m_item->rect().height() / 2 - HandleRadius);
    
}

void HandleItem::SetDefauls()
{
    // These things are needed in both constructors
  
    m_pressed = false;
    setZValue( 100 );

    setFlag( ItemIsMovable );

    HandleRadius = 5;
    MinSize = 10;

    setFlag( ItemSendsGeometryChanges );
    
}

HandleItem::HandleItem( QGraphicsRectItem* item, const QColor color, const HandleItem::HandleRole role, QGraphicsScene *scene) : QGraphicsItem( 0, scene ) 
                       , m_item(item), m_color(color), m_role(role)
{
  // This constructor is used internally to setup the left, right, top, and bottom handles
  SetDefauls();

  switch( m_role )
  {
  case RightHandle:
    setX(m_item->rect().x() + m_item->rect().width() - HandleRadius);
    setY(m_item->rect().y() + m_item->rect().height() / 2 - HandleRadius);
    break;
  case LeftHandle:
    setX(m_item->rect().x() - HandleRadius);
    setY(m_item->rect().y() + m_item->rect().height() / 2 - HandleRadius);
    break;
  case TopHandle:
    setX(m_item->rect().left() + m_item->rect().width() / 2 - HandleRadius);
    setY(m_item->rect().top() - HandleRadius);
    break;
  case BottomHandle:
    setX(m_item->rect().left() + m_item->rect().width() / 2 - HandleRadius);
    setY(m_item->rect().bottom() - HandleRadius);
    break;
  }

}


void HandleItem::SetRole(const HandleRole role)
{
  this->m_role = role;
}

void HandleItem::SetRectItem(QGraphicsRectItem* item)
{
  m_item = item;
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
    this->setPos(position);
    break;
    }
  case LeftHandle:
    {
    QPointF position(this->m_item->rect().left() - HandleRadius, this->m_item->rect().top() + this->m_item->rect().height()/2 - HandleRadius);
    this->setPos(position);
    break;
    }
  case TopHandle:
    {
    QPointF position(this->m_item->rect().left() + this->m_item->rect().width()/2 - HandleRadius, this->m_item->rect().top() - HandleRadius);
    this->setPos(position);
    break;
    }
  case BottomHandle:
    {
    QPointF position(this->m_item->rect().left() + this->m_item->rect().width()/2 - HandleRadius, this->m_item->rect().bottom() - HandleRadius);
    this->setPos(position);
    break;
    }
  case CenterHandle:
    {
    QPointF position(this->m_item->rect().left() + this->m_item->rect().width()/2 - HandleRadius,
                     this->m_item->rect().top() + this->m_item->rect().height()/2 - HandleRadius);
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
  
  switch( m_role )
  {
  case RightHandle:
    points << QPointF(2*HandleRadius,HandleRadius) << QPointF(HandleRadius,0) << QPointF(HandleRadius,2*HandleRadius);
    paint->drawConvexPolygon( QPolygonF(points) );
    break;
  case LeftHandle:
    points << QPointF(HandleRadius,HandleRadius*2) << QPointF(0,HandleRadius) << QPointF(HandleRadius,0);
    paint->drawConvexPolygon( QPolygonF(points) );
    break;
  case TopHandle:
    points << QPointF(0,HandleRadius) << QPointF(HandleRadius*2,HandleRadius) << QPointF(HandleRadius,0);
    paint->drawConvexPolygon( QPolygonF(points) );
    break;
  case BottomHandle:
    points << QPointF(0,HandleRadius) << QPointF(HandleRadius*2,HandleRadius) << QPointF(HandleRadius, 2*HandleRadius);
    paint->drawConvexPolygon( QPolygonF(points) );
    break;
  case CenterHandle:
    points << QPointF(0,0) << QPointF(HandleRadius*2,0) << QPointF(HandleRadius*2, 2*HandleRadius) << QPointF(0, 2*HandleRadius);
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
            newData.setX(m_item->boundingRect().x() + MinSize/2);
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
    case LeftHandle:
      {
        // Prevent the rectangle from collapsing
        if ( newRect.width() - movement.x() <= MinSize )
        {
          newRect.setLeft(newRect.right() - MinSize);
	  //float oldLeft = m_item->rect().left();
          //newRect.setWidth(MinSize);
	  //newRect.setLeft(oldLeft);
          m_item->setRect(newRect);
          newData.setX(m_item->boundingRect().x() - MinSize / 2);
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
    case TopHandle:
      {
        // Prevent the rectangle from collapsing.
        if ( newRect.height() - movement.y() <= MinSize )
        {
            newRect.setTop(newRect.bottom() - MinSize);
            //newRect.setHeight(MinSize);
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
    case BottomHandle:
      {
        // Prevent the rectangle from collapsing.
        if ( newRect.height() + movement.y() <= MinSize )
        {
            newRect.setBottom(newRect.top() + MinSize);
            m_item->setRect(newRect);
            newData.setX(pos().x());
            newData.setY(m_item->boundingRect().y() + boundingRect().height() / 2);

            emit Changed();
            return QGraphicsItem::itemChange( change, newData );
        }

        // Snap the movement to the Y direction
        newData.setX(m_item->rect().x() + m_item->rect().width() / 2 - HandleRadius);

        // Resize the rectangle
        newRect.setBottom(m_item->rect().bottom() + movement.y());

        m_item->setRect(newRect);

        break;
      }
    case CenterHandle:
      {
        //m_item->translate(movement.x(), movement.y());
        QRectF rect = m_item->rect();
        rect.setX(rect.x() + movement.x());
        rect.setY(rect.y() + movement.y());
        rect.setWidth(rect.width() + movement.x());
        rect.setHeight(rect.height() + movement.y());
        m_item->setRect(rect);
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
