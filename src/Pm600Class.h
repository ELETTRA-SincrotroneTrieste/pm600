/*----- PROTECTED REGION ID(Pm600Class.h) ENABLED START -----*/
//=============================================================================
//
// file :        Pm600Class.h
//
// description : Include for the Pm600 root class.
//               This class is the singleton class for
//                the Pm600 device class.
//               It contains all properties and methods which the 
//               Pm600 requires only once e.g. the commands.
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


#ifndef Pm600Class_H
#define Pm600Class_H

#include <tango.h>
#include <Pm600.h>


/*----- PROTECTED REGION END -----*/	//	Pm600Class.h


namespace Pm600_ns
{
/*----- PROTECTED REGION ID(Pm600Class::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	Pm600Class::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute Position class definition
class PositionAttrib: public Tango::Attr
{
public:
	PositionAttrib():Attr("Position",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~PositionAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Pm600 *>(dev))->read_Position(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<Pm600 *>(dev))->write_Position(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Pm600 *>(dev))->is_Position_allowed(ty);}
};

//	Attribute Velocity class definition
class VelocityAttrib: public Tango::Attr
{
public:
	VelocityAttrib():Attr("Velocity",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~VelocityAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Pm600 *>(dev))->read_Velocity(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<Pm600 *>(dev))->write_Velocity(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Pm600 *>(dev))->is_Velocity_allowed(ty);}
};

//	Attribute Acceleration class definition
class AccelerationAttrib: public Tango::Attr
{
public:
	AccelerationAttrib():Attr("Acceleration",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~AccelerationAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Pm600 *>(dev))->read_Acceleration(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<Pm600 *>(dev))->write_Acceleration(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Pm600 *>(dev))->is_Acceleration_allowed(ty);}
};

//	Attribute Deceleration class definition
class DecelerationAttrib: public Tango::Attr
{
public:
	DecelerationAttrib():Attr("Deceleration",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~DecelerationAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Pm600 *>(dev))->read_Deceleration(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<Pm600 *>(dev))->write_Deceleration(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Pm600 *>(dev))->is_Deceleration_allowed(ty);}
};

//	Attribute CreepSpeed class definition
class CreepSpeedAttrib: public Tango::Attr
{
public:
	CreepSpeedAttrib():Attr("CreepSpeed",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~CreepSpeedAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Pm600 *>(dev))->read_CreepSpeed(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<Pm600 *>(dev))->write_CreepSpeed(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Pm600 *>(dev))->is_CreepSpeed_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command Stop class definition
class StopClass : public Tango::Command
{
public:
	StopClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StopClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StopClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Pm600 *>(dev))->is_Stop_allowed(any);}
};

//	Command SetPosition class definition
class SetPositionClass : public Tango::Command
{
public:
	SetPositionClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetPositionClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetPositionClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Pm600 *>(dev))->is_SetPosition_allowed(any);}
};

//	Command Forward class definition
class ForwardClass : public Tango::Command
{
public:
	ForwardClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ForwardClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ForwardClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Pm600 *>(dev))->is_Forward_allowed(any);}
};

//	Command Backward class definition
class BackwardClass : public Tango::Command
{
public:
	BackwardClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	BackwardClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~BackwardClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Pm600 *>(dev))->is_Backward_allowed(any);}
};

//	Command Reset class definition
class ResetClass : public Tango::Command
{
public:
	ResetClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ResetClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ResetClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Pm600 *>(dev))->is_Reset_allowed(any);}
};

//	Command GoHome class definition
class GoHomeClass : public Tango::Command
{
public:
	GoHomeClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GoHomeClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GoHomeClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Pm600 *>(dev))->is_GoHome_allowed(any);}
};


/**
 *	The Pm600Class singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  Pm600Class : public Tango::DeviceClass
#else
class Pm600Class : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(Pm600Class::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static Pm600Class *init(const char *);
		static Pm600Class *instance();
		~Pm600Class();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		Pm600Class(string &);
		static Pm600Class *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	Pm600_H
