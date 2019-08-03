#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

class Complex{
	private:
		double a, b;
		double r, theta;
	public:
		Complex(){
			a = 0;
			b = 0;
			r = 0;
			theta = 0;
		}

		Complex(double arg1, double arg2, bool mode){
			if (mode){
				r = arg1;
				theta = arg2;
			} else {
				a = arg1;
				b = arg2;
			}
		}

};

#endif
