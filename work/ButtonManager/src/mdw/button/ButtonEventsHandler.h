#ifndef BUTTON_EVENTS_HANDLER_H
#define BUTTON_EVENTS_HANDLER_H

#include "interface/buttonscontrollercallbackprovider.h"
#include "interface/buttoneventshandlersubject.h"
#include <vector>

namespace interface {

/**
 * @brief Concrete implementation of ButtonsControllerCallbackProvider and ButtonEventsHandlerSubject.
 *
 * This class handles button press events and notifies registered observers of short or long presses.
 */
class ButtonEventsHandler : public ButtonsControllerCallbackProvider, public ButtonEventsHandlerSubject
{
public:
    ButtonEventsHandler();
    ~ButtonEventsHandler() override;

    // Implementation of ButtonsControllerCallbackProvider
    void onButtonChanged(uint16_t buttonIndex, bool pressed); ///< Callback for button state changes
    void setCallback(CallbackMethod callback);               ///< Registers a callback method

    // Implementation of ButtonEventsHandlerSubject
    bool subscribe(ButtonEventsHandlerObserver *observer) override;   ///< Registers an observer
    void unsubscribe(ButtonEventsHandlerObserver *observer) override; ///< Removes an observer

protected:
    void notifyButtonShortPressed(ButtonIndex buttonIndex) override;  ///< Notifies observers of a short press
    void notifyButtonLongPressed(ButtonIndex buttonIndex) override;   ///< Notifies observers of a long press

private:
    CallbackMethod callbackMethod_;                                   ///< Pointer to callback method
    std::vector<ButtonEventsHandlerObserver *> observers_;            ///< List of registered observers
};

} // namespace interface

#endif // BUTTON_EVENTS_HANDLER_H
