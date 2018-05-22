#include <iostream>
#include "../../domain/ViewCommand.h"
#include "MenuView.h"

using namespace std;

ViewCommand MenuView::OnCreate(bool) {
    Display();
    return ViewCommand(1);
}

ViewCommand MenuView::OnInput(int input) {
    switch (input) {
        case 0://退出系统
            return ViewCommand(3);
        case 1://创建账户
            return ViewCommand(2, 1);
        case 2://登录账户
            return ViewCommand(2, 2);
        default:
            cout << "输入有误，请重新输入：";
            return ViewCommand(1);
    }
}

void MenuView::Display() {
    cout << "=================" << endl;
    cout << "===银行ATM系统===" << endl;
    cout << "===1.创建账户====" << endl;
    cout << "===2.登录账户====" << endl;
    cout << "===0.退出系统====" << endl;
    cout << "=================" << endl;
    cout << "请输入您选择的项目：";
}

void MenuView::SetController(AccountController *) {}
