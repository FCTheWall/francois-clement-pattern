#ifndef BUTTONS_CONTROLLER_H
#define BUTTONS_CONTROLLER_H

#include "buttonirq.h"
#include "buttonscontrollercallbackcaller.h"
#include "buttonscontrollercallbackprovider.h"

class ButtonsController : public ButtonIrq, public ButtonsControllerCallbackCaller {
public:
    ButtonsController() = default;
    ~ButtonsController() override = default;  // Destructeur virtuel pour polymorphisme sécurisé

    void onIrq() override;

    bool registerCallback(ButtonsControllerCallbackProvider* callbackProvider,
                          ButtonsControllerCallbackProvider::CallbackMethod callbackMethod) override;
};

#endif // BUTTONS_CONTROLLER_H
