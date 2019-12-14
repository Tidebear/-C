#include<stdio.h>
char words[100] = {0};					//待判断的表达式 
int index = 1;							//字符下角标 
char ch;								//当前位置的字符  
bool error = false;						//判断表达式是否正确
char *keywords[100] = {0};              //
char chs[100] = {0}; 
int m = 0;
int count = 0;

void mainoperation(int n,int a);
void outputspace(int n,int m);
bool plusandminus();
bool brackets();
bool multiplayanddivice();

bool plusandminus(){					//判断是否为+或者-号 
	bool flag = false;
	multiplayanddivice();				//*号和/号判断
	if(ch == '+'||ch == '-')
		flag = true;
	if(flag){
		index++;
		ch = words[index];
		outputspace(index+1,m);
		plusandminus();
	}
	return flag;
}

bool multiplayanddivice(){			//*号和/号判断 
	bool flag = false;
	brackets();						//字符和()的判断
	if(ch == '*'||ch == '/')
		flag = true;
	if(flag){
		index++;
		ch = words[index];
		outputspace(index+1,m);
		multiplayanddivice();
	}
	return flag;
}

bool brackets(){					//字符和()的判断
	bool flag = false;
	if(ch>='A' && ch<='Z'||ch>='a' && ch<='z'|| ch >='0' && ch<='9')
		flag = true;
	if(flag){						//是否为字符				
		index++;					//index++
		ch = words[index];
		count++;
		outputspace(index+1,m);
		printf("%d\n",count);
		return flag;
	}
	else if(ch == '('){				//是否为'(' 		
		index++;
		ch = words[index];
		outputspace(index+1,m);
		plusandminus();				//判断括号内表达式是否正确
		if(ch == ')') {				//是否有配对() 			
			index++;
			ch = words[index];
			outputspace(index+1,m);
		}
		else{ 
			error = true;
			printf("没有与之匹配的括号！");
		} 
	}
	else
		error = true;
	return flag;
}

void outputspace(int n,int m){//输出空格 
	if(n < m){
		for(int i = 0; i < n-1; i++)
			printf(" "); 
		for(int i = index + 1; i < m; i++)
			printf("%c",words[i]);			
		printf("\n");
	} 
}

void mainoperation(int n,int a){//读取输入字符，如果出错，抛出IO异常 
	index = 1;
	char word;
	int k = 0;
	bool flag = true;
	printf("输入表达式并且以;结束：\n");
	while(word != ';'){
		scanf("%c",&word);
		words[k] = word;
		k++;
	} 
	for(int i =0; i < k; i++){
		printf("%c",words[i]);
	}
	printf("\n");
	m = k;
	while(flag){
		ch = words[index];  
		outputspace(index + 1,m);
		if(ch == ';' || error){
			flag = false;
			break;			
		}		
		plusandminus();//子程序判断表达式是否有错 
	}
	if(error)
		printf("表达式有错!缺少运算符!");
	else
		printf("表达式正确!"); 
}

int main(){	
	int n;
	printf("输入测试的次数：\n");
	scanf("%d",&n);						//n = 1;
	for(int a = 0; a< n; a++){			//a = 0;
		printf("a=%d,n=%d",a,n);
		mainoperation(n,a);//可以不要循环直接，默认编译一次就行，mainoperation(1,0);
	} 
	return 0;
} 

