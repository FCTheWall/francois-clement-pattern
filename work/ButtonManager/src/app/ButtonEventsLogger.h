#ifndef BUTTON_EVENTS_LOGGER_H
#define BUTTON_EVENTS_LOGGER_H

#include "interface/buttoneventshandlerobserver.h"
#include "xf/behavior.h"
#include "trace/trace.h"
#include <string>

/**
 * @brief State machine for ButtonEventsLogger.
 */
class StateMachine_ButtonEventsLogger : public XFBehavior
{
public:
    explicit StateMachine_ButtonEventsLogger(const std::string &text);
    ~StateMachine_ButtonEventsLogger() override;

    XFEventStatus processEvent() override; ///< Processes events in the state machine.

    inline const std::string &getText() const { return text_; } ///< Returns the state machine's text.

private:
    /**
     * @brief Enumeration of states for the state machine.
     */
    enum class MainState
    {
        STATE_INITIAL, ///< Initial state
        STATE_TEST     ///< Test state
    };

    MainState currentState_ = MainState::STATE_INITIAL; ///< The current state of the state machine.
    XFEventHandle delayedEventHandle_ = nullptr;       ///< Handle to a delayed event (if applicable).
    std::string text_;                                 ///< Text displayed in the state machine.
};

/**
 * @brief Logger for button events, implementing the observer interface.
 */
class ButtonEventsLogger : public interface::ButtonEventsHandlerObserver
{
public:
    ButtonEventsLogger();
    ~ButtonEventsLogger() override;

    // Overrides from ButtonEventsHandlerObserver
    void onButtonShortPressed(ButtonIndex buttonIndex) override;
    void onButtonLongPressed(ButtonIndex buttonIndex) override;

private:
    StateMachine_ButtonEventsLogger stateMachine_; ///< State machine for the logger.
};

#endif // BUTTON_EVENTS_LOGGER_H
