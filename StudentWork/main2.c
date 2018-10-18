/**
 * @file
 * 此程序中使用了 Doxygen 风格的文档标记为全局变量与函数进行说明
 * note - 提示
 * par - 样例
 * see - 另请参阅
 * param - 参数说明
 * return - 返回内容说明
 * retval - 某个具体返回值说明
 * @see https://zh.wikipedia.org/wiki/Doxygen
 * @see http://www.stack.nl/~dimitri/doxygen/
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 用于存储学生数量
 * @note 初始学生数量为0，随着信息录入而增加
 */
unsigned int students_number = 0;

/**
 * 用于存储学生信息
 * @note 二级下标0为学号，1为分数
 * @par students_info[0][1] 为第1个学生的分数
 */
int students_info[30][2];

/**
 * 输入所有学号和成绩
 * 样例输入： 1 60(换行)2 50(换行)0 0(换行)
 * */
void inputRecords() {
    //输出控制台输入格式提示
    printf("Please input records: \n");
    printf("(Format in each line is 'ID Score' and ends with '0 0'.) \n");

    //进行控制台输入读取
    int scanf_retval, student_id, student_score;
    //输入格式错误 或者 输入 '0 0' 或者 人数达到30 ，则停止输入
    while ((scanf_retval = scanf("%d%d", &student_id, &student_score)) == 2 &&
           student_id | student_score != 0 &&
           students_number < 30) {

        //将id与分数存入全局变量
        students_info[students_number][0] = student_id;
        students_info[students_number][1] = student_score;
        students_number++;
    }
    //如果是输入格式错误造成的停止输入，则清空缓冲区，为下一次输入做准备
    if (scanf_retval != 2)
        while (getchar() != '\n');

    //输出已经成功记录的学生数量
    printf("%d %s been recorded. \n", students_number, students_number > 1 ? "students have" : "student has");
}

/**
 * 计算总分与平均分
 */
void printTotalAndAverage() {
    int i;
    int total = 0;//记录分数总和
    for (i = 0; i < students_number; i++)
        total += students_info[i][1];//分数累加

    //输出总分与平均分
    printf("Total   = %d \n", total);
    printf("Average = %.1lf \n", (double) total / students_number);
}

/**
 * 用于在倒叙排序中比较两个学生的分数
 * @param 两个学生的信息
 * @return 两个学生的分数比较结果
 * @retval >0 - 后者分数大于前者
 * @retval 0 - 两者分数相等
 * @retval <0 - 前者分数大于后者
 */
int scoreCompare(const void *student_info0, const void *student_info) {
    return ((int *) student_info)[1] - ((int *) student_info0)[1];
}

/**
 * 成绩由高到低进行排序
 */
void sortScore(int storage_array[][2]) {
    //将数组进行复制，以便于存储排序结果的同时不改变原数组
    //memcpy(Memory Copy)是c自带的数组内容复制函数，相关文档参见 http://www.cplusplus.com/reference/cstring/memcpy/
    //void * memcpy ( void * destination, const void * source, size_t num );
    memcpy(storage_array, students_info, sizeof(int) * students_number * 2);

    //按成绩由大到小排序，比较函数在上方已经定义
    //qsort(Quick Sort)是c自带的快速排序函数，相关文档参见 http://www.cplusplus.com/reference/cstdlib/qsort/
    //void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
    qsort(storage_array, students_number, sizeof(int) * 2, scoreCompare);
}

/**
 * 成绩由高到低排序输出
 */
void printSortedScore() {
    //调用函数进行排序
    int students_score_desc[students_number][2];
    sortScore(students_score_desc);

    //对排序后的结果进行输出
    printf("Rank ID Score \n");
    int i;
    for (i = 0; i < students_number; i++)
        printf("%-5d%-3d%d \n", i + 1, students_score_desc[i][0], students_score_desc[i][1]);
}

/**
 * 用于在正序排序中比较两个学生的ID
 * @param 两个学生的信息
 * @return 两个学生的ID比较结果
 * @retval >0 - 前者ID大于后者
 * @retval 0 - 两者ID相等
 * @retval <0 - 后者ID大于前者
 */
int idCompare(const void *student_info0, const void *student_info) {
    return ((int *) student_info0)[0] - ((int *) student_info)[0];
}

/**
 * ID由低到高进行排序
 */
void sortID(int storage_array[][2]) {
    //将数组进行复制，以便于存储排序结果的同时不改变原数组
    memcpy(storage_array, students_info, sizeof(int) * students_number * 2);

    //按ID由小到大排序
    qsort(storage_array, students_number, sizeof(int) * 2, idCompare);
}

/**
 * ID由低到高排序输出
 */
void printSortedID() {
    //调用函数进行排序
    int students_id_asc[students_number][2];
    sortID(students_id_asc);

    //对排序后的结果进行输出
    printf("ID Score \n");
    int i;
    for (i = 0; i < students_number; i++)
        printf("%-3d%d \n", students_id_asc[i][0], students_id_asc[i][1]);
}

/**
 * 输入学号，输出排名与成绩
 * @par 输入样例： 1(回车)
 */
void searchID() {
    //调用函数对分数进行降叙排序
    int students_score_desc[students_number][2];
    sortScore(students_score_desc);

    //输入欲查询的ID，若输入错误则清空缓冲区并重新输入
    printf("Please input an ID to search: ");
    int target_id;
    while (scanf("%d", &target_id) != 1) {
        printf("Illegal input, please check and try again.");
        while (getchar() != '\n');
    }

    //线性查找并输出ID对应的成绩与排名
    int i;
    for (i = 0; i < students_number; i++) {
        if (students_score_desc[i][0] != target_id)
            continue;
        printf("ID Score Rank \n");
        printf("%-3d%-6d%d \n", target_id, students_score_desc[i][1], i + 1);
        break;
    }
    //如果未找到对应的ID，则提示未找到
    if (i == students_number)
        printf("ID %d not found. \n", target_id);
}

/**
 * 输出成绩统计
 */
void printAnalysis() {
    //调用函数对分数进行降叙排序
    int students_score_desc[students_number][2];
    sortScore(students_score_desc);

    //使用排序过的成绩进行统计
    int i, grade = 0;//默认成绩段为0(>=90)
    int grades_floor[] = {90, 80, 70, 60, 0};//成绩分段下限
    int grades_count[] = {0, 0, 0, 0, 0};//每个成绩段的人数
    for (i = 0; i < students_number; i++) {
        //如果选定的成绩段的最低分比当前的成绩高，则找到新的适用于当前成绩的成绩段
        if (students_score_desc[i][1] < grades_floor[grade])
            while (grades_floor[++grade] > students_score_desc[i][1]);//循环，直到找到下限低于当前成绩的成绩段
        //当前成绩所在的成绩段记录数增加
        grades_count[grade]++;
    }

    //输出每个成绩段人数与百分比
    printf("Grade Count Rate \n");
    for (i = 0; i < 5; i++)
        printf("%c     %-6d%3.0lf%% \n", 'A' + i, grades_count[i], (double) grades_count[i] / students_number * 100);
}

/**
 * 输出每一位学生的信息与全体信息
 */
void listRecords() {
    //调用函数，分别输出学生信息与全体信息
    printSortedID();
    printTotalAndAverage();
}

/**
 * 输出帮助菜单提示输入选项
 * @return 用户输入的选项
 * @retval [0,7]
 */
int readChoice() {
    //输出帮助菜单
    printf("----------------- \n");
    printf("Available choice: \n");
    printf("1. Input record \n");
    printf("2. Calculate total and average score of course \n");
    printf("3. Sort in descending order by score \n");
    printf("4. Sort in ascending order by number \n");
    printf("5. Search by number \n");
    printf("6. Statistic analysis \n");
    printf("7. List record \n");
    printf("0. Exit \n");
    printf("Please enter your choice: ");

    //输入直到格式正确为止
    int choice_id;
    while (scanf("%d", &choice_id) != 1) {
        printf("Illegal input, please check and try again.");
        while (getchar() != '\n');
    }
    //如果输入超出范围则重新输出可选项
    if (choice_id < 0 || choice_id > 7) {
        printf("Choice %d not found. \n", choice_id);
        return readChoice();
    }
    return choice_id;
}

/**
 * 执行用户选项
 * @param choice_id 用户提供的选项 [0,7]
 */
void execChoice(int choice_id) {
    //使用switch调用对应的函数
    switch (choice_id) {
        case 1:
            inputRecords();
            break;
        case 2:
            printTotalAndAverage();
            break;
        case 3:
            printSortedScore();
            break;
        case 4:
            printSortedID();
            break;
        case 5:
            searchID();
            break;
        case 6:
            printAnalysis();
            break;
        case 7:
            listRecords();
    }
}

/**
 * 入口函数、主函数
 * @return 程序运行返回值
 * @retval 0 - 程序正常退出
 * */
int main() {
    //一直执行用户输入的选项，直到输入0为止
    int choice_id;
    while (choice_id = readChoice())
        execChoice(choice_id);
    return 0;
}
