/**
 * @file
 * 此程序中使用了 Doxygen 风格的文档标记为全局变量与函数进行说明
 * @see https://zh.wikipedia.org/wiki/Doxygen
 * @see http://www.stack.nl/~dimitri/doxygen/
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 定义课程数目，若需增加课程数目，仅需修改这一宏定义
 * */
#define COURSE_NUMBER 2

/**
 * 用于存储学生数量
 * @note 初始学生数量为0，随着信息录入而增加
 */
unsigned int students_number = 0;

/**
 * 用于存储学生信息的结构体
 */
typedef struct {
    /**
     * 学号
     */
    long long id;
    /**
     * 姓名
     * @note 输入时不能包含空格，长度上限为50
     */
    char name[51];
    /**
     *  每门课程分数
     *  @note 若需增加课程数目，仅需修改宏定义
     */
    int score[COURSE_NUMBER];


    int total_score;
} StudentInfo;

/**
 * 用于存储学生信息
 * @note 最大为500学生
 * @par students_info[0] 为第1个学生的信息
 */
StudentInfo students_info[500];

/**
 * 根据课程数量自动生成分数的格式提示
 */
void getScoreText(char score_text[]){
    char str_temp[15];
    score_text[0] = 0;
    int course_id;
    for (course_id = 1; course_id <= COURSE_NUMBER; course_id++) {
        sprintf(str_temp, " Score%d", course_id);
        strcat(score_text, str_temp);
    }
}

/**
 * 输入所有学号和成绩
 * 样例输入： 1 60(换行)2 50(换行)0 0(换行)
 * */
void inputRecords() {
    //根据课程数量自动生成分数的输入格式提示
    char score_text[500];
    getScoreText(score_text);

    //输出控制台输入格式提示
    printf("Please input records: \n");
    printf("(Format in each line is 'ID Name%s' and ends with '0 0'.) \n", score_text);
    printf("(NOTE: Name can't contain space and must be shorter than 100 characters.) \n");
    printf("ID Name%s \n", score_text);

    //进行控制台输入读取
    int scanf_retval, student_id, student_score, student_total_score, course_id;
    char student_name[20];
    //输入格式错误 或者 输入 '0 0' 或者 人数达到500 ，则停止输入
    while ((scanf_retval = scanf("%d%s", &student_id, student_name)) == 2 &&
           student_id != 0 &&
           students_number < 500) {
        //将学号、姓名存入全局变量
        students_info[students_number].id = student_id;
        strcpy(students_info[students_number].name, student_name);

        //输入每个科目的成绩并统计总分
        student_total_score = 0;
        for (course_id = 0; course_id < COURSE_NUMBER; course_id++) {
            scanf("%d", &student_score);
            students_info[students_number].score[course_id] = student_score;
            student_total_score += student_score;
        }
        students_info[students_number].total_score = student_total_score;

        students_number++;
    }

    //如果是输入格式错误造成的停止输入，则清空缓冲区，为下一次输入做准备
    if (scanf_retval != 2)
        while (getchar() != '\n');

    //输出已经成功记录的学生数量
    printf("%d %s been recorded. \n", students_number,
           students_number > 1 ? "students have" : "student has");

}

/**
 * 计算并输出平均分
 */
void printAverage() {
    int course_id, i;
    int total, total_total = 0;//记录单科与全科分数总和

    //统计单科与全科的分数总和
    for (course_id = 0; course_id < COURSE_NUMBER; course_id++) {
        total = 0;
        for (i = 0; i < students_number; i++)
            total += students_info[i].score[course_id];//分数累加
        total_total += total;//全科分数是由单科分数累加所得

        //输出单科平均分
        printf("Score%d Average = %.1lf \n", course_id + 1, (double) total / students_number);
    }

    //输出全科平均分
    printf("Total  Average = %.1lf \n", (double) total_total / students_number);
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
    return ((StudentInfo *) student_info)->total_score - ((StudentInfo *) student_info0)->total_score;
}

/**
 * 成绩由高到低进行排序
 */
void sortScore(StudentInfo storage_array[]) {
    //将数组进行复制，以便于存储排序结果的同时不改变原数组
    //memcpy(Memory Copy)是c自带的数组内容复制函数，相关文档参见 http://www.cplusplus.com/reference/cstring/memcpy/
    //void * memcpy ( void * destination, const void * source, size_t num );
    memcpy(storage_array, students_info, sizeof(StudentInfo) * students_number);

    //按成绩由大到小排序，比较函数在上方已经定义
    //qsort(Quick Sort)是c自带的快速排序函数，相关文档参见 http://www.cplusplus.com/reference/cstdlib/qsort/
    //void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
    qsort(storage_array, students_number, sizeof(StudentInfo), scoreCompare);
}

/**
 * 输出学生信息
 * */
void printStudentInfo(int rank, StudentInfo student) {
    printf("%-4d %-2lld %-4s", rank, student.id, student.name, student.total_score);
    int course_id;
    for (course_id = 0; course_id < COURSE_NUMBER; course_id++)
        printf(" %-6d", student.score[course_id]);
    printf(" %d \n", student.total_score);
}

/**
 * 输出最高分与最低分
 */
void printSortedScore() {
    //调用函数进行排序
    StudentInfo students_score_desc[students_number];
    sortScore(students_score_desc);

    //根据课程数量自动生成分数的格式提示
    char score_text[500];
    getScoreText(score_text);

    //对排序后的结果取首项末项进行输出
    printf("Rank ID Name%s TotalScore \n",score_text);
    printStudentInfo(1, students_score_desc[0]);
    printStudentInfo(students_number, students_score_desc[students_number - 1]);
}

/**
 * 输出成绩统计
 */
void printAnalysis() {
    //调用函数，分别输出最高分、最低分与平均分
    printSortedScore();
    printAverage();
}

/**
 * 输出帮助菜单提示输入选项
 * @retval [0,2]
 */
int readChoice() {
    //输出帮助菜单
    printf("----------------- \n");
    printf("Available choice: \n");
    printf("1. Input record \n");
    printf("2. Statistic analysis \n");
    printf("0. Exit \n");
    printf("Please enter your choice: ");

    //输入直到格式正确为止
    int choice_id;
    while (scanf("%d", &choice_id) != 1) {
        printf("Illegal input, please check and try again.");
        while (getchar() != '\n');
    }
    //如果输入超出范围则重新输出可选项
    if (choice_id < 0 || choice_id > 2) {
        printf("Choice %d not found. \n", choice_id);
        return readChoice();
    }
    return choice_id;
}

/**
 * 存储功能入口函数
 * */
void (*functions[])(void)={
        inputRecords,
        printAnalysis
};

/**
 * 执行用户选项
 * @param choice_id 用户提供的选项 [0,7]
 */
void execChoice(int choice_id) {
    functions[choice_id - 1]();
    return;
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
