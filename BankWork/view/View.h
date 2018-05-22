#ifndef BANKWORK_VIEW_H
#define BANKWORK_VIEW_H

#include "../domain/ViewCommand.h"
#include "../controller/AccountController.h"

/**
 * 视图类
 */
class View {
public:
    /**
     * 在视图被创建时调用
     * @param 是否为重新创建
     */
    virtual ViewCommand OnCreate(bool)=0;

    /**
     * 在视图接收到菜单类输入时调用
     * @param 用户输入的菜单编号
     * @return 下一步执行的命令
     */
    virtual ViewCommand OnInput(int)=0;

    /**
     * 设置控制器
     */
    virtual void SetController(AccountController *)=0;
};

#endif //BANKWORK_VIEW_H
