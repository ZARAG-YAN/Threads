/**
 * @file matrix.hpp
 * @brief Contains prototype for data class, multipliel and adder class
 */
#ifndef DATA_H
#define DATA_H
//#include <pthread.h>
#include "thread.hpp"

///////////// Data //////////////
class data
{
public:
        data();
        ~data();
        // constructor() clear and not ready
        void print();
        void initialize();

private:
        int m_matrix[m_size][m_size];
        int m_size;
        mutex m_mutex;
        bool m_ready;
        void set_size();
        void set_ready(bool);
};

////////////// Adder //////////////

/**
 * @class adder
 * @brief is inharitanced thread class and added two matrixs.
 * */
class adder : public th::thread
{
private:
	data* in1;
	data* in2;
	data* out;
public:

	/**
	*@fn adder       
	*@brief  two matrics addition.
	@param i //todo
	@brief first index
	@param j //todo
	@brief second index
	*/
	adder(data*, data*, data*);

	/**
	* @fn run
	* @brief virtual function's overloading.
	* */
        virtual void run()
	{
		if (! in1->is_ready()) {
			in1->wait();
		}
		if (! in2->is_ready()) {
			in2->wait();
		}
		out.matrix = in1->matrix + in2->matrix;
		out.set_ready();
	}
};


////////////// Multiplay ///////////////

class multiplier : public th::thread
{
private:
	data* in1;
	data* in2;
	data* out;
public:
	/**
	* @fn multiplier
	* @brief consturcot
	**/
        multiplier(data*, data*, data*);
	
	/**
	* @fn run
	* @brief virtual function's overloading.
	* */
	virtual void run()
	{
		if (! in1->is_ready()) {
			in1->wait();
		}
		if (! in2->is_ready()) {
			in2->wait();
		}
		out.matrix = in1->matrix + in2->matrix;
		out.set_ready();
	}
	
	/**
	*@fn multiplier       
	*@brief  two matrics multiplier.
	@param i //todo
	@brief first index
	@param j //todo
	@brief second index
	*/
};

#endif
