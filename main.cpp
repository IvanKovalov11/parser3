#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string stroka;
    double x, y, z;
    char op1, op2;
    getline(cin, stroka);
    istringstream stream(stroka);
    stream>>x; stream>>op1;
    while(stream>>y)
    {
        if((op1=='*')||(op1=='/'))
        {
            if(op1=='*')
            {
                x=x*y;
            }
            if(op1=='/')
            {
                if(y!=0)
                {
                    x=x/y;
                }
                else
                {
                    cout<<"ERROR"<<endl;
                    return -1;
                }
            }
            if(!(stream>>op1))
            {
                break;
            }
        }
        else if((op1=='+')||(op1=='-'))
        {
            if(stream>>op2)
            {
                if((op2=='+')||(op2=='-'))
                {
                    if(op1=='+')
                    {
                        x=x+y;
                    }
                    if(op1=='-')
                    {
                        x=x-y;
                    }
                    op1=op2; op2=0;
                }
                if((op2=='*')||(op2=='/'))
                {
                    while((op2=='*')||(op2=='/'))
                    {
                        stream>>z;
                        if(op2=='*')
                        {
                            y=y*z;
                        }
                        if(op2=='/')
                        {
                            if(z!=0)
                            {
                                y=y/z;
                            }
                            else{
                                cout<<"ERROR"<<endl;
                                return -1;
                            }
                        }
                        if(!(stream>>op2))
                        {
                            break;
                        }
                    }
                    if(op1=='+')
                    {
                        x+=y;
                    }
                    if(op1=='-')
                    {
                        x-=y;
                    }
                    op1=op2; op2=0;
                }
            }
            else
            {
                if(op1=='+')
                {
                    x+=y;
                }
                if(op1=='-')
                {
                    x-=y;
                }
            }
        }
    }
    cout<<x<<endl;
    return 0;
}
