#include "matrix.hpp"
#include <iostream>
#include <cassert>

data::data()
{
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                m_matrix[i][j] = 0;
            }
        }
        m_ready = false;
}

void data::set_size(int s)
{
        m_size = s;
}

void data::set_ready(bool b)
{
	m_ready = b;
}

void data::initialize()
{
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                if (j == i) {
		    m_matrix[i][j] = 1;
		}
            }
        }
        m_ready = true;
}

void data::print()
{
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
		    std::cout << m_matrix[i][j] = 1;
		}
		std::cout << std::endl;
            }
        }
}

////////////// adder ////////////////

adder::adder(data a, data b, data c)
	:in1(a)
	,in2(b)
	,out(c)
{
    for (int i = 0; i < m_size; ++i) {
	for (int j = 0; j < m_size; ++j) {
	    out[i][j] = in1[i][j] + in2[i][j];
        }
    }
}


////////////// multiplier ///////////////

multiplier::multiplier(data a, data b, data c)
	:in1(a)
	,in2(b)
	,out(c)
{
    for (int i = 0; i < m_size; ++i) {
	for (int j = 0; j < m_size; ++j) {
	    for (int k = 0; k < m_size; ++j) {
		out[i][j] = in1[i][k] + in2[k][j];
	    }
        }
    }
}

