/*
 * Utils.h
 *
 *  Created on: Jan 29, 2015
 *      Author: elohhim
 */

#ifndef UTILS_H_
#define UTILS_H_

template <typename T> int sgn(T val)
{
	return (T(0) < val) - (val < T(0));
}

#endif /* UTILS_H_ */
