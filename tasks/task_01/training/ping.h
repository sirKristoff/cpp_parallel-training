/*
 * ping.h
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#ifndef PING_H_
#define PING_H_

class Ping
{
	 int count_;
public:
	Ping( int count );
	Ping( const Ping& ) = delete;
	Ping& operator=( const Ping& ) = delete;
	virtual ~Ping();
};

#endif /* PING_H_ */
