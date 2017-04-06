//
// file :         readthread.cpp
//
// description :  reading thread
//
// project :      TANGO Device Server
//
// $Author: graziano $ 
//
// $Revision: 1.5 $
//
// $Log: readthread.cpp,v $
// Revision 1.5  2017-01-16 08:53:26  graziano
// fixed log
//
// Revision 1.4  2016-12-15 17:01:44  graziano
// fixed step parsing
//
// Revision 1.3  2016-12-15 16:20:17  graziano
// added step positive and negative
//
// Revision 1.2  2016-12-14 11:21:57  graziano
// added step movements
//
// Revision 1.1  2016-12-12 10:43:59  graziano
// first commit
//
//
//
//
//
// copyleft :   Sincrotrone Trieste S.C.p.A.
//              Strada Statale 14 - km 163,5 in AREA Science Park
//              34012 Basovizza, Trieste ITALY
//

#include "readthread.h"
#include "Pm600.h"
#include <math.h>

static const char __FILE__rev[] = __FILE__ " $Revision: 1.5 $";

namespace Pm600_ns
{

//+------------------------------------------------------------------
//
//	method:			readthread::readthread()
//
//	description:	readthread constructor
//
//-------------------------------------------------------------------
readthread::readthread(Tango::DeviceImpl* devImpl):Tango::LogAdapter(devImpl)
{ 
	DEBUG_STREAM << "readthread::readthread(): constructor... :" << __FILE__rev << endl;
	device = devImpl;
}

//+------------------------------------------------------------------
//
//	method:			readthread::~readthread()
//
//	description:	readthread destructor
//
//-------------------------------------------------------------------
readthread::~readthread()
{
	DEBUG_STREAM << "readthread::~readthread(): destructor... !" << endl;
}

//+------------------------------------------------------------------
//
//	method:			readthread::run()
//
//	description:	Run
//
//-------------------------------------------------------------------
void readthread::run(void *)
{
	INFO_STREAM << "readthread::run(): running... !" << endl;
	/*int pausesec,pausenano,pausesec_dfl,pausenano_dfl,
	    cnt_err = 0,
		max_cnt_err = 3,
		ret;*/
	unsigned long counter =0;
	abortflag = false;
	Pm600 *_device = static_cast<Pm600 *>(device);


	while (!abortflag)
	{
		counter++;
		DEBUG_STREAM << "readthread::run(): looping "<< endl;
		string tstate;
		_device->SendReceive(GET_STATE, tstate);
		if(tstate.length() == 8)
		{
			if(tstate[1] == '1')
			{
				_device->set_state(Tango::FAULT);
				_device->set_status("Error (abort, tracking, stall, timeout etc.)");
			}
			else if(tstate[0] == '0' || tstate[4] == '1')
			{
				_device->set_state(Tango::MOVING);
				if(tstate[4] == '1')
					_device->set_status("Jogging or joystick moving");
				else
					_device->set_status("Controller is busy");
			}
			else
			{
				_device->set_state(Tango::ON);
				if(tstate[2] == '1')
					_device->set_status("Upper hard limit is ON");
				else if(tstate[3] == '1')
					_device->set_status("Lower hard limit is ON");
				else
					_device->set_status("Controller is idle");
			}
		}
		else
		{
			INFO_STREAM << __func__ << ": wrong status response length=" << tstate.length();
		}
		usleep(10000);
		/*string tpos;
		_device->SendReceive(QUERY_POSITIONS, tpos);
		//if(tstate.length() == 8)
		{
			INFO_STREAM << __func__ << ": query positions response length=" << tpos.length() << " -> " << tpos;
		}*/
		double dpos;
		_device->SendReceive(string(GET_COMMAND_POSITION), dpos);
		*(_device->attr_Position_read) = dpos*_device->positionRatio;

		//if(counter%2 == 0)
		{
			usleep(10000);
			string tspeed;
			_device->SendReceive(QUERY_SPEEDS, tspeed);
			char parsespeed[1024];
			int icontroller,isc,isv,isa,isd,ild;
			//int ret = sscanf(tspeed.c_str(),"%d:SC = %d  SV = %d  SA = %d  SD = %d  LD = %d",&icontroller,&isc,&isv,&isa,&isd,&ild);
			char tmp[1024];
			//int ret = sscanf(tspeed.c_str(),"%d:%[^\r]",&icontroller,&isc,tmp);
			int ret = sscanf(tspeed.c_str(),"SC = %d  SV = %d  SA = %d  SD = %d  LD = %d",&isc,&isv,&isa,&isd,&ild);
			if(ret == 5)
			{
				*(_device->attr_CreepSpeed_read) = isc*_device->positionRatio;
				*(_device->attr_Velocity_read) = isv*_device->positionRatio;
				*(_device->attr_Acceleration_read) = isa*_device->positionRatio;
				*(_device->attr_Deceleration_read) = isd*_device->positionRatio;
			}
			else
			{
				INFO_STREAM << __func__ << ": ret="<<ret<<" -> failed parsing of tspeed '" << tspeed << "'";
			}
			//if(tstate.length() == 8)
			{
				INFO_STREAM << __func__ << ": query speeds response length=" << tspeed.length() << " -> " << tspeed;
			}
			/*double dvel;
			_device->SendReceive(string(GET_VELOCITY), dvel);
			*(_device->attr_Velocity_read) = dvel*_device->positionRatio;*/
		}

		abort_sleep(1);
	}
	INFO_STREAM << "readthread::run(): exit!!!" << endl;
}

//+------------------------------------------------------------------
//
//	method:			readthread::abort_sleep
//
//	description:	Resume from sleep if abort_flag set (sec.)
//
//-------------------------------------------------------------------
void readthread::abort_sleep(double time)
{

	for (int i = 0; i < (time/0.3); i++) {
		if (abortflag)
			break;
		omni_thread::sleep(0,300000000);
	}

}


}


