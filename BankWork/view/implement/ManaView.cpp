#include "ManaView.h"
#include "../../util/StringUtil.h"

ViewCommand ManaView::OnCreate(bool) {
    Display();
    return ViewCommand(1);
}

ViewCommand ManaView::OnInput(int input) {
    double n;
    switch (input) {
        case 0://退出系统
            return ViewCommand(3);
        case 1://查询余额
            cout << (con->Balance().message) << endl;
            StringUtil::Pause();
            Display();
            return ViewCommand(1);
        case 2://取款
            cout << "请输入取款数额：" << endl;
            cin >> n;
            cout << (con->WithDrawal(n).message) << endl;
            cout << (con->Balance().message) << endl;
            StringUtil::Pause();
            Display();
            return ViewCommand(1);
        case 3://存款
            cout << "请输入存款数额：" << endl;
            cin >> n;
            cout << (con->Deposit(n).message) << endl;
            cout << (con->Balance().message) << endl;
            StringUtil::Pause();
            Display();
            return ViewCommand(1);
        case 4://查询余额
            cout << (con->Interest().message) << endl;
            StringUtil::Pause();
            Display();
            return ViewCommand(1);
        case 5://撤销账户
            cout << (con->Delete().message) << endl;
            StringUtil::Pause();
            return ViewCommand(3);
        default:
            cout << "输入有误，请重新输入：";
            return ViewCommand(1);
    }
}

void ManaView::SetController(AccountController *acc) { con = acc; }

void ManaView::Display() {
    cout << "=================" << endl;
    cout << "===账户管理系统==" << endl;
    cout << "===1.查询余额====" << endl;
    cout << "===2.取款========" << endl;
    cout << "===3.存款========" << endl;
    cout << "===4.查看利息====" << endl;
    cout << "===5.撤销账户====" << endl;
    cout << "===0.退出账户====" << endl;
    cout << "=================" << endl;
    cout << "请输入您选择的项目：";
}
