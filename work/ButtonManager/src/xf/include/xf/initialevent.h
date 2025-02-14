#ifndef XF_INITIALEVENT_H
#define XF_INITIALEVENT_H

#include "xf/event.h"

/** @ingroup xf_core
 *  @{
 */

/**
 * @brief Initial event to start a behavior.
 *
 * Represents for example the first transition executed
 * in a state machine.
 */
class XFInitialEvent : public XFEvent
{
public:
    XFInitialEvent();

    bool deleteAfterConsume() const override;   ///< See XFEvent.
};

/** @} */ // end of xf_core group
#endif // XF_INITIALEVENT_H
