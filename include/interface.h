/**
 *  Interface.h
 *
 *  @copyright 2014 Copernica BV
 *  @author Emiel Bruijntjes <emiel.bruijntjes@copernica.com>
 */

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Class definition
 */
class Interface : private ClassBase
{
public:
    /**
     *  Constructor
     *  @param  name
     */
    Interface(const char *name) : ClassBase(name, ClassType::Interface) {}
    
    /**
     *  Destructor
     */
    virtual ~Interface() {}
    
    /**
     *  Add a - of course abstract - method to the interface
     *  @param  name        Name of the method
     *  @param  arguments   Optional description of the arguments
     */
    void method(const char *name, const Arguments &arguments = {})
    {
        // call base
        ClassBase::method(name, Abstract | Public, arguments);
    }

private:
    /**
     *  Construct a new instance of the object
     *  @return Base
     */
    virtual Base* construct() override
    {
        // this does not occur for interfaces
        return nullptr;
    }

    /**
     *  Construct a clone of the object
     *  @param  orig
     *  @return Base
     */
    virtual Base* clone(Base *orig) override
    {
        // this does not occur for interfaces
        return nullptr;
    }

    /**
     *  Namespaces have access to the private base class
     */
    friend class Namespace;
};

/**
 *  End namespace
 */
}
