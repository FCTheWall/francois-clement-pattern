#include "ButtonEventsLogger.h"

StateMachine_ButtonEventsLogger::StateMachine_ButtonEventsLogger(const std::string &text)
    : text_(text)
{
}

StateMachine_ButtonEventsLogger::~StateMachine_ButtonEventsLogger() = default;

XFEventStatus StateMachine_ButtonEventsLogger::processEvent()
{
    XFEventStatus eventStatus = XFEventStatus::Unknown;

    switch (currentState_)
    {
    case MainState::STATE_INITIAL:
        if (getCurrentEvent()->getEventType() == XFEvent::Initial)
        {
            GEN(XFDefaultTransition());

            currentState_ = MainState::STATE_TEST;

            eventStatus = XFEventStatus::Consumed;
        }
        break;

    case MainState::STATE_TEST:
        if (getCurrentEvent()->getEventType() == XFEvent::DefaultTransition ||
            (getCurrentEvent() == delayedEventHandle_ && getCurrentEvent()->getId() == Timeout_TEST_id))
        {
            Trace::out(getText());

            if (delayedEventHandle_)
                delayedEventHandle_ = nullptr; // Delayed event (timeout) consumed

            delayedEventHandle_ = pushEvent(Timeout_TEST_id, 1000);

            eventStatus = XFEventStatus::Consumed;
        }
        break;

    default:
        break;
    }

    return eventStatus;
}

ButtonEventsLogger::ButtonEventsLogger()
    : stateMachine_("Button Events Logger")
{
}

ButtonEventsLogger::~ButtonEventsLogger() = default;

void ButtonEventsLogger::onButtonShortPressed(ButtonIndex buttonIndex)
{
    Trace::out("Button %d short pressed", buttonIndex);
}

void ButtonEventsLogger::onButtonLongPressed(ButtonIndex buttonIndex)
{
    Trace::out("Button %d long pressed", buttonIndex);
}
