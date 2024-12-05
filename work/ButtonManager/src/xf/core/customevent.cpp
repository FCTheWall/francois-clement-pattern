#include "xf/customevent.h"

XFCustomEvent::XFCustomEvent(EventId id, interface::XFBehavior * pBehavior /* = nullptr */)
    : XFEvent(XFEvent::Event, id),
      bDeleteAfterConsume_(true)
{
    setBehavior(pBehavior);
}
