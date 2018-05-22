#ifndef BANKWORK_MENUVIEW_H
#define BANKWORK_MENUVIEW_H

#include "../View.h"

/**
 * 菜单视图
 */
class MenuView : public View {
public:
    ViewCommand OnCreate(bool) override;

    ViewCommand OnInput(int) override;

    void SetController(AccountController *) override;

private:
    /**
     * 显示菜单视图
     */
    void Display();
};

#endif //BANKWORK_MENUVIEW_H
