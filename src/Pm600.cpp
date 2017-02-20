/*----- PROTECTED REGION ID(Pm600.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        Pm600.cpp
//
// description : C++ source for the Pm600 class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               Pm600 are implemented in this file.
//
// project :     Pm600 McLennan
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <Pm600.h>
#include <Pm600Class.h>

/*----- PROTECTED REGION END -----*/	//	Pm600.cpp

/**
 *  Pm600 class description:
 *    
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//================================================================
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  Stop          |  stop
//  SetPosition   |  set_position
//  Forward       |  forward
//  Backward      |  backward
//  Reset         |  reset
//  GoHome        |  go_home
//================================================================

//================================================================
//  Attributes managed are:
//================================================================
//  Position      |  Tango::DevDouble	Scalar
//  Velocity      |  Tango::DevDouble	Scalar
//  Acceleration  |  Tango::DevDouble	Scalar
//  Deceleration  |  Tango::DevDouble	Scalar
//================================================================

namespace Pm600_ns
{
/*----- PROTECTED REGION ID(Pm600::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/	//	Pm600::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : Pm600::Pm600()
 *	Description : Constructors for a Tango device
 *                implementing the classPm600
 */
//--------------------------------------------------------
Pm600::Pm600(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(Pm600::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::constructor_1
}
//--------------------------------------------------------
Pm600::Pm600(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
	/*----- PROTECTED REGION ID(Pm600::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::constructor_2
}
//--------------------------------------------------------
Pm600::Pm600(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
	/*----- PROTECTED REGION ID(Pm600::constructor_3) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : Pm600::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void Pm600::delete_device()
{
	DEBUG_STREAM << "Pm600::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::delete_device) ENABLED START -----*/
	
	//	Delete device allocated objects
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::delete_device
	delete[] attr_Position_read;
	delete[] attr_Velocity_read;
	delete[] attr_Acceleration_read;
	delete[] attr_Deceleration_read;
}

//--------------------------------------------------------
/**
 *	Method      : Pm600::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void Pm600::init_device()
{
	DEBUG_STREAM << "Pm600::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::init_device_before) ENABLED START -----*/
	
	//	Initialization before get_device_property() call
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::init_device_before
	

	//	Get the device properties from database
	get_device_property();
	
	attr_Position_read = new Tango::DevDouble[1];
	attr_Velocity_read = new Tango::DevDouble[1];
	attr_Acceleration_read = new Tango::DevDouble[1];
	attr_Deceleration_read = new Tango::DevDouble[1];
	/*----- PROTECTED REGION ID(Pm600::init_device) ENABLED START -----*/
	
	//	Initialize device
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::init_device
}

//--------------------------------------------------------
/**
 *	Method      : Pm600::get_device_property()
 *	Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void Pm600::get_device_property()
{
	/*----- PROTECTED REGION ID(Pm600::get_device_property_before) ENABLED START -----*/
	
	//	Initialize property data members
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::get_device_property_before


	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("DeviceName"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on Pm600Class to get class property
		Tango::DbDatum	def_prop, cl_prop;
		Pm600Class	*ds_class =
			(static_cast<Pm600Class *>(get_device_class()));
		int	i = -1;

		//	Try to initialize DeviceName from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  deviceName;
		else {
			//	Try to initialize DeviceName from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  deviceName;
		}
		//	And try to extract DeviceName value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  deviceName;

	}

	/*----- PROTECTED REGION ID(Pm600::get_device_property_after) ENABLED START -----*/
	
	//	Check device property data members init
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::get_device_property_after
}

//--------------------------------------------------------
/**
 *	Method      : Pm600::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void Pm600::always_executed_hook()
{
	DEBUG_STREAM << "Pm600::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : Pm600::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void Pm600::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "Pm600::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(Pm600::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::read_attr_hardware
}
//--------------------------------------------------------
/**
 *	Method      : Pm600::write_attr_hardware()
 *	Description : Hardware writing for attributes
 */
//--------------------------------------------------------
void Pm600::write_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "Pm600::write_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(Pm600::write_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::write_attr_hardware
}

//--------------------------------------------------------
/**
 *	Read attribute Position related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void Pm600::read_Position(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Pm600::read_Position(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(Pm600::read_Position) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_Position_read);
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::read_Position
}
//--------------------------------------------------------
/**
 *	Write attribute Position related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void Pm600::write_Position(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "Pm600::write_Position(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(Pm600::write_Position) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::write_Position
}
//--------------------------------------------------------
/**
 *	Read attribute Velocity related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void Pm600::read_Velocity(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Pm600::read_Velocity(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(Pm600::read_Velocity) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_Velocity_read);
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::read_Velocity
}
//--------------------------------------------------------
/**
 *	Write attribute Velocity related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void Pm600::write_Velocity(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "Pm600::write_Velocity(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(Pm600::write_Velocity) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::write_Velocity
}
//--------------------------------------------------------
/**
 *	Read attribute Acceleration related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void Pm600::read_Acceleration(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Pm600::read_Acceleration(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(Pm600::read_Acceleration) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_Acceleration_read);
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::read_Acceleration
}
//--------------------------------------------------------
/**
 *	Write attribute Acceleration related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void Pm600::write_Acceleration(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "Pm600::write_Acceleration(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(Pm600::write_Acceleration) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::write_Acceleration
}
//--------------------------------------------------------
/**
 *	Read attribute Deceleration related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void Pm600::read_Deceleration(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Pm600::read_Deceleration(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(Pm600::read_Deceleration) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_Deceleration_read);
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::read_Deceleration
}
//--------------------------------------------------------
/**
 *	Write attribute Deceleration related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void Pm600::write_Deceleration(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "Pm600::write_Deceleration(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(Pm600::write_Deceleration) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::write_Deceleration
}

//--------------------------------------------------------
/**
 *	Method      : Pm600::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void Pm600::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(Pm600::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command Stop related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void Pm600::stop()
{
	DEBUG_STREAM << "Pm600::Stop()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::stop) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::stop
}
//--------------------------------------------------------
/**
 *	Command SetPosition related method
 *	Description: Set actual position
 *
 *	@param argin Actual position
 */
//--------------------------------------------------------
void Pm600::set_position(Tango::DevDouble argin)
{
	DEBUG_STREAM << "Pm600::SetPosition()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::set_position) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::set_position
}
//--------------------------------------------------------
/**
 *	Command Forward related method
 *	Description: Move forward
 *
 *	@param argin 
 */
//--------------------------------------------------------
void Pm600::forward(Tango::DevDouble argin)
{
	DEBUG_STREAM << "Pm600::Forward()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::forward) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::forward
}
//--------------------------------------------------------
/**
 *	Command Backward related method
 *	Description: Move backward
 *
 *	@param argin 
 */
//--------------------------------------------------------
void Pm600::backward(Tango::DevDouble argin)
{
	DEBUG_STREAM << "Pm600::Backward()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::backward) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::backward
}
//--------------------------------------------------------
/**
 *	Command Reset related method
 *	Description: This command will reset the tracking abort, stall abort, timeout abort or user (command) abort conditions and re-enable the servo control loop.
 *               It will also set the Command position to be equal to the Actual position.
 *
 */
//--------------------------------------------------------
void Pm600::reset()
{
	DEBUG_STREAM << "Pm600::Reset()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::reset) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::reset
}
//--------------------------------------------------------
/**
 *	Command GoHome related method
 *	Description: Homing
 *
 */
//--------------------------------------------------------
void Pm600::go_home()
{
	DEBUG_STREAM << "Pm600::GoHome()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Pm600::go_home) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::go_home
}
//--------------------------------------------------------
/**
 *	Method      : Pm600::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void Pm600::add_dynamic_commands()
{
	/*----- PROTECTED REGION ID(Pm600::add_dynamic_commands) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic commands if any
	
	/*----- PROTECTED REGION END -----*/	//	Pm600::add_dynamic_commands
}

/*----- PROTECTED REGION ID(Pm600::namespace_ending) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	Pm600::namespace_ending
} //	namespace
