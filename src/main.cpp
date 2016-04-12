#define ANTIPODE32MR

#include "ASystemConfig.h"
#include "ACore.h"

#include <cstdlib>

using namespace AFramework;

class Base{
  
	public:
		Base(){
			m_a = 0;
		}
		
		Base(int a){
			m_a = a;
			if(m_alloc){
				a++;
			}
		}
		
		~Base(){
		
		}
		
		void	setA(int a){
			m_a = a;
		}
		
		int		a() const{
			return m_a;
		}
		
		void	*	operator new(size_t size){
			void * obj = System::malloc(size);
			if(obj){
				Base * m_this = reinterpret_cast<Base *>(obj);
				m_this->m_alloc = true;
			}
			return obj;
		}
		
		void	*	operator new[](size_t size){
			return System::malloc(size);
		}
		
		void		operator delete(void * ptr){
			System::free(&ptr);
		}
		
		void		operator delete[](void * ptr){
			System::free(&ptr);
		}
		
	private:
		int		m_a;
		bool	m_alloc;
};

class Derived : public Base{

	public:
		Derived() : Derived(0, 0){
		
		}
		
		Derived(int a, int b) : Base(a){
			setB(b);
		}
		
		~Derived(){
		
		}
		
		void setB(int b){
			m_b = b;
		}
		
		int b() const{
			return m_b;
		}
	private:
		int m_b;
};

int main(){
	
	TRISA	= 0x0793;	//0000 0111 1001 0011
	ANSELA	= 0x0000;
	LATA	= 0x0000;
	ODCA	= 0x0000;
	
	TRISB	= 0xEFAF;	//1110 1111 1010 1111
	ANSELB	= 0x0000;
	LATB	= 0x0000;
	ODCB	= 0x0000;
	
	TRISC	= 0x01FE;	//0000 0001 1111 1110
	ANSELC	= 0x0000;
	LATC	= 0x0000;
	ODCC	= 0x0000;
	
	LATCbits.LATC0 = 1;

	System::init(16392);
		
	Derived * d = new Derived();
	
	delete d;

	while(1){
		
	}
	return 0;
}