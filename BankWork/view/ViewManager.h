#ifndef BANKWORK_VIEWMANAGER_H
#define BANKWORK_VIEWMANAGER_H

#include <iostream>
#include "View.h"

using namespace std;

/**
 * 视图管理器
 */
class ViewManager {
public:
    /**
     * 打开视图
     * @param 视图ID
     */
    void CreateView(int viewId);

private:
    /**
     * 所有可用的视图
     */
    static View *const views[];
    /**
     * 控制器指针
     */
    AccountController *con = new AccountController();
};

#endif //BANKWORK_VIEWMANAGER_H
