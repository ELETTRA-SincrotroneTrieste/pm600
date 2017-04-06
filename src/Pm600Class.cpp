/*----- PROTECTED REGION ID(Pm600Class.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        Pm600Class.cpp
//
// description : C++ source for the Pm600Class.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the Pm600 once per process.
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


#include <Pm600Class.h>

/*----- PROTECTED REGION END -----*/	//	Pm600Class.cpp

//-------------------------------------------------------------------
/**
 *	Create Pm600Class singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Pm600_class(const char *name) {
		return Pm600_ns::Pm600Class::init(name);
	}
}

namespace Pm600_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
Pm600Class *Pm600Class::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		Pm600Class::Pm600Class(string &s)
 * description : 	constructor for the Pm600Class
 *
 * @param s	The class name
 */
//--------------------------------------------------------
Pm600Class::Pm600Class(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering Pm600Class constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(Pm600Class::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::constructor

	cout2 << "Leaving Pm600Class constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		Pm600Class::~Pm600Class()
 * description : 	destructor for the Pm600Class
 */
//--------------------------------------------------------
Pm600Class::~Pm600Class()
{
	/*----- PROTECTED REGION ID(Pm600Class::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		Pm600Class::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
Pm600Class *Pm600Class::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new Pm600Class(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		Pm600Class::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
Pm600Class *Pm600Class::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		StopClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *StopClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "StopClass::execute(): arrived" << endl;
	((static_cast<Pm600 *>(device))->stop());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		SetPositionClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *SetPositionClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "SetPositionClass::execute(): arrived" << endl;
	Tango::DevDouble argin;
	extract(in_any, argin);
	((static_cast<Pm600 *>(device))->set_position(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		ForwardClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ForwardClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "ForwardClass::execute(): arrived" << endl;
	Tango::DevDouble argin;
	extract(in_any, argin);
	((static_cast<Pm600 *>(device))->forward(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		BackwardClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *BackwardClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "BackwardClass::execute(): arrived" << endl;
	Tango::DevDouble argin;
	extract(in_any, argin);
	((static_cast<Pm600 *>(device))->backward(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		ResetClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ResetClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "ResetClass::execute(): arrived" << endl;
	((static_cast<Pm600 *>(device))->reset());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		GoHomeClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *GoHomeClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "GoHomeClass::execute(): arrived" << endl;
	((static_cast<Pm600 *>(device))->go_home());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : Pm600Class::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum Pm600Class::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : Pm600Class::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum Pm600Class::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : Pm600Class::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum Pm600Class::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : Pm600Class::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void Pm600Class::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "DeviceName";
	prop_desc = "serial device";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "ControllerAddr";
	prop_desc = "";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "PositionRatio";
	prop_desc = "";
	prop_def  = "1";
	vect_data.clear();
	vect_data.push_back("1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : Pm600Class::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void Pm600Class::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("Pm600 McLennan");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("");
	description << str_desc;
	data.push_back(description);

	//	put cvs or svn location
	string	filename("Pm600");
	filename += "Class.cpp";

	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}

	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : Pm600Class::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void Pm600Class::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(Pm600Class::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new Pm600(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Pm600 *dev = static_cast<Pm600 *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(Pm600Class::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : Pm600Class::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void Pm600Class::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(Pm600Class::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::attribute_factory_before
	//	Attribute : Position
	PositionAttrib	*position = new PositionAttrib();
	Tango::UserDefaultAttrProp	position_prop;
	//	description	not set for Position
	//	label	not set for Position
	//	unit	not set for Position
	//	standard_unit	not set for Position
	//	display_unit	not set for Position
	//	format	not set for Position
	//	max_value	not set for Position
	//	min_value	not set for Position
	//	max_alarm	not set for Position
	//	min_alarm	not set for Position
	//	max_warning	not set for Position
	//	min_warning	not set for Position
	//	delta_t	not set for Position
	//	delta_val	not set for Position
	
	position->set_default_properties(position_prop);
	//	Not Polled
	position->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(position);

	//	Attribute : Velocity
	VelocityAttrib	*velocity = new VelocityAttrib();
	Tango::UserDefaultAttrProp	velocity_prop;
	//	description	not set for Velocity
	//	label	not set for Velocity
	//	unit	not set for Velocity
	//	standard_unit	not set for Velocity
	//	display_unit	not set for Velocity
	//	format	not set for Velocity
	//	max_value	not set for Velocity
	//	min_value	not set for Velocity
	//	max_alarm	not set for Velocity
	//	min_alarm	not set for Velocity
	//	max_warning	not set for Velocity
	//	min_warning	not set for Velocity
	//	delta_t	not set for Velocity
	//	delta_val	not set for Velocity
	
	velocity->set_default_properties(velocity_prop);
	//	Not Polled
	velocity->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(velocity);

	//	Attribute : Acceleration
	AccelerationAttrib	*acceleration = new AccelerationAttrib();
	Tango::UserDefaultAttrProp	acceleration_prop;
	//	description	not set for Acceleration
	//	label	not set for Acceleration
	//	unit	not set for Acceleration
	//	standard_unit	not set for Acceleration
	//	display_unit	not set for Acceleration
	//	format	not set for Acceleration
	//	max_value	not set for Acceleration
	//	min_value	not set for Acceleration
	//	max_alarm	not set for Acceleration
	//	min_alarm	not set for Acceleration
	//	max_warning	not set for Acceleration
	//	min_warning	not set for Acceleration
	//	delta_t	not set for Acceleration
	//	delta_val	not set for Acceleration
	
	acceleration->set_default_properties(acceleration_prop);
	//	Not Polled
	acceleration->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(acceleration);

	//	Attribute : Deceleration
	DecelerationAttrib	*deceleration = new DecelerationAttrib();
	Tango::UserDefaultAttrProp	deceleration_prop;
	//	description	not set for Deceleration
	//	label	not set for Deceleration
	//	unit	not set for Deceleration
	//	standard_unit	not set for Deceleration
	//	display_unit	not set for Deceleration
	//	format	not set for Deceleration
	//	max_value	not set for Deceleration
	//	min_value	not set for Deceleration
	//	max_alarm	not set for Deceleration
	//	min_alarm	not set for Deceleration
	//	max_warning	not set for Deceleration
	//	min_warning	not set for Deceleration
	//	delta_t	not set for Deceleration
	//	delta_val	not set for Deceleration
	
	deceleration->set_default_properties(deceleration_prop);
	//	Not Polled
	deceleration->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(deceleration);

	//	Attribute : CreepSpeed
	CreepSpeedAttrib	*creepspeed = new CreepSpeedAttrib();
	Tango::UserDefaultAttrProp	creepspeed_prop;
	creepspeed_prop.set_description("The speed at which moves with a non-zero creep distance will stop");
	//	label	not set for CreepSpeed
	//	unit	not set for CreepSpeed
	//	standard_unit	not set for CreepSpeed
	//	display_unit	not set for CreepSpeed
	//	format	not set for CreepSpeed
	//	max_value	not set for CreepSpeed
	//	min_value	not set for CreepSpeed
	//	max_alarm	not set for CreepSpeed
	//	min_alarm	not set for CreepSpeed
	//	max_warning	not set for CreepSpeed
	//	min_warning	not set for CreepSpeed
	//	delta_t	not set for CreepSpeed
	//	delta_val	not set for CreepSpeed
	
	creepspeed->set_default_properties(creepspeed_prop);
	//	Not Polled
	creepspeed->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(creepspeed);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(Pm600Class::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : Pm600Class::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void Pm600Class::pipe_factory()
{
	/*----- PROTECTED REGION ID(Pm600Class::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::pipe_factory_before
	/*----- PROTECTED REGION ID(Pm600Class::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : Pm600Class::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void Pm600Class::command_factory()
{
	/*----- PROTECTED REGION ID(Pm600Class::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::command_factory_before


	//	Command Stop
	StopClass	*pStopCmd =
		new StopClass("Stop",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pStopCmd);

	//	Command SetPosition
	SetPositionClass	*pSetPositionCmd =
		new SetPositionClass("SetPosition",
			Tango::DEV_DOUBLE, Tango::DEV_VOID,
			"Actual position",
			"",
			Tango::OPERATOR);
	command_list.push_back(pSetPositionCmd);

	//	Command Forward
	ForwardClass	*pForwardCmd =
		new ForwardClass("Forward",
			Tango::DEV_DOUBLE, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pForwardCmd);

	//	Command Backward
	BackwardClass	*pBackwardCmd =
		new BackwardClass("Backward",
			Tango::DEV_DOUBLE, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pBackwardCmd);

	//	Command Reset
	ResetClass	*pResetCmd =
		new ResetClass("Reset",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pResetCmd);

	//	Command GoHome
	GoHomeClass	*pGoHomeCmd =
		new GoHomeClass("GoHome",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pGoHomeCmd);

	/*----- PROTECTED REGION ID(Pm600Class::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		Pm600Class::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void Pm600Class::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(Pm600Class::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		Pm600Class::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void Pm600Class::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		Pm600 *dev = static_cast<Pm600 *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(Pm600Class::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Pm600Class::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : Pm600Class::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *Pm600Class::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(Pm600Class::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	Pm600Class::Additional Methods
} //	namespace
