#include<stdio.h>
char words[100] = {0};					//���жϵı��ʽ 
int index = 1;							//�ַ��½Ǳ� 
char ch;								//��ǰλ�õ��ַ�  
bool error = false;						//�жϱ��ʽ�Ƿ���ȷ
char *keywords[100] = {0};              //
char chs[100] = {0}; 
int m = 0;
int count = 0;

void mainoperation(int n,int a);
void outputspace(int n,int m);
bool plusandminus();
bool brackets();
bool multiplayanddivice();

bool plusandminus(){					//�ж��Ƿ�Ϊ+����-�� 
	bool flag = false;
	multiplayanddivice();				//*�ź�/���ж�
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

bool multiplayanddivice(){			//*�ź�/���ж� 
	bool flag = false;
	brackets();						//�ַ���()���ж�
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

bool brackets(){					//�ַ���()���ж�
	bool flag = false;
	if(ch>='A' && ch<='Z'||ch>='a' && ch<='z'|| ch >='0' && ch<='9')
		flag = true;
	if(flag){						//�Ƿ�Ϊ�ַ�				
		index++;					//index++
		ch = words[index];
		count++;
		outputspace(index+1,m);
		printf("%d\n",count);
		return flag;
	}
	else if(ch == '('){				//�Ƿ�Ϊ'(' 		
		index++;
		ch = words[index];
		outputspace(index+1,m);
		plusandminus();				//�ж������ڱ��ʽ�Ƿ���ȷ
		if(ch == ')') {				//�Ƿ������() 			
			index++;
			ch = words[index];
			outputspace(index+1,m);
		}
		else{ 
			error = true;
			printf("û����֮ƥ������ţ�");
		} 
	}
	else
		error = true;
	return flag;
}

void outputspace(int n,int m){//����ո� 
	if(n < m){
		for(int i = 0; i < n-1; i++)
			printf(" "); 
		for(int i = index + 1; i < m; i++)
			printf("%c",words[i]);			
		printf("\n");
	} 
}

void mainoperation(int n,int a){//��ȡ�����ַ�����������׳�IO�쳣 
	index = 1;
	char word;
	int k = 0;
	bool flag = true;
	printf("������ʽ������;������\n");
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
		plusandminus();//�ӳ����жϱ��ʽ�Ƿ��д� 
	}
	if(error)
		printf("���ʽ�д�!ȱ�������!");
	else
		printf("���ʽ��ȷ!"); 
}

int main(){	
	int n;
	printf("������ԵĴ�����\n");
	scanf("%d",&n);						//n = 1;
	for(int a = 0; a< n; a++){			//a = 0;
		printf("a=%d,n=%d",a,n);
		mainoperation(n,a);//���Բ�Ҫѭ��ֱ�ӣ�Ĭ�ϱ���һ�ξ��У�mainoperation(1,0);
	} 
	return 0;
} 

