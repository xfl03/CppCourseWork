/**
 * @file
 * 文档见 view/ViewManager.h
 */
#include "ViewManager.h"

#include "implement/MenuView.h"
#include "implement/RegView.h"
#include "implement/LoginView.h"
#include "implement/ManaView.h"

void ViewManager::CreateView(int viewId) {
    views[viewId]->SetController(con);
    ViewCommand command = views[viewId]->OnCreate(false);
    int n;
    while (true) {//循环进行菜单输入
        switch (command.command) {//执行返回的命令
            case 1://继续输入
                break;
            case 2://切换视图
                CreateView(command.data);
                command = views[viewId]->OnCreate(true);//重新打开当前视图
                continue;
            case 3://关闭视图
                return;
        }
        cin >> n;
        command = views[viewId]->OnInput(n);
    }
}

View *const ViewManager::views[] = {new MenuView(), new RegView(), new LoginView(), new ManaView()};