#include<iostream>
using namespace std;

class own_string
{
	char *s;
	public:
	own_string()
	{
		s=new char[0];
	}

	own_string(const char* p)
	{
		int i,j;
		for(i=0;p[i];i++)
			s=new char[i+1];
		for(j=0;p[j];j++)
		{
			s[j]=p[j];
		}
		s[j]=p[j];
	}

	own_string(const own_string& temp)
	{
		int i,j;
		for(i=0;temp.s[i];i++);
		s=new char[i+1];
		for(j=0;temp.s[j];j++)
		{
			s[j]=temp.s[j];
		}
		s[j]=temp.s[j];
	}

	~own_string()
	{
		delete s;
	}

	int my_length()
	{
		int i;
		for(i=0;s[i];i++);
		return i;
	}


	void operator=(own_string temp)
	{
		int i,l;
		for(l=0;temp.s[l];l++);
		s=new char[l+1];
		for(i=0;temp.s[i];i++)
			s[i]=temp.s[i];
		s[i]=temp.s[i];
	}

	void get_data()
	{
		cout << s << endl;
	}

	own_string operator+ (const own_string &temp)
	{
		int i,j,k,l;
		own_string result;
		for(k=0;s[k];k++);
		for(l=0;temp.s[l];l++);
		result.s=new char[k+l+1];
		for(i=0;s[i];i++)
		{
			result.s[i]=s[i];
		}
		for(j=0;temp.s[j];j++)
		{
			result.s[i++]=temp.s[j];
		}
		result.s[i++]=temp.s[j];
		return result;
	}

	own_string operator+ (const char temp)
	{
		int i,j,k,l;
		own_string result;
		for(k=0;s[k];k++);
		result.s=new char[k+2];
		for(i=0;s[i];i++)
		{
			result.s[i]=s[i];
		}
			result.s[i++]=temp;
		return result;
	}

	void  operator+= (const own_string &temp)
	{
		int i,j,k,l;
		for(k=0;s[k];k++);
		for(j=0;temp.s[j];j++)
		{
			s[k++]=temp.s[j];
		}
		s[k++]=temp.s[j];
	
	}
	

	int operator< (own_string &temp)
	{
		int i=0;
		for(;temp.s[i];i++)
		{	
			if(this->s[i] < temp.s[i])
			{
				return 1;

			}
			else if(this->s[i] > temp.s[i])
			{
				return 0;

			}
		}
	}

	int operator> (own_string &temp)
	{
		int i=0;
		for(i=0;temp.s[i];i++)
		{
			if(this->s[i] > temp.s[i])
			{
				return 1;
			}
			else if(this->s[i] < temp.s[i])
			{
				return 0;
			}
		}
	}


	int operator>= (own_string &temp)
	{
		int i=0;
		for(i=0;temp.s[i];i++)
		{
			if(this->s[i]==temp.s[i])	
			{
				continue;
			}		
			else if(this->s[i] > temp.s[i])
			{
				return 1;
			}
			else if(this->s[i] < temp.s[i])
			{
				return 0;
			}
		}
		if(this->s[i]==temp.s[i])	
		{
			return 1;
		}	
	}


	int operator<= (own_string &temp)
	{
		int i=0;
		for(i=0;temp.s[i];i++)
		{
			if(this->s[i]==temp.s[i])	
			{
				continue;
			}		
			else if(this->s[i] > temp.s[i])
			{
				return 1;
			}
			else if(this->s[i] < temp.s[i])
			{
				return 0;
			}
		}
		if(this->s[i]==temp.s[i])	
		{
			return 1;
		}	
	}


	int operator== (own_string &temp)
	{
		int i=0;
		for(i=0;temp.s[i];i++)
		{
			if(this->s[i]!=temp.s[i])	
			{
				break;
			}		
		}
		if(this->s[i]==temp.s[i])	
		{
			return 1;
		}	
		else
		{
			return 0;
		}
	}

	int operator!= (own_string &temp)
	{
		int i=0;
		for(i=0;temp.s[i];i++)
		{
			if(this->s[i]!=temp.s[i])	
			{
				break;
			}		
		}
		if(this->s[i]==temp.s[i])	
		{
			return 0;
		}	
		else
		{
			return 1;
		}
	}


	void operator() (const own_string &temp)
	{
	int i=0;
		for(i=0;temp.s[i];i++)	
		{
			s[i]=temp.s[i];
		}
	}

	void operator() (const char *temp)
	{
	int i=0;
		for(i=0;temp[i];i++)	
		{
			s[i]=temp[i];
		}
	}


	friend own_string strrev(own_string &);
	friend void  strcpy(own_string &,const own_string &);
	friend void  strncpy(own_string &temp,const own_string &temp1,int );
	friend void strcat(own_string &,const own_string &);
	friend void strncat(own_string &,const own_string &,int);
	friend int strcmp(const own_string &,const own_string &);
	friend char* strchr(const own_string &,char );
	friend char* strrchr(const own_string &,char );
	friend char* strstr(const own_string &, const own_string &);
	friend istream& operator >> (istream&,const own_string &);
	friend ostream& operator << (ostream&,const own_string );
	friend own_string operator+ (const char *,const own_string&);
	friend own_string operator+ (const char,const own_string&);
};

own_string operator+ (const char a,const own_string &temp)
{
	own_string result;
	result.s[0]=a;
	for(int i=0;temp.s[i];i++)
	{
		result.s[i+1]=temp.s[i];
	}
	return result;
}


istream& operator >> (istream& in,const own_string &temp)
{
	in >> temp.s;
	return in;
}

ostream& operator << (ostream& out,const own_string temp)
{
	out << temp.s;
	return out;
}

own_string operator+ (const char *temp,const own_string& temp1)
{
	int i,j,k,l;
	own_string result;
	for(l=0;temp[l];l++);
	for(k=0;temp1.s[k];k++);
	result.s=new char[l+k+1];

	for(i=0;temp[i];i++)
		result.s[i]=temp[i];

	for(j=0;temp1.s[j];j++,i++)
		result.s[i]=temp1.s[j];

	result.s[i]=temp1.s[j];


	return result;
}


own_string strrev(own_string &temp)
{
	int i,j,l;
	l=temp.my_length();
	own_string result;
	result.s=new char[l+1];
	for(i=0,j=l-1;j>=0;i++,j--)
	{
		result.s[i]=temp.s[j];
	}
	result.s[i]='\0';	
	return result;
}

void  strcpy(own_string &temp,const own_string &temp1)
{
	int i,j,l,k;
	for(l=0;temp.s[l];l++);
	for(k=0;temp1.s[k];k++);
	for(i=0;temp1.s[i];i++)
	{
		temp.s[i]=temp1.s[i];
	}
	temp.s[i]=temp1.s[i];
}


void  strncpy(own_string &temp,const own_string &temp1,int a)
{
	int i,j,l,k;
	for(i=0;a;i++,a--)
	{
		temp.s[i]=temp1.s[i];
	}
	temp.s[i]='\0';
}

void strcat(own_string &temp,const own_string &temp1)
{

	int i,j,k,l;
	own_string result;
	for(l=0;temp.s[l];l++);
	for(k=0;temp1.s[k];k++);
	for(i=k-1,j=0;temp1.s[j];j++,i++)
	{
		temp.s[i]=temp1.s[j];
	}
	temp.s[i]=temp1.s[j];


}

void strncat(own_string &temp,const own_string &temp1,int a)
{

	int i,j,k,l;
	own_string result;
	for(k=0;temp.s[k];k++);
	for(l=0;temp1.s[l];l++);
	for(i=k-1,j=0;a;j++,i++,a--)
	{
		temp.s[i]=temp1.s[j];
	}
	temp.s[i]='\0';


}

int strcmp(const own_string &temp,const own_string &temp1)
{
	int i=0;
	for(i=0;temp.s[i];i++)
	{
		if(temp.s[i]!=temp1.s[i])
			break;
	}
	if(temp.s[i] > temp1.s[i])
	{
		return 1;
	}
	else if(temp.s[i] < temp1.s[i])
	{
		return -1;
	}
	if(temp.s[i] == temp1.s[i])
	{
		return 0;
	}

}

char* strchr(const own_string &temp,char a)
{
	int i=0;
	char *p=NULL;
	for(i=0;temp.s[i];i++)
	{
		if(temp.s[i]==a)
		{
			return &temp.s[i];
		}
	}

	return p;


}	
char* strrchr(const own_string &temp,char a)
{
	int i=0,j;
	char *p=NULL;
	for(i=0;temp.s[i];i++);
	for(j=i-1;j>=0;j--)
	{
		if(temp.s[j]==a)
		{
			return &temp.s[j];
		}
	}

	return p;

}

char* strstr(const own_string &temp, const own_string &temp1)
{
	int i,j,k,l;
	for(l=0;temp1.s[l];l++);
	for(i=0;temp.s[i];i++)
	{
		if(temp.s[i]==temp1.s[0])
		{
			for(j=0,k=i;temp.s[j];j++,k++)
			{
				if(temp.s[k]!=temp1.s[j])
					break;
			}
			if(j==l)
				return &temp.s[i];
		}
	}
}




main()
{
	int i;
	own_string s("dakjdlkpradipsdasd"),s1("pradip"),s2,s3;
	//cout << (s < s1) << endl;
	//strcpy(s,s1);
	//strncpy(s,s1,4);
	//strcat(s,s1);
	//strncat(s,s1,5);
	//cout << strcmp(s,s1) << endl;
	//	char p='z';
	//	cout << strchr(s,p) << endl;
	//	cout << strrchr(s,p) << endl;

	//	s.get_data();

	//cout<< (strstr(s,s1)) << endl;
	/*	cout <<"enter" <<endl;
		cin >> s2;
		cout <<"enter" <<endl;
		cin >> s3;
		cout <<"enter" <<endl;
		cout << s2+s3 <<endl;
	 */
//	s+=s1;
//	cout << s <<endl;
s2="vectorpradip";

cout << s2 << endl;


}



