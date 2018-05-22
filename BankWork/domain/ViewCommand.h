#ifndef BANKWORK_VIEWCOMMAND_H
#define BANKWORK_VIEWCOMMAND_H

/**
 * 视图命令类
 */
class ViewCommand {
public:
    explicit ViewCommand(int command, int data = 0) :
            command(command), data(data) {}

    /**
     * 视图命令
     * 1-重新输入
     * 2-切换视图（切换的视图ID填入data）
     * 3-关闭当前视图
     */
    int command;
    /**
     * 视图命令的附加数据
     */
    int data;
};

#endif //BANKWORK_VIEWCOMMAND_H
