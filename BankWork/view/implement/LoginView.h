#ifndef BANKWORK_LOGINVIEW_H
#define BANKWORK_LOGINVIEW_H

#include "../View.h"
#include "../../controller/AccountController.h"

/**
 * 登录视图
 */
class LoginView : public View {
public:
    ViewCommand OnCreate(bool re) override;

    ViewCommand OnInput(int) override;

    void SetController(AccountController *acc) override;

    /**
     * 控制器指针
     */
    AccountController *con;
};

#endif //BANKWORK_LOGINVIEW_H
