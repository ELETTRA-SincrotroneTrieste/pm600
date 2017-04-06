//
// file :         readthread.h
//
// description :  reading thread
//
// project :      TANGO Device Server
//
// $Author: graziano $ 
//
// $Revision: 1.1 $
//
// $Log: readthread.h,v $
// Revision 1.1  2016-12-12 10:43:59  graziano
// first commit
//
//
//
//
// copyleft :   Sincrotrone Trieste S.C.p.A.
//              Strada Statale 14 - km 163,5 in AREA Science Park
//              34012 Basovizza, Trieste ITALY
//


#ifndef READTHREAD_H
#define READTHREAD_H

#include <omnithread.h>
#include <tango.h>
#include <inttypes.h>

namespace Pm600_ns
{

class readthread : public omni_thread, public Tango::LogAdapter
{	
	private:
		Tango::DeviceImpl* device;
		void abort_sleep(double time); 

				
	public:
		
		readthread(Tango::DeviceImpl* devImpl);
		~readthread();

		bool abortflag;
					
	protected:
		void run(void *);
		
};	/* end class readthread() */

}

#endif

/* EOF */
