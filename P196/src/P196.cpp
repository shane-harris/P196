/*****************************************************
Shane Harris
CISP 400 - Mon Wed 3:00 pm
Project 1
Feb 01, 2016
*****************************************************/


#include <iostream>
#include <climits>
using namespace std;


unsigned num_digits( unsigned long l);

int nth_digit(unsigned long l, unsigned n);

unsigned long rev_digits(unsigned long l);

bool is_palindrome(unsigned long l);

bool P196(unsigned long l);


int main ()

{
    unsigned long int l; //max is 4294967295
    unsigned int n;

    cout<< "This is the biggest number that can be passed "<<ULONG_MAX<<endl;
	cout << "Please enter a number that is < ULONG_MAX"<<endl;

	cin >> l;

	cout << "The number is "<<num_digits(l)<<" digits long"<<endl;
    cout << "Enter a number between 0 and "<<num_digits(l)-1<<endl;

    cin >>n;

	cout <<"The number in the "<<n<<" position of "<<l<<" is "<<nth_digit(l,n)<<"."<<endl;

	cout << "The reverse of the number entered is "<<rev_digits(l)<<endl;
    if (is_palindrome(l)== true)
    {
        cout <<l<<" is a palindrome."<<endl;
    }
    else
    {
        cout <<l<<" is not a palindrome."<<endl;
    }

    if(P196(l)== true)
    {
        cout <<l<<" is a P196 number."<<endl;
    }
    else
    {
        cout <<l<<" is not a P196 number."<<endl;
    }

  return 0;

}

unsigned num_digits( unsigned long l)
{
    if (l < ULONG_MAX-1)
    {
        unsigned short int n=0;
        unsigned long int x=4;

        do
            {
            x=x*10;
            n=n+1;
            }
        while( l>=x);

    return n;
    }

}

int nth_digit(unsigned long l, unsigned n)
{
    if(l >= ULONG_MAX-1)
    {
        return -1;
    }
	if(n==0)
	{
		l = l%10;
		return l;
	}
	else
	{
	if(n > (num_digits(l)-1))
		return -1;
	else
		do
		{
			l = l/10;
			n = n-1;
		}
		while(n>=1);
	l = l%10;
	return l;
	}
}

unsigned long rev_digits(unsigned long l)
{
    unsigned long L=0;
    unsigned x;
    unsigned y=0;
    if(num_digits(l)==10 && nth_digit(l,0)>=4 && nth_digit(l,1)>=2)
    {
        return 1;
    }
    x = num_digits(l);
    if(x == 1)
    {
        return l;
    }
    else
    {
        do
        {
            if(num_digits(l)==10 && nth_digit(l,0)>=4 && nth_digit(l,1)>=2)
            {
                return false;
            }
            L= L*10;
            L= L + nth_digit(l,y);
            y=y+1;
        }
        while(y!=x);
    }
return L;
}

bool is_palindrome(unsigned long l)
{
    unsigned long L;
    if (l >= (ULONG_MAX-l))
    {
        return false;
    }
	L = rev_digits(l);
	if(L==l)
		return true;
	else
		return false;
}


bool P196(unsigned long l)
{
    unsigned long x;
    x=l;
    do
    {
        if(is_palindrome(l) == true)
        {
        return true;
        }
        else
        {
            if(num_digits(l)==10 && nth_digit(l,0)>=4 && nth_digit(l,1)>=2)
            {
                return -1;
            }
            else
            {
                l=l + rev_digits(l);
                if(is_palindrome(l)== true)
                {
                    return l;
                }
            }

        }

    }
    while(l < ULONG_MAX/3);
}

