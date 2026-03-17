#include<stdio.h>

struct stu{

	int num;

	float TotalScore;

};

void f(struct stu p)

{

	struct stu s[2]={{20044,550},{20045,537}};

	p.num=s[1].num;

	p.TotalScore=s[1].TotalScore;

}

int main()
{

	struct stu s[2]={{20041,703},{20042,580}};

	f(s[0]);

	printf("%d %3.0f\n",s[0].num,s[0].TotalScore);

	return 0;

}
// 结构体指针与结构体，示例如下
struct st{
    int x;
    int *y;
} *pt;
int a = 10;
struct st s1 = {5, &a};  // y 指向 a
pt = &s1;                // pt 指向 s1
printf("%d", pt->x);     // 输出 5
// 其实也没必要打括号，->的优先级比*高,同样的->的优先级也比++高
printf("%d", *(pt->y));  // 输出 10（a的值）

struct stu s2 = {20041, 703.5};
printf("%d %.1f", s2.num, s2.TotalScore);

// (C)
struct
    {  int num;
       float age;
    } std1;
// 匿名结构体，是可以存在的，但无法定义变量，除非在定义时直接声明一个变量，如上所示的std1。匿名结构体不能被复用，因为它没有名字，所以只能在定义时使用一次。
// (D)
struct
    {  int num;
       float age;
    } student;
struct student std1;
// 这种是不合法的，因为匿名结构体没有名字，无法定义变量student。正确的做法是直接在定义时声明变量，如下所示：
// struct
//     {  int num;
//        float age;
//     } std1; // 这样就合法了，可以使用std1来访问num和age成员。