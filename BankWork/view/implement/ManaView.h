#ifndef BANKWORK_MANAVIEW_H
#define BANKWORK_MANAVIEW_H

#include <iostream>
#include "../View.h"

/**
 * 用户账户管理视图
 */
class ManaView : public View {
public:
    ViewCommand OnCreate(bool) override;

    ViewCommand OnInput(int) override;

    void SetController(AccountController *) override;

private:
    void Display();

    /**
     * 控制器指针
     */
    AccountController *con;
};

#endif //BANKWORK_MANAVIEW_H
