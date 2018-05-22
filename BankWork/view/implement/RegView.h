#ifndef BANKWORK_REGVIEW_H
#define BANKWORK_REGVIEW_H

#include "../View.h"
#include "../../controller/AccountController.h"

/**
 * 创建账户视图类
 */
class RegView : public View {
public:
    ViewCommand OnCreate(bool) override;

    ViewCommand OnInput(int) override;

    void SetController(AccountController *acc) override;

private:
    /**
     * 控制器指针
     */
    AccountController *con;
};

#endif //BANKWORK_REGVIEW_H
