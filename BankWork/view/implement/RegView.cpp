#include <iostream>
#include "RegView.h"
#include "../../util/StringUtil.h"
#include "../../domain/DebitAccount.h"
#include "../../domain/CreditAccount.h"

using namespace std;

ViewCommand RegView::OnCreate(bool) {
    Account tmp;
    tmp.balance = 0;
    string t;

    cout << "=================" << endl;
    cout << "====创建账户=====" << endl;

    cout << "请输入自定义的账号：" << endl;
    while (true) {
        t = StringUtil::ReadLineWithoutSpace("");
        if (con->CheckID(t).status == 0)//未被占用
            break;
        cout << "该账号已被占用，请重新输入：" << endl;
    }
    tmp.identity = t;

    cout << "请输入密码：" << endl;
    tmp.password = StringUtil::GetHash(StringUtil::ReadLineWithoutSpace(""));

    cout << "请输入姓名：" << endl;
    tmp.name = StringUtil::ReadLineWithoutSpace("");

    cout << "请输入性别（男为M,女为F）：" << endl;
    while (true) {
        t = StringUtil::ReadLineWithoutSpace("");
        if (t == "M" || t == "F")//性别输入正确
            break;
        cout << "性别输入错误，请重新输入：" << endl;
    }
    tmp.gender = (t == "M");

    cout << "请输入地址：" << endl;
    tmp.address = StringUtil::ReadLineWithoutSpace("");

    cout << "请输入手机：" << endl;
    while (true) {
        t = StringUtil::ReadLineWithoutSpace("");
        if (con->JudgeMobile(t).status == 0)//格式正确
            break;
        cout << "手机号输入错误，请重新输入：" << endl;
    }
    tmp.phone = t;

    cout << "请输入身份证：" << endl;
    while (true) {
        t = StringUtil::ReadLineWithoutSpace("");
        if (con->JudgeIDcard(t).status == 0)//格式正确
            break;
        cout << "身份证号输入错误，请重新输入：" << endl;
    }
    tmp.idcard = t;

    cout << "请输入账户类型（储蓄账户为1，信用卡账户为2）：" << endl;
    int tt;
    Account *acc;
    while (cin >> tt) {
        if (tt == 1) {
            tmp.type = 1;
            acc = new DebitAccount(tmp);
            break;
        } else if (tt == 2) {
            tmp.type = 2;
            acc = new CreditAccount(tmp);
            break;
        }
        cout << "输入无效，请重新输入：" << endl;
    }

    con->Register(*acc);
    cout << "注册成功！" << endl;
    StringUtil::Pause();

    return ViewCommand(3);//返回上级菜单
}

ViewCommand RegView::OnInput(int) {
    return ViewCommand(3);//不应该执行至此
}

void RegView::SetController(AccountController *acc) { con = acc; }
