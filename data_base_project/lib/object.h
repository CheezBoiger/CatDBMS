/*
   Object Abstraction class. 
 */
#ifndef _OBJECT_H_
#define _OBJECT_H_
#pragma once

#include <lib/security/user.h>
#include <lib/compression/serialize.h>

#ifndef __INTERPRET_BOOL
 #define __INTERPRET_BOOL
 #define _interpret_bool(a) ( (a == 1) ? "true" : "false" )
#endif /* __INTERPRET_BOOL */

namespace catdb {

/**
 * file_information_buffer used to store basic information about the object.
 */
struct file_information_buffer {
   std::string filename;
   std::string owner;

   int32_t id;
   int32_t security_id;
};

/**
 * object_type enum used to specify the type that this object is.
 */   
enum object_type {
   O_TYPE_OBJECT,
   O_TYPE_ELEMENT,
   O_TYPE_MODULE,
   O_TYPE_COLUMN,
};

/**
 * Object class. Abstract class since it shows the similarities of
 * all files in the data base.
 */
class Object : public serialization::Serialize {
private:
   /**
    * The identification number associated.
    */
   int32_t id;
   /**
    * The security identification number associated. This is used to determine the authenticity of
    * this object.
    */
   int32_t security_id;

protected:
   /**
    * The security level of this object. Specified Security level determines whether the user has
    * permission to use, or view, this object. If the User has equal, or greater, rights, he/she may
    * be granted permission to control this object.
    */
   security::security_levels sec_level;
   /**
    * Type of object, it could be an Element, Container, Column, Database, etc.
    */
   object_type type;
   /**
    * Name of the object.
    */
   std::string objectname;
   /** 
    * Name of the owner, if no owner is specified, this object is "free".
    */
   std::string owner;
   /**   
    * Get the identification number of this object.
    */
   int32_t get_id(void) { return id; }
   /**
    * Get the security identification number of this object.
    */
   int32_t get_security_id(void) { return security_id; }
   /**
    * Update this object if need be.
    */
   virtual void update(void) = 0;
   /** 
    * Check the security of the user before allowing them to access this object.
    */
   virtual bool check_security(User& user) = 0;

public:
   /**
    * Standard virtual destructor for this object.
    */
   virtual ~Object(void) { }
   /** 
    * Ye' ol' copy constructor for this object.
    */
   Object(const Object &obj);
   /**
    * The Copy constructor again, only that it allows the passing of object pointer types.
    */
   Object(const Object* obj);
   /** 
    * Standard Object default constructor.
    */
   Object(void);
   /**
    * Most of the constructing will be using this overloaded constructor.
    */
   Object(std::string objname
        , std::string objowner
        , int32_t id
        , int32_t sec_id
        , security_levels level
        , object_type type);
   /** 
    * Get the object name of this object. should be called something else...
    */
   std::string get_filename(void) { return objectname; }
   /**
    * Get the owner name, the name that owns this object.
    */
   std::string get_owner_name(void) { return owner; }
   /**
    * Get the type that this object is.
    */ 
   object_type get_object_type(void) { return type; }

   bool operator==(const Object &obj1) const;
   bool operator<=(const Object &obj1) const;
   bool operator>=(const Object &obj1) const;
   bool operator<(const Object &obj1) const;
   bool operator>(const Object &obj1) const;
   bool operator!=(const Object &obj1) const;
   /**
    * Serialize this object.
    */
   virtual void serialize(serialization::ObjectStream& stream);
   /**
    * Deserialize this object into this.
    */
   virtual void deserialize(serialization::ObjectStream& stream);

   operator uint32_t(void);
};
} /* catdb namespace */
#endif /* _OBJECT_H_ */
