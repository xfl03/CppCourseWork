cmake_minimum_required(VERSION 3.10)
project(BankWork)

set(CMAKE_CXX_STANDARD 11)

add_executable(BankWork main.cpp domain/Account.h domain/DebitAccount.h domain/CreditAccount.h datasource/AccountDataSource.cpp Constant.h io/FileIO.cpp io/FileIO.h dao/AccountDAO.cpp datasource/AccountDataSource.h dao/AccountDAO.h service/AccountService.cpp util/StringUtil.h util/StringUtil.cpp service/AccountService.h controller/AccountController.h domain/BasicResponce.h controller/AccountController.cpp view/implement/MenuView.h view/View.h domain/ViewCommand.h view/ViewManager.h view/ViewManager.cpp view/implement/MenuView.cpp view/implement/RegView.h view/implement/RegView.cpp view/implement/LoginView.h view/implement/LoginView.cpp view/implement/ManaView.h view/implement/ManaView.cpp domain/Account.cpp)