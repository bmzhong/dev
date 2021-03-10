
//(1) a function taking arguments of type pointer to character and refrence to integer and returning no value;
void f1(char *, int &);

//(2) a pointer to such a function;
void (*fp1)(char *, int &);

//(3) a function taking such a pointer as an argument;
typedef void (*FP)(char *, int &);
void f2(FP);

//(4) a function returning such a pointer.
FP f3();

//(5)a function that takes such a pointer as an argument and returns its argument as the return value
FP f4(FP fp)
{
    return fp;
}