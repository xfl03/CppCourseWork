#include <iostream>
#include "LoginView.h"
#include "../../util/StringUtil.h"

using namespace std;

ViewCommand LoginView::OnCreate(bool re) {
    if (re)
        return ViewCommand(3);//直接返回到主菜单
    cout << "=================" << endl;
    cout << "====登录账户=====" << endl;
    cout << "请输入账号：" << endl;
    string id = StringUtil::ReadLineWithoutSpace("");
    cout << "请输入密码：" << endl;
    string pw = StringUtil::GetHash(StringUtil::ReadLineWithoutSpace(""));
    if (con->Login(id, pw).status != 0) {
        cout << "账号或密码错误！" << endl;
        return ViewCommand(3);//返回上级菜单
    }

    return ViewCommand(2, 3);
}

ViewCommand LoginView::OnInput(int) {
    return ViewCommand(3);//不应该执行至此
}

void LoginView::SetController(AccountController *acc) { con = acc; }
